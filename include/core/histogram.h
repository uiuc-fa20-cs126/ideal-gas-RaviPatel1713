#pragma  once
#include "cinder/gl/gl.h"
#include "particle.h"
#include <cmath>
namespace idealgas{
//#define EPSILON_ 0.0000001f;
using glm::vec2;
class Histogram{
public:
  Histogram() = default;
  Histogram(const vec2 &pos, const vec2 &size);

  void Draw() const;

  void Update(const std::vector<Particle> *particles, double mass);
  void Update(const std::vector<Particle> *particles,
              double mass_lower_bound,
              double mass_upper_bound);
private:
  vec2 hist_pos_;
  vec2 hist_size_;
  std::vector<int> speed_distribution_frequency_;
  size_t particle_count_;

};
}