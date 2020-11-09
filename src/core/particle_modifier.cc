#include "core/particle_modifier.h"

namespace idealgas{

ParticleModifier::ParticleModifier(const vec2 &pos, const vec2 &size)
    : top_left_(pos), bottom_right_(top_left_ + size){}

void ParticleModifier::DrawParticleModifierSection() const {
//  double inc = (bottom_right_.y - top_left_.y)/5;
  vec2 section(bottom_right_.x - top_left_.x,
               (bottom_right_.y - top_left_.y)/5);
  ci::gl::drawStringCentered("Particle",
      glm::vec2(top_left_.x + section.x/2,
          top_left_.y +  section.y/ 2),
      ci::Color("black"));

//  std::cout << radius_ << mass_;

}

bool ParticleModifier::ChangedParticleSettings(const vec2 &c) { return false; }
}