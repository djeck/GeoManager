#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/System/Vector3.hpp>

class Drawable
{
protected:
public:
  Drawable();
  virtual void setSelected(bool select);
  virtual bool isSelected();
  virtual void draw();
};

#endif