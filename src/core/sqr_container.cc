#include <core/sqr_container.h>

namespace idealgas {
using cinder::Path2d;
using glm::vec2;
#define PI 3.14159265
#define INF standard_config::kWindowWidth

SqrContainer::SqrContainer(const vec2 &centroid, const double polygon_radius)
    : centroid_(centroid), polygon_radius_(polygon_radius) {
  //  double current_degree = -PI/2;
  double current_degree = 2 * PI - PI / 4;

  for (unsigned i = 0; i < 4; ++i) {
    vec2 vertex(cos(current_degree) * (polygon_radius_),
                sin(current_degree) * (polygon_radius_));
    vertex += centroid;
    polygon_vertices_.push_back(vertex);
    current_degree -= 2 * PI / 4;
  }
}

void SqrContainer::Draw() const {
  Path2d mPath;
  mPath.moveTo(polygon_vertices_[0]);
  for (unsigned i = 1; i < 4; ++i) {
    mPath.lineTo(polygon_vertices_[i]);
  }
  mPath.close();
  ci::gl::color(ci::Color("black"));
  ci::gl::draw(mPath);

  for(unsigned i = 0; i < particles.size(); ++i){
    particles[i].Draw();
  }
}

void SqrContainer::AddParticles(const vec2 &c) {
  particles.emplace_back(c, vec2(5, 5), 20, 7, "red");
}

void SqrContainer::Update() {
  for (int i = 0; i < particles.size(); ++i) {

//    IsInside(particles[i]);
    for (int j = i; j < particles.size(); ++j) {
      if (particles[i].Collide(particles[j])) {
        particles[i].UpdateVelocity(particles[j]);
      }
    }
    particles[i].UpdatePosition();
  }
}

//=============================================================================/
// The following code implementation for wall collision checking for polygon
// other than rectangle.
//https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/
//=============================================================================/

bool SqrContainer::OnSegment(const vec2 &p, const vec2 &q, const vec2 &r) {
  return (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
          q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
}

int SqrContainer::Orientation(const vec2 &p, const vec2 &q, const vec2 &r){
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0)
    return 0;               // co-linear
  return (val > 0) ? 1 : 2; // clock or counter-clock wise
}

bool SqrContainer::doIntersect(const vec2 &p1, const vec2 &q1,
                               const vec2 &p2, const vec2 &q2) {
  // Find the four orientations needed for general and
  // special cases
  int o1 = Orientation(p1, q1, p2);
  int o2 = Orientation(p1, q1, q2);
  int o3 = Orientation(p2, q2, p1);
  int o4 = Orientation(p2, q2, q1);

  // General case
  if (o1 != o2 && o3 != o4)
    return true;

  // Special Cases
  // p1, q1 and p2 are colinear and p2 lies on segment p1q1
  if (o1 == 0 && OnSegment(p1, p2, q1)) return true;

  // p1, q1 and p2 are colinear and q2 lies on segment p1q1
  if (o2 == 0 && OnSegment(p1, q2, q1)) return true;

  // p2, q2 and p1 are colinear and p1 lies on segment p2q2
  if (o3 == 0 && OnSegment(p2, p1, q2)) return true;

  // p2, q2 and q1 are colinear and q1 lies on segment p2q2
  if (o4 == 0 && OnSegment(p2, q1, q2)) return true;

  return false; // Doesn't fall in any of the above cases
}

bool SqrContainer::IsInside(Particle &particle) {
  vec2 &p = particle.GetPos();
  vec2 extreme(INF, p.y);

  // Count intersections of the above line with sides of polygon
  int count = 0, i = 0;
  do {
    int next = (i+1) % polygon_vertices_.size();

    // Check if the line segment from 'p' to 'extreme' intersects
    // with the line segment from 'polygon[i]' to 'polygon[next]'
    if (doIntersect(polygon_vertices_[i],
                    polygon_vertices_[next],
                    p, extreme)) {
      // If the point 'p' is colinear with line segment 'i-next',
      // then check if it lies on segment. If it lies, return true,
      // otherwise false
      if (Orientation(polygon_vertices_[i],p,
                      polygon_vertices_[next]) == 0) {
        if (OnSegment(polygon_vertices_[i], p,
                         polygon_vertices_[next])){
          vec2 normal = glm::normalize(polygon_vertices_[i]
                                       - polygon_vertices_[next]);
          double ratio = 2 * glm::dot(p, normal);
          p -= vec2(ratio * normal.x, ratio * normal.y);
          return true;
        }
        return false;
      }

      ++count;
    }
    i = next;
  } while (i != 0);

  // Return true if count is odd, false otherwise
  return count&1;  // Same as (count%2 == 1)
}


} // namespace idealgas