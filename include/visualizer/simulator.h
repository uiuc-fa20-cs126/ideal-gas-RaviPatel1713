#pragma once

#include "cinder/gl/gl.h"
#include <cinder/Path2d.h>
#include "core/polygon_container.h"
#include "core/particle_modifier.h"
#include "core/sqr_container.h"
namespace idealgas {
namespace visualizer {
using glm::vec2;

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
  Simulator(double window_width,
//            double window_height,
            const glm::vec2& top_left_corner,
            double simulator_size);

  /**
   * Displays the current state of the simulator in the Cinder application.
   */
  void Draw() const;

  /**
  * Updates the particle positions and other simulation content.
  */
  void UpdateSimulation();

  /**
   * Erases all the particles in the simulator.
   */
  void Clear();

  void AddParticlesToContainer();

private:
  // private methods for rendering app title and other background components
  void PrintAppTitle() const;
  void renderContent() const;

  const double window_width_;
//  const double window_height_;
  vec2 container_top_left_corner_;
  double container_size_;
  SqrContainer container_;
  ParticleModifier particle_modifier_;
};

}  // namespace visualizer

}  // namespace idealgas

