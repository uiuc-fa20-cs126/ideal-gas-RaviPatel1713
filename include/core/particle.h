#pragma  once
#include "cinder/gl/gl.h"
using glm::vec2;

namespace ideal_gas{
class Particle{
public:
  Particle() = default;
  Particle(const vec2 &pos, const vec2 &vel);
  Particle (const vec2 &pos, const vec2 &vel,
            const double mass, const double radius);



protected:
  vec2 pos_;
  vec2 vel_;
  double mass_;
  double radius_;
};
}