#include "core/histogram.h"
#include "cinder/gl/gl.h"
namespace idealgas{
#define PI 3.14159265

Histogram::Histogram(const vec2 &pos, const vec2 &size)
    : hist_pos_(pos)
    , hist_size_(size){
  speed_distribution_frequency_ =
      std::vector<int>(standard_config::kHistogramBarCount, 0);
}

void Histogram::Draw() const {
  ci::Rectf pixel_bounding_box(hist_pos_,
                               hist_pos_ + hist_size_);
  ci::gl::drawStrokedRect(pixel_bounding_box);
  ci::gl::color(ci::Color(kBLACK));
  ci::gl::drawStrokedRect(pixel_bounding_box);

  // draws labels for the histogram
  // y axis
  ci::gl::pushModelMatrix();
  ci::gl::translate(hist_pos_.x + 5, hist_pos_.y + hist_size_.y/2);
  ci::gl::rotate(-PI/2);
  ci::gl::drawStringCentered(
      "Particle Frequency",
      glm::vec2(0,0),
      ci::Color("black"));
  ci::gl::popModelMatrix();

  // x axis
  vec2 x_axis_babel_center(hist_pos_.x + hist_size_.x/2, hist_pos_.y + hist_size_.y - 10);
  ci::gl::drawStringCentered(
      "Particle Speed",
      x_axis_babel_center,
      ci::Color("black"));

  double bar_width = (hist_size_.x - 40) / standard_config::kHistogramBarCount;

  for(int i = 0; i < standard_config::kHistogramBarCount; ++i){
    double bar_height = (hist_size_.y - 40 )
                      * speed_distribution_frequency_[i]
                      / particle_count_;
    vec2 bar_bottom_right(hist_pos_.x + 20 + bar_width * (i + 1),
                          hist_pos_.y - 20 + hist_size_.y);
    vec2 bar_top_left(
        hist_pos_.x + 20 + bar_width * i,
        hist_pos_.y - 20 + hist_size_.y - bar_height);
    pixel_bounding_box = ci::Rectf(bar_top_left, bar_bottom_right);
    ci::gl::drawStrokedRect(pixel_bounding_box);
    ci::gl::color(ci::Color(kBLUE));
    ci::gl::drawStrokedRect(pixel_bounding_box);
  }



}
void Histogram::Update(const std::vector<Particle> *particles, double mass) {
  speed_distribution_frequency_ =
      std::vector<int>(standard_config::kHistogramBarCount, 0);

  particle_count_ = 0;
  double max_speed = 0;
  for (const Particle &p : *particles){
    if (fabs(mass - p.GetMass()) <= 0.0001f){
      ++particle_count_;
      double speed = glm::length(p.GetVel());
      max_speed = (speed > max_speed) ? speed : max_speed;
    }
  }

  double speed_inc_value = max_speed/standard_config::kHistogramBarCount;
  for (const Particle &p : *particles){
    if (fabs(mass - p.GetMass()) <= 0.0001f){
      double speed = glm::length(p.GetVel());
      for(unsigned bar = 0; bar < standard_config::kHistogramBarCount; ++bar){
        if(speed <= speed_inc_value + speed_inc_value * bar){
          ++speed_distribution_frequency_[bar];
          break;
        }
      }
    }
  }
}

void Histogram::Update(const std::vector<Particle> *particles,
                       double mass_lower_bound, double mass_upper_bound) {

}
}
