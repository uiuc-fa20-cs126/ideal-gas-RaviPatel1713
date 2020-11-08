#pragma  once

#include "core/polygon_container.h"
#include "cinder/gl/gl.h"
#include <cmath>
#include "cinder/Path2d.h"
#include "core/particle.h"

namespace idealgas{
using glm::vec2;
class SqrContainer{
public:
  SqrContainer() = default;

  SqrContainer(const vec2 &centeroid, double polygon_radius);

  void Draw() const;

  void AddParticles(const vec2 &c);

  void Update();

  /*
//  void Draw() const override;
//  void AddParticles(const vec2 &c) override;
//  void Update() override;
   */
private:
  bool IsInside(Particle &particle);
  int Orientation(const vec2 &p, const vec2 &q, const vec2 &r);
  bool doIntersect(const vec2 &p1, const vec2 &q1,
                   const vec2 &p2, const vec2 &q2);
  bool OnSegment(const vec2 &p, const vec2 &q, const vec2 &r);

  vec2 centroid_;
  double polygon_radius_;
  std::vector<vec2> polygon_vertices_;
  std::vector<Particle> particles;
};

}