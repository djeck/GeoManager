#ifndef MESH_HPP
#define MESH_HPP

#include <iostream>
#include <SFML/OpenGL.hpp>

#include "Drawable.hpp"


#define PERSO_SIZE 6
#define PERSO_N_PARAM 3

class Mesh : public Drawable
{
public:
  Mesh();
  Mesh(sf::Vector3f pos);
  ~Mesh();
  void draw(sf::Vector3f position,sf::Vector3f rotation);
private:
  GLuint m_index;
  void transformShape();

};

#endif