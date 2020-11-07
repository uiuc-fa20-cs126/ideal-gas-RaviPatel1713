#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "simulator.h"

namespace idealgas {

namespace visualizer {

/**
 * Allows a user to simulate ideal gas in an ideal gas simulation and visualize
 * it on the window screen.
 */
class IdealGasApp : public ci::app::App {
 public:
  IdealGasApp();

  void draw() override;
  void update() override;
  void mouseDown(ci::app::MouseEvent event) override;

  const double kWindowWidth = 1200;
  const double kWindowHeight = 800;

  const double kMargin = 60;
 private:
  Simulator simulator_;
};

}  // namespace visualizer

}  // namespace idealgas
