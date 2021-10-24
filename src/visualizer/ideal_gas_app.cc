#include <visualizer/ideal_gas_app.h>

namespace idealgas {
namespace visualizer {
IdealGasApp::IdealGasApp()
    : simulator_(standard_config::kWindowWidth,
                 standard_config::kWindowHeight,
//                glm::vec2
//                 ( standard_config::kMargin, standard_config::kMargin ),
                 standard_config::kContainerSize ),

      particle_mass_(particle_config::kMinMass),
      particle_radius_(particle_config::kMinRadius),
      particle_color_(0){
  ci::app::setWindowSize((int) standard_config::kWindowWidth,
                         (int) standard_config::kWindowHeight);
}

void IdealGasApp::setup() {
  mTextureFont = gl::TextureFont::create( Font( "BigCaslon-Medium", 40 ) );
  mParams = ci::params::InterfaceGl::create(
      getWindow(), "App parameters", ci::app::toPixels(ci::ivec2(200, 400)));

  mParams->addText("Container Settings");

  mParams->addButton("Triangular", [&]() { simulator_.ChangeContainer(3); });
  mParams->addButton("Rectangular (standard)",
                     [&]() { simulator_.ChangeContainer(4); });
  mParams->addButton("Pentagonal", [&]() { simulator_.ChangeContainer(5); });
  mParams->addButton("Hexagonal", [&]() { simulator_.ChangeContainer(6); });

  mParams->addSeparator();

  mParams->addText("Particle Settings");
  mParams->addParam("mass", &particle_mass_)
      .min(10.0f)
      .max(40.0f)
      .precision(2)
      .step(0.1f);
  mParams->addParam("radius", &particle_radius_)
      .min(4.0f)
      .max(10.0f)
      .precision(2)
      .step(0.1f);
  mParams->addButton("Red", [&]() { particle_color_ = 0; });
  mParams->addButton("Blue", [&]() { particle_color_ = 1; });
  mParams->addButton("Green", [&]() { particle_color_ = 2; });

  mParams->addSeparator();

  mParams->addButton("PAUSE/UNPAUSE", [&]() { is_paused = !is_paused; });
  mParams->addButton("RESET", [&](){
    simulator_.Clear();
    particle_mass_ = particle_config::kMinMass;
    particle_radius_ = particle_config::kMinRadius;
    particle_color_ = 0;
  });
}

void IdealGasApp::draw() {
  ci::Color8u background_color(255,246,148);  // light yellow
  ci::gl::clear(background_color);

  // draws the app title
  vec2 offset = vec2( 450, standard_config::kMargin );
  Rectf boundsRect( getWindowWidth()/2 - 180, mTextureFont->getAscent(),
                    getWindowWidth(),
                    getWindowHeight());
  gl::color( Color(kRED) );
  mTextureFont->drawStringWrapped( standard_config::kAppTitle, boundsRect);

  simulator_.Draw();
  mParams->draw();
}

void IdealGasApp::update() {
  if (!is_paused){ simulator_.UpdateSimulation(); }
}



void IdealGasApp::keyDown(ci::app::KeyEvent event) {
  if( event.getCode() == ci::app::KeyEvent::KEY_SPACE ) {
    simulator_.AddParticlesToContainer(particle_mass_,
                                       particle_radius_,
                                       particle_color_);
  }
}
}  // namespace visualizer

}  // namespace idealgas
