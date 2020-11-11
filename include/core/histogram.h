#pragma  once
#include "cinder/gl/gl.h"
#include "test_particle.h"
#include <cmath>
namespace idealgas{
class Histogram{
public:
  Histogram() = default;

  /**
   * Constructs a histogram at a specified position and size.
   */
  Histogram(const vec2 &pos, const vec2 &size);

  /**
   * Draws the histograms.
   */
  void Draw() const;

  /**
   * Updates histogram with specified mass.
   */
  void Update(const std::vector<Particle> *particles, double mass);

  /**
   * Updates histogram with specified mass upper and lower bound.
   */
  void Update(const std::vector<Particle> *particles,
              double mass_lower_bound,
              double mass_upper_bound);
private:
  vec2 hist_pos_;
  vec2 hist_size_;
  std::vector<int> speed_distribution_frequency_;
  int particle_count_;

};
}