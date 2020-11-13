#include <catch2/catch.hpp>

#include <visualizer/simulator.h>

using idealgas::visualizer::Simulator;

//TEST_CASE("valid wall collisions with particle moving towards the wall") {
//  Simulator simulator = Simulator(glm::vec2(0, 0),
//                                  200);
//  // moving horizontally towards left wall
//  simulator.AddParticles(glm::vec2(0, 5),
//                         glm::vec2(-5, 0));
//  // moving in a positive sloped manner towards left wall
//  simulator.AddParticles(glm::vec2(0, 130),
//                         glm::vec2(-5, 5));
//  // moving in a negative sloped manner towards left wall
//  simulator.AddParticles(glm::vec2(0, 100),
//                         glm::vec2(-5, -5));
//
//  // moving horizontally towards right wall
//  simulator.AddParticles(glm::vec2(200, 5),
//                         glm::vec2(5, 0));
//  // moving in a positive sloped manner towards right wall
//  simulator.AddParticles(glm::vec2(200, 130),
//                         glm::vec2(5, 5));
//  // moving in a negative sloped manner towards right wall
//  simulator.AddParticles(glm::vec2(200, 100),
//                         glm::vec2(5, -5));
//
//
//  // moving vertically towards top wall
//  simulator.AddParticles(glm::vec2(50, 0),
//                         glm::vec2(0, -5));
//  // moving in a positive sloped manner towards top wall
//  simulator.AddParticles(glm::vec2(100, 0),
//                         glm::vec2(5, -5));
//  // moving in a negative sloped manner towards top wall
//  simulator.AddParticles(glm::vec2(130, 0),
//                         glm::vec2(-5, -5));
//
//  // moving vertically towards bottom wall
//  simulator.AddParticles(glm::vec2(50, 200),
//                         glm::vec2(0, 5));
//  // moving in a positive sloped manner towards bottom wall
//  simulator.AddParticles(glm::vec2(100, 200),
//                         glm::vec2(-5, 5));
//  // moving in a negative sloped manner towards bottom wall
//  simulator.AddParticles(glm::vec2(130, 200),
//                         glm::vec2(5, 5));
//
//
//
//  simulator.UpdateParticlePosition(); // one frame iteration
//
//  SECTION("left wall"){
//    SECTION("particle moving horizontally"){
//      glm::vec2 result_vel = glm::vec2(5, 0);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(0).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(0).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in positive sloped manner"){
//      glm::vec2 result_vel = glm::vec2(5, 5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(1).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(1).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in negative sloped manner"){
//      glm::vec2 result_vel = glm::vec2(5, -5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(2).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(2).vel_.y) == result_vel.y);
//    }
//
//  }
//  SECTION("right wall"){
//    SECTION("particle moving horizontally") {
//      glm::vec2 result_vel = glm::vec2(-5, 0);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(3).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(3).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in positive sloped manner"){
//      glm::vec2 result_vel = glm::vec2(-5, 5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(4).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(4).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in negative sloped manner"){
//      glm::vec2 result_vel = glm::vec2(-5, -5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(5).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(5).vel_.y) == result_vel.y);
//    }
//  }
//  SECTION("top wall"){
//    SECTION("particle moving vertically"){
//      glm::vec2 result_vel = glm::vec2(0, 5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(6).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(6).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in positive sloped manner"){
//      glm::vec2 result_vel = glm::vec2(5, 5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(7).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(7).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in negative sloped manner"){
//      glm::vec2 result_vel = glm::vec2(-5, 5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(8).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(8).vel_.y) == result_vel.y);
//    }
//  }
//  SECTION("bottom wall"){
//    SECTION("particle moving vertically"){
//      glm::vec2 result_vel = glm::vec2(0, -5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(9).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(9).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in a positive sloped manner"){
//      glm::vec2 result_vel = glm::vec2(-5, -5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(10).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(10).vel_.y) == result_vel.y);
//    }
//    SECTION("particle moving in a negative sloped manner"){
//      glm::vec2 result_vel = glm::vec2(5, -5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(11).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(11).vel_.y) == result_vel.y);
//    }
//
//  }
//}
//
//TEST_CASE("two particle collision") {
//  Simulator simulator = Simulator(glm::vec2(0,0),
//                                  200);
//  // horizontally moving particles towards each other
//  simulator.AddParticles(glm::vec2(100, 100), glm::vec2(5, 0));
//  simulator.AddParticles(glm::vec2(105, 100), glm::vec2(-5, 0));
//
//  // horizontally moving in same direction with left particle(higher velocity)
//  // colliding with right particle (lower velocity)
//  simulator.AddParticles(glm::vec2(100, 130), glm::vec2(5, 0));
//  simulator.AddParticles(glm::vec2(105, 130), glm::vec2(4, 0));
//
//  // vertically moving particles towards each other
//  simulator.AddParticles(glm::vec2(180, 180), glm::vec2(0, 5));
//  simulator.AddParticles(glm::vec2(180, 185), glm::vec2(0, -5));
//
//  // vertically moving in same direction with top particle(higher velocity)
//  // colliding with bottom particle (lower velocity)
//  simulator.AddParticles(glm::vec2(180, 130), glm::vec2(0, 5));
//  simulator.AddParticles(glm::vec2(180, 135), glm::vec2(0, 4));
//
//  simulator.UpdateParticlePosition(); // one frame iteration
//  SECTION("particle collision moving horizontally"){
//    SECTION("particles moving towards each other"){
//      glm::vec2 result_vel = glm::vec2(-5, 0);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(0).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(0).vel_.y) == result_vel.y);
//      result_vel = glm::vec2(5, 0);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(1).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(1).vel_.y) == result_vel.y);
//    }
//    SECTION("particles moving in the same direction with differing velocities"){
//      glm::vec2 result_vel = glm::vec2(4, 0);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(2).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(2).vel_.y) == result_vel.y);
//      result_vel = glm::vec2(5, 0);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(3).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(3).vel_.y) == result_vel.y);
//    }
//  }
//  SECTION("particle collision moving vertically"){
//    SECTION("particles moving towards each other"){
//      glm::vec2 result_vel = glm::vec2(0, -5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(4).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(4).vel_.y) == result_vel.y);
//      result_vel = glm::vec2(0, 5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(5).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(5).vel_.y) == result_vel.y);
//    }
//    SECTION("particles moving in the same direction with differing velocities"){
//      glm::vec2 result_vel = glm::vec2(0, 4);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(6).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(6).vel_.y) == result_vel.y);
//      result_vel = glm::vec2(0, 5);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(7).vel_.x) == result_vel.x);
//      REQUIRE(Approx(simulator.GetParticlesVector().at(7).vel_.y) == result_vel.y);
//    }
//  }
//}
//
//
