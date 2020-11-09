#include "core/histogram.h"

namespace idealgas{

Histogram::Histogram(const vec2 &pos, const vec2 &size)
    : hist_pos_(pos)
    , hist_size_(size){
}

void Histogram::Draw() const {
  ci::Rectf pixel_bounding_box(hist_pos_,
                               hist_pos_ + hist_size_);
//  ci::gl::drawStrokedRect(pixel_bounding_box);
  ci::gl::color(ci::Color("black"));
  ci::gl::drawStrokedRect(pixel_bounding_box);

  double bar_width = hist_size_.x / standard_config::kHistogramBarCount;

  for(int i = 0; i < standard_config::kHistogramBarCount; ++i){
    double bar_height = hist_size_.y * (speed_distribution_frequency_[i]/particle_count_);
    vec2 bar_bottom_right(hist_pos_.x + bar_width * (i + 1),
                          hist_pos_.y + hist_size_.y);
    vec2 bar_top_left(
        hist_pos_.x + bar_width * i,
        hist_pos_.y + hist_size_.y - bar_height);
    pixel_bounding_box = ci::Rectf(bar_top_left, bar_bottom_right);
    ci::gl::drawStrokedRect(pixel_bounding_box);
    ci::gl::color(ci::Color("blue"));
    ci::gl::drawStrokedRect(pixel_bounding_box);
  }

}
void Histogram::Update(const std::vector<Particle> *particles, double mass) {
  speed_distribution_frequency_ =
      std::vector<int>(standard_config::kHistogramBarCount);

  double max_speed = 0;
  for (const Particle &p : *particles){
    if (fabs(mass - p.GetMass()) <= 0.0000001f){
      ++particle_count_;
      double speed = glm::length(p.GetVel());
      if(speed > max_speed){
        max_speed = speed;
      }
    }
  }

  double speed_inc_value = max_speed/standard_config::kHistogramBarCount;
  for (const Particle &p : *particles){
    if (fabs(mass - p.GetMass()) <= 0.0000001f){
      double speed = glm::length(p.GetVel());
      for(unsigned bar = 0; bar < standard_config::kHistogramBarCount; ++bar){
        if(speed < speed_inc_value + speed_inc_value * bar){
          ++speed_distribution_frequency_[bar];
        }
      }
    }
  }

}
void Histogram::Update(const std::vector<Particle> *particles,
                       double mass_lower_bound, double mass_upper_bound) {

}
}
