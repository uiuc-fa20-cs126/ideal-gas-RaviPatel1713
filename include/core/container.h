#pragma once

#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "core/ideal_gas_app_config.h"
#include "core/test_particle.h"
#include <cmath>
namespace idealgas {
class Container {
public:
  Container() = default;

  /**
   * Creates a square shaped ideal gas container.
   *
   * @param centeroid the center of a square container shape in
   * cinder app window pixel.
   * @param polygon_radius the radius of a square container.
   */
  Container(const vec2 &centeroid, double polygon_radius);

  /**
   * Creates an ideal gas of container of specified shape.
   *
   * @param centeroid the center of a polygon container shape in
   *    cinder app window pixel.
   * @param polygon_radius the radius of a polygon container.
   * @param shape the shape of the container unsigned int representing its
   *    total number of sides.
   */
  Container(const vec2 &centeroid, double polygon_radius, unsigned shape);

  /**
   * Creates an regular/irregular polygon container shape with a counter
   * -clockwise orientation of vertices plotting.
   *
   * @param polygon_vertices vector of vertices to plotted to make a polygon.
   */
  Container(const std::vector<glm::vec2> &polygon_vertices);

  /**
   * Releases particles into the ideal gas container.
   */
  void AddParticles(double mass, double radius, int color);

  /**
   * Checks and returns whether a wall collision detected for a particle.
   */
  bool WallCollisionDetected(Particle &particle);

  /**
   * Checks and returns whether a particle has inward orientation, which means
   * the particle is inside, with respect to a side represented by 2 vertices
   * of a polygon container.
   */
  bool HasInwardOrientation(const vec2 &v_0, const vec2 &p, const vec2 &v_1);

  /**
   * Draws the container state with respect to particle movement.
   */
  void Draw() const;

  /**
   * Updates the state of the container with respect to particle movement.
   */
  void Update();

  //  getter methods
  vec2 GetCentroid() const;
  double GetPolygonRadius() const;
  unsigned GetShape() const;
  const std::vector<vec2> &GetPolygonVertices() const;
  const std::vector<Particle> &GetParticlesVec();

private:
  vec2 centroid_;
  /** minimum radius length of any polygon within which no point is
      colliding with wall */
  double safe_radius;
  double polygon_radius_;
  unsigned shape_;

  std::vector<vec2> polygon_vertices_;
  std::vector<Particle> particles;
};

}