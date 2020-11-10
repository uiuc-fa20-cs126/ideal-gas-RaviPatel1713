#pragma once

#include "cinder/gl/gl.h"
#include "core/container.h"
#include <cinder/Path2d.h>
#include "core/histogram.h"
namespace idealgas {
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
  Simulator(double window_width,
            double window_height,
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

  void AddParticlesToContainer(double mass, double radius, int color);

  void ChangeContainer(unsigned shape);

private:
  const double window_width_;
  const double window_height_;
  vec2 container_top_left_corner_;
  double container_size_;
  Container container_;
//  std::vector<Histogram> histograms;
};

}  // namespace visualizer

}  // namespace idealgas

