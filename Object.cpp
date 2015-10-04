#include "Object.hpp"

Object::Object()
{
	  m_id=0;//nothing by default
}

Object::Object(sf::Vector3f pos)
{
	  m_position=pos;
}

Object::~Object()
{
	
}
  
void Object::calcul()
{
	m_elapsed = m_clock.restart();
  
	m_dposition += m_ddposition*m_elapsed.asSeconds();
	m_position += m_dposition*m_elapsed.asSeconds();
	
	m_drotation += m_ddrotation*m_elapsed.asSeconds();
	m_rotation += m_drotation*m_elapsed.asSeconds();
}
  
void Object::setRotation(sf::Vector3f rotation)
{
	m_rotation=rotation;
}

void Object::setRotationMV(sf::Vector3f rotation)
{
	m_drotation=rotation;
}

void Object::setRotationMVAcc(sf::Vector3f rotation)
{
	m_ddrotation=rotation;
}

sf::Vector3f Object::getRotation()
{
	return m_rotation;
}
  
bool Object::isSelected()
{
	return m_selected;
}

void Object::setSelected(bool select)
{
	m_selected=select;
}

int Object::getId()
{
	return m_id;
}

void Object::setId(int id)
{
	m_id=id;
}
