#pragma  once
#include "cinder/gl/gl.h"
#include "ideal_gas_app_config.h"

namespace idealgas{
using glm::vec2;
class Particle {
public:
  Particle() = default;

  /**
   * Constructs a particle with specified position,velocity, mass, radius,
   * and color.
   */
  Particle(const vec2 &pos,
           const vec2 &vel,
           double mass,
           double radius,
           const ci::Color color);

  /**
   * Checks and returns whether the current particle collided with other
   * particle.
   */
  bool CollidedWith(const Particle &other) const;

  /**
   * Updates the velocities of current particle and other particle collided
   * with.
   */
  void UpdateCollidedParticlesVelocities(Particle &other);

  /**
   * Draws the particle with current position.
   */
  void Draw() const;

  /**
   * Updates a particle position.
   */
  void UpdatePosition();

  void SetVel(const vec2 &v);

  vec2 GetPos() const;

  vec2 GetVel() const;

  double GetMass() const;

private:
  vec2 pos_, vel_;
  double mass_, radius_;
  ci::Color color_;
};
}