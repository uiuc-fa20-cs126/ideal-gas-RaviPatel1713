#include <visualizer/ideal_gas_app.h>

namespace idealgas {

namespace visualizer {

IdealGasApp::IdealGasApp()
    : simulator_(idealgas::standard_config::kWindowWidth,
                 idealgas::standard_config::kWindowHeight,
                 glm::vec2(idealgas::standard_config::kMargin,
                                idealgas::standard_config::kMargin),
          idealgas::standard_config::kContainerSize) {
  ci::app::setWindowSize((int) idealgas::standard_config::kWindowWidth,
                         (int) idealgas::standard_config::kWindowHeight);
}

void IdealGasApp::setup() {
//  AppBase::setup();
}

void IdealGasApp::draw() {
  ci::Color8u background_color(255,246,148);  // light yellow
  ci::gl::clear(background_color);

  simulator_.Draw();
}

void IdealGasApp::update() {
//  simulator_.UpdateSimulation();
}

void IdealGasApp::mouseDown(ci::app::MouseEvent event) {
//  simulator_.AddParticles(event.getPos());
}


}  // namespace visualizer

}  // namespace idealgas
