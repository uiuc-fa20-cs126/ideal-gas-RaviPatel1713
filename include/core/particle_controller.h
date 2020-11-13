#pragma once

#include "../../../../include/glm/vec2.hpp"
#include <vector>

namespace idealgas {
using glm::vec2;

struct Particle{
  vec2 pos;
  vec2 vel;
};

/**
 * A simulator which render the particles movements and positioning in an ideal
 * gas simulation environment and respond to mouse events.
 */
class ParticleController {
public:
  ParticleController();

private:
  std::vector<Particle> particles;
};

}  // namespace idealgas
