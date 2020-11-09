#include "core/app_param_settings.h"

namespace idealgas{

AppParamSettings::AppParamSettings(const vec2 &pos, const vec2 &size)
    : top_left_(pos), bottom_right_(top_left_ + size){
//  mParams = params::InterfaceGl("App parameters",
//      toPixels( ivec2( 200, 180 ) ) );
//  mParams.addParam( "Cube Size", &vel_)
//      .min( 0.1f )
//      .max( 10.0f )
//      .step( 0.1f );
}

void AppParamSettings::DrawParticleModifierSection() const {
//  double inc = (bottom_right_.y - top_left_.y)/5;
  vec2 section(bottom_right_.x - top_left_.x,
               (bottom_right_.y - top_left_.y)/5);
  ci::gl::drawStringCentered("Particle",
      glm::vec2(top_left_.x + section.x/2,
          top_left_.y +  section.y/ 2),
      ci::Color("black"));

//  mParams->draw();


//  std::cout << radius_ << mass_;

}

bool AppParamSettings::ChangedParticleSettings(const vec2 &c) { return false; }
}