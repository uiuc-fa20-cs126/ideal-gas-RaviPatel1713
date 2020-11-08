#include <visualizer/ideal_gas_app.h>

namespace idealgas {

namespace visualizer {

IdealGasApp::IdealGasApp()
    : simulator_(standard_config::kWindowWidth,
                 standard_config::kWindowHeight,
                 glm::vec2(standard_config::kMargin,
                                standard_config::kMargin),
          standard_config::kContainerSize) {
  ci::app::setWindowSize((int) standard_config::kWindowWidth,
                         (int) standard_config::kWindowHeight);
}

void IdealGasApp::setup() {
  vec2 current_button_pos = vec2(standard_config::kWindowWidth - 100,
                               standard_config::kWindowHeight - 50);
  vec2 button_size = vec2(80, 35);
  reset_button_ = AppButton("Reset", current_button_pos, button_size);

  current_button_pos -= vec2(100, 0);
  pause_button_ = AppButton("Pause", current_button_pos, button_size);
}

void IdealGasApp::draw() {
  ci::Color8u background_color(255,246,148);  // light yellow
  ci::gl::clear(background_color);

  reset_button_.DrawButton();
  pause_button_.DrawButton();
  simulator_.Draw();
}

void IdealGasApp::update() {
  if (!is_paused){
    simulator_.UpdateSimulation();
  }
}

void IdealGasApp::mouseDown(ci::app::MouseEvent event) {
  if(reset_button_.ClickedButton(event.getPos()))
    simulator_.Clear();
  if(pause_button_.ClickedButton(event.getPos()))
    is_paused = !is_paused;
  else
    //TODO: add funtionality for simulation changes
    return;
}
}  // namespace visualizer

}  // namespace idealgas
