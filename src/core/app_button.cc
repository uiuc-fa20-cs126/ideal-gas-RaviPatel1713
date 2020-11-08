#include "core/app_button.h"

#include <utility>

namespace idealgas {

AppButton::AppButton(const std::string &button_name, const vec2 &button_pos,
                     const vec2 &size)
    : button_name_(button_name)
    , top_left_(button_pos)
    , bottom_right_(top_left_ + size) {}

void AppButton::DrawButton() const {
  ci::Rectf pixel_bounding_box(top_left_, bottom_right_);
  ci::gl::drawStrokedRect(pixel_bounding_box);
  ci::gl::color(ci::Color("red"));
  ci::gl::drawSolidRect(pixel_bounding_box);

  // render button name on button tag created above
  ci::gl::drawStringCentered(
      button_name_,
      vec2(top_left_.x + (bottom_right_.x - top_left_.x)/2,
                top_left_.y + (bottom_right_.y - top_left_.y)/2),
      ci::Color("white"));
}
bool AppButton::ClickedButton(const vec2 &c) {
  return (c.y >= top_left_.y && c.y <= bottom_right_.y &&
          c.x >= top_left_.x && c.x <= bottom_right_.x);
}
} // namespace idealgas
