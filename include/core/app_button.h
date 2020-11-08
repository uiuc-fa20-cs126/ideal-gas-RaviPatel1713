#pragma once
#include "cinder/gl/gl.h"
#include <string>

namespace idealgas {
using glm::vec2;

class AppButton {
public:
  AppButton() = default;
  AppButton(const std::string &button_name, const vec2 &button_pos,
            const vec2 &size);
  void DrawButton() const;
  bool ClickedButton(const vec2 &c);

private:
  std::string button_name_;
  vec2 top_left_;
  vec2 bottom_right_;
};
} // namespace idealgas
