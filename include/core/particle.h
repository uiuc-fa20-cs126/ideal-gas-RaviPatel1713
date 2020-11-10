#pragma  once
#include "cinder/gl/gl.h"
#include "ideal_gas_app_config.h"

namespace idealgas{
using glm::vec2;
class Particle {
public:
  Particle() = default;
  Particle(const vec2 &pos, const vec2 &vel, double mass, double radius,
           const ci::Color color);
  bool Collide(const Particle &other) const;

  void UpdateVelocity(Particle &other);

  void Draw() const;

  void UpdatePosition();

  vec2 GetPos() const;
  vec2 GetVel() const;

  void SetVel(const vec2 &v);

  double GetMass() const;

private:
  vec2 pos_, vel_;
  double mass_, radius_;
  ci::Color color_;
};
}