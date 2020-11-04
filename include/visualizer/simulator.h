#pragma once

#include "cinder/gl/gl.h"

namespace idealgas {
using glm::vec2;

struct Particle{
  explicit Particle() = default;
  explicit Particle(const vec2 &pos, const vec2 &vel) : pos_(pos), vel_(vel){}
  vec2 pos_;
  vec2 vel_;
};


namespace visualizer {

/**
 * A simulator which render the particles movements and positioning in an ideal
 * gas simulation environment and respond to mouse events.
 */
class Simulator {
public:
  /**
   * Creates a simulator.
   *
   * @param top_left_corner     the screen coordinates of the top left corner of
   *                            the simulator
   * @param simulator_size      the size of the simulator, measured in
   *                            screen pixels
   */
  Simulator(const glm::vec2& top_left_corner, double simulator_size);

  /**
   * Displays the current state of the simulator in the Cinder application.
   */
  void Draw() const;

  /**
   * Adds particles in the simulation window.
   */
  void AddParticles(const glm::vec2 &pos);

  /**
  * Updates the particle position according to their current velocity.
  */
  void UpdateParticlePosition();

  /**
   * Erases all the particles in the simulator.
   */
  void Clear();

private:
  glm::vec2 top_left_corner_;
  double simulator_size_;
  std::vector<Particle> particles;
};

}  // namespace visualizer

}  // namespace idealgas

