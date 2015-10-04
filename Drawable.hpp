#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/System/Vector3.hpp>

class Drawable
{
protected:
public:
  Drawable();
  virtual void draw();
};

#endif