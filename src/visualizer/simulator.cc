#include <visualizer/simulator.h>

namespace idealgas {

namespace visualizer {

using glm::vec2;

Simulator::Simulator(const vec2 &top_left_corner, double simulator_size)
    : top_left_corner_(top_left_corner), simulator_size_(simulator_size) {
}


void Simulator::Draw() const {
  vec2 pixel_bottom_right =
      top_left_corner_ + vec2(simulator_size_, simulator_size_);
  ci::Rectf pixel_bounding_box(top_left_corner_, pixel_bottom_right);
  ci::gl::drawStrokedRect(pixel_bounding_box);
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(pixel_bounding_box);
}

void Simulator::Clear() {

}

void Simulator::AddParticles(const glm::vec2 &pos) {
}
void Simulator::UpdateParticlePosition() {
}

}  // namespace visualizer

}  // namespace idealgas

