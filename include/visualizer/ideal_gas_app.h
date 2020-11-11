#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"

#include "core/ideal_gas_app_config.h"
#include "simulator.h"

#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/Utilities.h"

using namespace ci;
using namespace ci::app;

namespace idealgas {
using glm::vec2;
namespace visualizer {

/**
 * Allows a user to simulate ideal gas in an ideal gas simulation and visualize
 * it on the window screen.
 */
class IdealGasApp : public ci::app::App {
 public:
   /**
    * Conctructs an app window for Ideal Gas Simulation.
    */
  IdealGasApp();

  /**
   * Initializes textureFont for app title and app parameter tweaker from
   * cinder's sub-libraries called params::InterfaceGlRef.
   */
  void setup() override;

  /**
   * Draws the app title, app param, container simulator and associated
   * histograms.
   */
  void draw() override;

  /**
   * Updates simulator state.
   */
  void update() override;

  /**
   * Used exclusively for adding particles to container
   */
  void keyDown(ci::app::KeyEvent event) override;

private:
  Simulator simulator_;
  bool is_paused;
  /**cinder app param is a parameter tweaker for simulation to tweak with
   * container and particle parameters and to pause/unpause and reset the
   * simulation.
   */
  params::InterfaceGlRef mParams;
  double particle_mass_;
  double particle_radius_;
  unsigned particle_color_;
  gl::TextureFontRef mTextureFont;
};

}  // namespace visualizer

}  // namespace idealgas
