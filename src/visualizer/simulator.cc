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

  for(int i = 0; i < particles.size(); ++i){
    ci::gl::color(ci::Color("red"));
    ci::gl::drawSolidCircle(particles[i].pos_, 7);
  }
}

void Simulator::Clear() {
  particles.clear();
}

void Simulator::AddParticles(const glm::vec2 &pos) {
  // checks bounds
  if (pos.x > top_left_corner_.x &&
      pos.x < top_left_corner_.x + simulator_size_ &&
      pos.y > top_left_corner_.y &&
      pos.y < top_left_corner_.y + simulator_size_){
    particles.emplace_back(glm::vec2(pos.x, pos.y),
                           glm::vec2(5, 5));
  }
}
void Simulator::UpdateParticlePosition() {
  for(int i = 0; i < particles.size(); ++i){
    if (particles[i].pos_.x - 7 <= top_left_corner_.x &&
        particles[i].vel_.x < 0){
      particles[i].vel_.x = -1 * particles[i].vel_.x;
    }
    else if (particles[i].pos_.x + 7 >= top_left_corner_.x + simulator_size_&&
        particles[i].vel_.x > 0){
      particles[i].vel_.x = -1 * particles[i].vel_.x;
    }

    if (particles[i].pos_.y - 7 <= top_left_corner_.y &&
        particles[i].vel_.y < 0){
      particles[i].vel_.y = -1 * particles[i].vel_.y;
    }
    else if (particles[i].pos_.y + 7 >= top_left_corner_.y + simulator_size_&&
        particles[i].vel_.y > 0){
      particles[i].vel_.y = -1 * particles[i].vel_.y;
    }


    particles[i].pos_ +=  particles[i].vel_;
  }
}

}  // namespace visualizer

}  // namespace idealgas

