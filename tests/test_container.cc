#include <catch2/catch.hpp>

#include <core/container.h>
#include "cinder/gl/gl.h"
#include "core/ideal_gas_app_config.h"
using namespace idealgas;
using glm::vec2;
TEST_CASE("Standard rectangular container constructor",
          "[standard][constructor]") {
  vec2 centroid(100, 100);
  // radius length is from centroid to any vertex of a regular polygon
  double polygon_radius = 141.421f; // in order to get side length of 200
  Container rect_container(centroid, polygon_radius);

  REQUIRE(Approx(rect_container.GetCentroid().x) == centroid.x);
  REQUIRE(Approx(rect_container.GetCentroid().y) == centroid.y);
  REQUIRE(Approx(rect_container.GetPolygonRadius())
          == polygon_radius);
  REQUIRE(rect_container.GetShape() == standard_config::kSQUARE);
  REQUIRE(rect_container.GetPolygonVertices().size() == 4);
  REQUIRE(rect_container.GetParticlesVec().size() == 0);


  SECTION("container vertices check""[vertices-check]"){
    vec2 vertex = {200, 0};
    REQUIRE(Approx(rect_container.GetPolygonVertices()[0].x) == vertex.x);
    REQUIRE(rect_container.GetPolygonVertices()[0].y == Approx(vertex.y));

    vertex = {0, 0};
    REQUIRE(Approx(rect_container.GetPolygonVertices()[1].x) == vertex.x);
    REQUIRE(Approx(rect_container.GetPolygonVertices()[1].y) == vertex.y);

    vertex = {0, 200};
    REQUIRE(Approx(rect_container.GetPolygonVertices()[2].x) == vertex.x);
    REQUIRE(Approx(rect_container.GetPolygonVertices()[2].y) == vertex.y);
    vertex = {200, 200};
    REQUIRE(Approx(rect_container.GetPolygonVertices()[3].x) == vertex.x);
    REQUIRE(Approx(rect_container.GetPolygonVertices()[3].y) == vertex.y);

  }

}
