#include <core/container.h>
#include <string>

namespace idealgas {
using cinder::Path2d;
using glm::vec2;

#define PI 3.14159265

Container::Container(const vec2 &centeroid, double polygon_radius,
                     unsigned shape) : centroid_(centeroid), polygon_radius_(polygon_radius), shape_(shape)
{
  double current_degree = (shape%2 == 0) ? 2 * PI - PI / shape : -PI/2;

  for (unsigned i = 0; i < shape; ++i) {
    vec2 vertex(cos(current_degree) * (polygon_radius_),
                sin(current_degree) * (polygon_radius_));
    vertex += centroid_;
    polygon_vertices_.push_back(vertex);
    current_degree -= 2 * PI / shape ;
  }
  safe_radius = polygon_radius_ * cos(PI/shape);
}

Container::Container(const vec2 &centroid, const double polygon_radius)
    : Container(centroid, polygon_radius, 4)  {}

void Container::Draw() const {
  Path2d mPath;
  mPath.moveTo(polygon_vertices_[0]);
  for (unsigned i = 1; i < shape_; ++i) {
    mPath.lineTo(polygon_vertices_[i]);
  }
  mPath.close();
  ci::gl::color(ci::Color("black"));
  ci::gl::draw(mPath);

  for(unsigned i = 0; i < particles.size(); ++i){
    particles[i].Draw();
  }
}

void Container::AddParticles(const vec2 &c, double mass, double radius, int color) {
  ci::Color _color;
  if(color == 0) _color = "red";
  if(color == 1) _color = "blue";
  if(color == 2) _color = "green";
  particles.emplace_back(c, vec2( 2 , 2), mass, radius, _color);
}

void Container::Update() {
  for (int i = 0; i < particles.size(); ++i) {
    if (glm::distance(centroid_, particles[i].GetPos()) > safe_radius) {
      WallCollisionDetected(particles[i]);
    }
    for (int j = i + 1; j < particles.size(); ++j) {
      if (particles[i].Collide(particles[j])) {
        particles[i].UpdateVelocity(particles[j]);
      }
    }
    particles[i].UpdatePosition();
  }
}

bool Container::WallCollisionDetected(Particle &particle) {
  vec2 p = particle.GetPos(),
       v = particle.GetVel();

  int i = 0;

  do {
    int next = (i+1) % polygon_vertices_.size();
    vec2 n = vec2(polygon_vertices_[next].y - polygon_vertices_[i].y,
                  polygon_vertices_[i].x - polygon_vertices_[next].x);
    double n_length = glm::length(n);
    n = vec2(n.x / n_length, n.y / n_length);

    if(!Inside(polygon_vertices_[i], p, polygon_vertices_[next]) &&
        glm::dot(n, v) <  0){
      particle.SetVel(glm::reflect(v, n));
      return false;
    }
    i = next;
  } while (i != 0);

  return true;
}

bool Container::Inside(const vec2 &p_0, const vec2 &p, const vec2 &p_1) {
  return ((p.y - p_1.y) * (p_0.x - p_1.x) -
          (p.x - p_1.x) * (p_0.y - p_1.y)) >= 0;
}


} // namespace idealgas