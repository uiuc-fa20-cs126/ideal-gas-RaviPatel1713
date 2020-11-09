#include <visualizer/simulator.h>

namespace idealgas {

namespace visualizer {

using glm::vec2;
using cinder::Path2d;

Simulator::Simulator(double window_width,
//                     double window_height,
                     const vec2 &top_left_corner,
                     double container_size)
      : window_width_(window_width)
//      , window_height_(window_height)
      , container_top_left_corner_(top_left_corner)
      , container_size_(container_size){
  vec2 polygon_center(container_top_left_corner_
                      + vec2(container_size_/2, container_size_/2));
  container_ = Container(polygon_center,container_size_/2);
}


void Simulator::PrintAppTitle() const {
  ci::gl::drawStringCentered(
      "Ideal Gas Simulation",
      glm::vec2(
          window_width_ / 2,
          container_top_left_corner_.x / 2), // window margin
      ci::Color("black"));
}
void Simulator::renderContent() const {
  vec2 pixel_top_left = vec2(2 * container_top_left_corner_.x + container_size_,
                                 container_top_left_corner_.x);
  vec2 pixel_bottom_right = pixel_top_left + vec2(230, 230);
  ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
  ci::gl::drawStrokedRect(pixel_bounding_box);
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(pixel_bounding_box);

  pixel_top_left += vec2(container_top_left_corner_.x + 200, 0);
  pixel_bottom_right = pixel_top_left + vec2(230, 230);
  pixel_bounding_box  = ci::Rectf(pixel_top_left, pixel_bottom_right);
  ci::gl::drawStrokedRect(pixel_bounding_box);
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(pixel_bounding_box);

  pixel_top_left += vec2(0, 250);
  pixel_bottom_right = pixel_top_left + vec2(230, 230);
  pixel_bounding_box  = ci::Rectf(pixel_top_left, pixel_bottom_right);
  ci::gl::drawStrokedRect(pixel_bounding_box);
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(pixel_bounding_box);
}

void Simulator::Draw() const {
  PrintAppTitle();
  renderContent();
  container_.Draw();
  
}

void Simulator::Clear() {

}


void Simulator::UpdateSimulation() {
  container_.Update();
}

void Simulator::AddParticlesToContainer(double mass, double radius, int color) {
  container_.AddParticles(vec2(350, 350), mass, radius, color);
}
void Simulator::ChangeContainer(unsigned int shape) {
  if (shape < 3)
    throw std::invalid_argument("The container has to have at least 3 sides.");
  vec2 polygon_center(container_top_left_corner_
                      + vec2(container_size_/2, container_size_/2));
  container_ = Container(polygon_center,
                         container_size_/2, shape);
}

}  // namespace visualizer

}  // namespace idealgas

