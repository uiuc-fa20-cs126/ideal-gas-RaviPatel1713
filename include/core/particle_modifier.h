#pragma  once
#include "cinder/gl/gl.h"
namespace idealgas{
using glm::vec2;
class ParticleModifier{
public:
  ParticleModifier() = default;
  ParticleModifier(const vec2 &pos, const vec2 &size);

  void DrawParticleModifierSection() const;

  bool ChangedParticleSettings(const vec2 &c);

private:
  vec2 top_left_;
  vec2 bottom_right_;

  vec2 vel_;
  double mass_;
  double radius_;
  std::vector<std::string> particle_color_;
};
}