#include <core/container.h>
#include <string>

namespace idealgas {
using cinder::Path2d;
using glm::vec2;

#define PI 3.14159265

Container::Container(const std::vector<glm::vec2> &polygon_vertices)
    : polygon_vertices_(polygon_vertices){}

Container::Container(const vec2 &centeroid, double polygon_radius,
                     unsigned shape)
    : centroid_(centeroid),
      polygon_radius_(polygon_radius),
      shape_(shape)
{
  if (shape < 3) {
    throw std::invalid_argument("The container has to have at least 3 sides.");
  }
  // the following settings for plotting a regular polygon are done since the
  // xy coordinate system in computer programming different and starts at
  // top left corner of a window and goes to bottom right for positive slope.


  // for odd sided polygon defaults the first vertex starts at y-axis
  double current_degree = -PI/2; // angle in rads w/r to centroid

  if (shape%2 == 0){  //  for even sided regular polygon
    // the counter-clockwise vertex plotting starts at first vertex before
    // x-axis
    current_degree = 2 * PI - PI / shape;
  }

  for (unsigned i = 0; i < shape; ++i) {
    vec2 vertex(cos(current_degree) * (polygon_radius_),
                sin(current_degree) * (polygon_radius_));
    //
    vertex += centroid_;
    polygon_vertices_.push_back(vertex);
    current_degree -= 2 * PI / shape ; // updates angle for next vertex
  }
  safe_radius = polygon_radius_ * cos(PI/shape);
  particles = std::vector<Particle>();
}

Container::Container(const vec2 &centroid, const double polygon_radius)
    : Container(centroid, polygon_radius, 4)
{/*default shaped container*/}

void Container::Draw() const {
  Path2d mPath;
  mPath.moveTo(polygon_vertices_[0]);
  for (unsigned i = 1; i < shape_; ++i) {
    mPath.lineTo(polygon_vertices_[i]);
  }
  mPath.close();
  ci::gl::color(ci::Color(kBLACK));
  ci::gl::draw(mPath);

  for(unsigned i = 0; i < particles.size(); ++i){
    particles[i].Draw();
  }
}

void Container::AddParticles(double mass, double radius, int color) {
  ci::Color _color;
  if(color == 0) _color = kRED;
  if(color == 1) _color = kBLUE;
  if(color == 2) _color = kGREEN;
  particles.emplace_back(centroid_,
                         particle_config::kStartingVel,
                         mass, radius, _color);
}

void Container::Update() {
  for (int i = 0; i < particles.size(); ++i) {
    if (glm::distance(centroid_, particles[i].GetPos()) > safe_radius) {
      WallCollisionDetected(particles[i]);
    }
    for (int j = i + 1; j < particles.size(); ++j) {
      if (particles[i].CollidedWith(particles[j])) {
        particles[i].UpdateCollidedParticlesVelocities(particles[j]);
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

    if(!HasInwardOrientation(polygon_vertices_[i], p, polygon_vertices_[next]) &&
        glm::dot(n, v) <  0){
      particle.SetVel(glm::reflect(v, n));
      return false;
    }
    i = next;
  } while (i != 0);

  return true;
}

bool Container::HasInwardOrientation(const vec2 &v_0, const vec2 &p, const vec2 &v_1) {
  return ((p.y - v_1.y) * (v_0.x - v_1.x) -
          (p.x - v_1.x) * (v_0.y - v_1.y)) >= 0;
}

vec2 Container::GetCentroid() const { return centroid_; }

double Container::GetPolygonRadius() const { return polygon_radius_; }

unsigned Container::GetShape() const { return shape_; }

const std::vector<vec2> &Container::GetPolygonVertices() const {
  return polygon_vertices_;
}

const std::vector<Particle>&Container::GetParticlesVec() {
  return particles;
}

} // namespace idealgas