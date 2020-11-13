#include "core/test_particle.h"

namespace idealgas{
Particle::Particle(const vec2 &pos,
                   const vec2 &vel,
                   const double mass,
                   const double radius,
                   const ci::Color color)
    : pos_(pos)
    , vel_(vel)
    , mass_(mass)
    , radius_(radius)
    , color_(color){
}

bool Particle::CollidedWith(const Particle &other) const {
  return (glm::distance(pos_, other.pos_) <= 14 &&
          glm::dot(vel_ - other.vel_, pos_ - other.pos_) < 0);
}
void Particle::UpdateCollidedParticlesVelocities(Particle &other) {
  vec2 vec1_diff_vec2 = vel_ - other.vel_;
  vec2 pos1_diff_pos2 = pos_ - other.pos_;
  double mass_ratio;
  double length_sqr = pow(glm::length(pos1_diff_pos2), 2.0);
  double ratio = glm::dot(vec1_diff_vec2, pos1_diff_pos2)/length_sqr;

  // velocity calculator for particle 1
  mass_ratio = 2 * (other.mass_/(mass_ + other.mass_));
  vel_ -= vec2(mass_ratio * ratio * pos1_diff_pos2.x,
               mass_ratio * ratio * pos1_diff_pos2.y);

  // velocity calculator for particle 2 (_other_)
  mass_ratio = -2 * (mass_/(mass_ + other.mass_));
  other.vel_ -= vec2(mass_ratio * ratio * pos1_diff_pos2.x,
                      mass_ratio * ratio * pos1_diff_pos2.y);
}
void Particle::Draw() const {
  ci::gl::color(ci::Color(color_));
  ci::gl::drawSolidCircle(pos_, radius_);
}
void Particle::UpdatePosition() {
  pos_ += vel_;
}


vec2 Particle::GetPos() const { return pos_; }

vec2 Particle::GetVel() const { return vel_; }

void Particle::SetVel(const vec2 &v) { vel_ = v;}

double Particle::GetMass() const { return mass_; }

}


