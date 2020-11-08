#pragma  once
#include "cinder/gl/gl.h"
#include "ideal_gas_app_config.h"
namespace idealgas{
using glm::vec2;
class Particle{
public:
  Particle() = default;
  Particle(const vec2 &pos, const vec2 &vel);
  Particle (const vec2 &pos, const vec2 &vel,
            const double mass, const double radius);
  bool Collide(const Particle *other) const;

  void UpdateParticlePosition(Particle *other);


private:
  vec2 pos_;
  vec2 vel_;
  double mass_;
  double radius_;
};
}