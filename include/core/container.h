#pragma  once

#include <cmath>
#include "cinder/gl/gl.h"
#include "cinder/Path2d.h"
#include "core/particle.h"

namespace idealgas{
class Container{
public:
  Container() = default;

  Container(const vec2 &centeroid, double polygon_radius);

  Container(const vec2 &centeroid, double polygon_radius, unsigned shape);


  void Draw() const;

  void AddParticles(double mass, double radius, int color);

  void Update();
private:

  bool WallCollisionDetected(Particle &particle);
  bool Inside(const vec2 &p_0, const vec2 &p, const vec2 &p_1);
  vec2 centroid_;
  /** minimum radius length of any polygon within which no point is
      colliding with wall */
  double safe_radius;
  double polygon_radius_;
  unsigned shape_;

  std::vector<vec2> polygon_vertices_;
  std::vector<Particle> particles;
};

}