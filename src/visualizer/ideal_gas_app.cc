#include <visualizer/ideal_gas_app.h>

namespace idealgas {

namespace visualizer {

IdealGasApp::IdealGasApp()
    : simulator_(glm::vec2(kMargin, kMargin),
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize,
                         (int) kWindowSize);
}

void IdealGasApp::draw() {
  ci::Color8u background_color(255,
                               246,
                               148);  // light yellow
  ci::gl::clear(background_color);

  // call simulator Draw() method here
  simulator_.Draw();
}

void IdealGasApp::update() {
  simulator_.UpdateParticlePosition();
}

void IdealGasApp::mouseDown(ci::app::MouseEvent event) {
  simulator_.AddParticles(event.getPos());
}

}  // namespace visualizer

}  // namespace idealgas
