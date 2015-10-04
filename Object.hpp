#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <SFML/OpenGL.hpp>
#include "Physical.hpp"


class Object : public Physical
{
protected:

  sf::Vector3f m_rotation;
  sf::Vector3f m_drotation;
  sf::Vector3f m_ddrotation;
  
  sf::Clock m_clock;
  sf::Time m_elapsed;
  bool m_selected;
  
  int m_id;
public:
  Object();
  Object(sf::Vector3f pos);
  ~Object();
  
  void calcul();// calcul speed and position...
  
  void setRotation(sf::Vector3f rotation);
  void setRotationMV(sf::Vector3f rotation);
  void setRotationMVAcc(sf::Vector3f rotation);
  sf::Vector3f getRotation();
  
  bool isSelected();
  void setSelected(bool select);
  
  int getId();
  void setId(int id);
};

#endif
