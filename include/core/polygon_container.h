#pragma  once
#include "cinder/gl/gl.h"

namespace idealgas{
using glm::vec2;
class PolygonContainer{
public:
  virtual void Draw() const;
  virtual void MoveCentroidTo(const vec2 &c);
  virtual void AddParticles(const vec2 &c);
  virtual void Update();
};
}