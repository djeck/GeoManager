#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <SFML/OpenGL.hpp>
#include "Physical.hpp"
#include "Drawable.hpp"


#define PERSO_SIZE 6
#define PERSO_N_PARAM 3

class Object : public Drawable , public Physical
{
private:

  sf::Vector3f m_rotate;
  sf::Vector3f m_drotate;
  sf::Vector3f m_ddrotate;
  
  sf::Clock m_clock;
  sf::Time m_elapsed;
  GLuint m_index;
  bool m_selected;
  void transformShape();
public:
  Object();
  Object(sf::Vector3f pos);
  ~Object();
  void draw();
  
  void setRotation(sf::Vector3f rotation);
  void setRotationMV(sf::Vector3f rotation);
  void setRotationMVAcc(sf::Vector3f rotation);
  bool isSelected();
  void setSelected(bool select);
  
  sf::Vector3f getRotation();
  void calcul();
};

#endif
