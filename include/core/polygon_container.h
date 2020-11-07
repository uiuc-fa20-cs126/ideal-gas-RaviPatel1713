#pragma  once
#include "cinder/gl/gl.h"

namespace ideal_gas{
using glm::vec2;
class PolygonContainer{
public:
  virtual void Draw() = 0;
  virtual void MoveCentroidTo(const vec2 &c) = 0;
  virtual void AddParticles(const vec2 &c) = 0;
  virtual void Update() = 0;
protected:
  const vec2 centroid_;
  double polygon_radius_;
};


}