#include <visualizer/simulator.h>

namespace idealgas {

namespace visualizer {

using glm::vec2;
using cinder::Path2d;

Simulator::Simulator(double window_width,
                     double window_height,
                     double container_size)
    : window_width_(window_width)
    , window_height_(window_height)
    , particle_container_radius(container_size) {
  vec2 reg_polygon_container_centroid(window_width_/4, window_height_/2);
  container_ = Container(reg_polygon_container_centroid, particle_container_radius);
  vec2 hist_size = vec2(200, 200);
  for (unsigned i = 0; i < 3; ++i) {
    histograms.emplace_back(
        vec2(window_width_ / 2 + hist_size.x,
             50 + (hist_size.y + 50) * i),
        vec2(200, 200));
  }
}


void Simulator::Draw() const {
  container_.Draw();
  for (const Histogram &h : histograms) {
    h.Draw();
  }
}

void Simulator::Clear() {
  window_width_ = standard_config::kWindowWidth;
  window_height_ = standard_config::kWindowHeight;
  particle_container_radius = standard_config::kContainerSize;

  vec2 reg_polygon_container_centroid(window_width_/4, window_height_/2);

  container_ = Container(reg_polygon_container_centroid, particle_container_radius);
  vec2 hist_size = vec2(200, 200);
  for (unsigned i = 0; i < 3; ++i) {
    histograms.emplace_back(
        vec2(window_width_ / 2 + hist_size.x,
             50 + (hist_size.y + 50) * i),
        vec2(200, 200));
  }
}


void Simulator::UpdateSimulation() {
  container_.Update();
  for (unsigned i = 0; i < 3; ++i) {
    histograms[i].Update(&container_.GetParticlesVec(), 10.0f * (i + 1));
  }
}

void Simulator::AddParticlesToContainer(double mass, double radius, int color) {
  container_.AddParticles(mass, radius, color);
}

void Simulator::ChangeContainer(unsigned int shape) {
  vec2 reg_polygon_container_centroid(window_width_/4, window_height_/2);
  container_ = Container(reg_polygon_container_centroid,
                         particle_container_radius, shape);
}

}  // namespace visualizer

}  // namespace idealgas

