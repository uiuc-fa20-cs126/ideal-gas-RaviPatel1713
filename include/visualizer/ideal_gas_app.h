#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "core/ideal_gas_app_config.h"
#include "simulator.h"
#include <core/app_button.h>

namespace idealgas {

namespace visualizer {

/**
 * Allows a user to simulate ideal gas in an ideal gas simulation and visualize
 * it on the window screen.
 */
class IdealGasApp : public ci::app::App {
 public:
  IdealGasApp();
  void setup() override;
  void draw() override;
  void update() override;
  void mouseDown(ci::app::MouseEvent event) override;
 private:
  Simulator simulator_;
  AppButton reset_button_;
  AppButton pause_button_; // pause and unpause in the same button
  bool is_paused;
//  std::vector<Histogram> h
};

}  // namespace visualizer

}  // namespace idealgas
