//
// Created by Ravi Patel on 11/7/20.
//
#include <core/sqr_container.h>

namespace idealgas {
using glm::vec2;
using cinder::Path2d;
#define PI 3.14159265
SqrContainer::SqrContainer(const vec2 &centroid, const double polygon_radius)
    : centroid_(centroid), polygon_radius_(polygon_radius){
//  double current_degree = -PI/2;
  double current_degree = 2*PI - PI/4;

  for(unsigned i = 0; i < 4; ++i){
    vec2 vertex(cos(current_degree) * (polygon_radius_),
                sin(current_degree) * (polygon_radius_));
    vertex += centroid;
    polygon_vertices_.push_back(vertex);
    current_degree -= 2*PI/4;
  }
}

void SqrContainer::Draw() const {
  Path2d mPath;
  mPath.moveTo( polygon_vertices_[0] );
  for(unsigned i = 1; i < 4; ++i){
    mPath.lineTo( polygon_vertices_[i] );
  }
  mPath.close();
  ci::gl::color(ci::Color("black"));
  ci::gl::draw( mPath );
}

void SqrContainer::AddParticles(const vec2 &c) {

}

void SqrContainer::Update() {}

}