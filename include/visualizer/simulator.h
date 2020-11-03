#pragma once

#include "cinder/gl/gl.h"

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
   * @param sketchpad_size      the side length of the sketchpad, measured in
   *                            screen pixels
   */
  Simulator(const glm::vec2& top_left_corner, double simulator_size);

  /**
   * Displays the current state of the simulator in the Cinder application.
   */
  void Draw() const;

  /**
   * Erases all the particles in the simulator.
   */
  void Clear();

private:
  glm::vec2 top_left_corner_;

  /** Number of screen pixels in the width/height of one sketchpad pixel */
  double pixel_side_length_;
};

}  // namespace visualizer

}  // namespace idealgas

