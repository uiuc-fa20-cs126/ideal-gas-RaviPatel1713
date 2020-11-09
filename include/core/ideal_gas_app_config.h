#pragma once

#include "cinder/gl/gl.h"
using glm::vec2;

namespace idealgas {
namespace standard_config {
// app window size
const double kWindowWidth = 1200.0f;
const double kWindowHeight = 800.0f;

// simulator configs
const vec2 kContainerCenter(350, 350);
const double kContainerSize = 600.0f;
const double kRadius = 10.0f;
const double kMass = 40.0f;
const double kMargin = 50.0f;
const unsigned kHistogramBarCount = 10;
} // namespace standard_config

namespace particle_config{
const double kMinMass = 10.0f,
             kMaxMass = 40.0f;
const double kMinRadius = 2.0f,
             kMaxRadius = 8.0f;
const double kMinVelocity = 4.0f,
             kMaxVelocity = 10.0f;
}

} // namespace idealgas


