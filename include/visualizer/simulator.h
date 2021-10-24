#pragma once

#include "cinder/gl/gl.h"
#include "core/container.h"
#include <cinder/Path2d.h>
#include "core/histogram.h"
namespace idealgas {
namespace visualizer {
/**
 * A simulator which render the particles movements and 3 speed distribution
 * histograms for different masses in an ideal gas simulation environment and
 * respond to mouse events.
 */
class Simulator {
public:
  /**
   * Creates a simulator.
   *
   * @param window_width the cinder application rendering window width
   * @param window_height the cinder application rendering window height
   * @param particle_container_radius the container created from a regular
   *        polygon with a centroid and radius
   */
  Simulator(double window_width,
            double window_height,
            double particle_container_radius);

  /**
   * Displays the current state of the simulator with histograms.
   */
  void Draw() const;

  /**
  * Updates the particle positions and histograms.
  */
  void UpdateSimulation();

  /**
   * Resets the simulator to its default settings.
   */
  void Clear();

  /**
   * Add particles into the ideal gas container environment.
   * @param mass the mass of the particle to be added
   * @param radius the radius of the particle to be added
   * @param color the color of the particle to be added
   */
  void AddParticlesToContainer(double mass, double radius, int color);

  /**
   * Changes the container polygon shape.
   * @param shape the polygon shape of the container represented by unsigned
   * int (for example, 3->triangular, 4->rectangular(square), and so on)
   */
  void ChangeContainer(unsigned shape);

private:
  double window_width_;
  double window_height_;
  double particle_container_radius;
  Container container_;
  std::vector<Histogram> histograms;
};

}  // namespace visualizer

}  // namespace idealgas

