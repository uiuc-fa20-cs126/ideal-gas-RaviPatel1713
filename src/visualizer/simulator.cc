#include <visualizer/simulator.h>

namespace idealgas {

namespace visualizer {

using glm::vec2;
using cinder::Path2d;

Simulator::Simulator(double window_width,
                     double window_height,
                     const vec2 &top_left_corner,
                     double container_size)
    : window_width_(window_width)
    , window_height_(window_height)
    , container_top_left_corner_(top_left_corner)
    , container_size_(container_size) {
  vec2 polygon_center(container_top_left_corner_ +
                      vec2(container_size_ / 2, container_size_ / 2));
  container_ = Container(polygon_center, container_size_ / 2);
//  vec2 hist_size = vec2(200, 200);
//  for (unsigned i = 0; i < 3; ++i) {
//    histograms.emplace_back(
//        vec2(window_width_ / 2 + hist_size.x,
//             container_top_left_corner_.x + (hist_size.y + 50) * i),
//        vec2(200, 200);
//  }
}


void Simulator::Draw() const {
  // print app title
  ci::gl::drawStringCentered(
      standard_config::kAppTitle,
     glm::vec2(window_width_ / 2, 25),
      ci::Color(kBLACK));

  container_.Draw();
//  for (const Histogram &h : histograms) { h.Draw(); }
}

void Simulator::Clear() {

}


void Simulator::UpdateSimulation() {
  container_.Update();
}

void Simulator::AddParticlesToContainer(double mass, double radius, int color) {
  container_.AddParticles(mass, radius, color);
}
void Simulator::ChangeContainer(unsigned int shape) {
  if (shape < 3) {
    throw std::invalid_argument("The container has to have at least 3 sides.");
  }
  vec2 polygon_center(container_top_left_corner_
                      + vec2(container_size_/2, container_size_/2));
  container_ = Container(polygon_center,
                         container_size_/2, shape);
}

}  // namespace visualizer

}  // namespace idealgas

