#include "Physical.hpp"

Physical::Physical()
{
  m_position.x=0;
  m_position.y=0;
  m_position.z=0;
  m_dposition.x=0;
  m_dposition.y=0;
  m_dposition.z=0;
  m_ddposition.x=0;
  m_ddposition.y=0;
  m_ddposition.z=0;
}

void Physical::setPosition(sf::Vector3f position)
{
  m_position=position;
}

void Physical::setVitesse(sf::Vector3f position)
{
  m_dposition=position;
}

void Physical::setAcceleration(sf::Vector3f position)
{
  m_ddposition=position;
}

void Physical::calcul()
{
  m_elapsed = m_clock.restart();
  
  m_dposition += m_ddposition*m_elapsed.asSeconds();
  m_position += m_dposition*m_elapsed.asSeconds();

}

sf::Vector3f Physical::getPosition()
{
  return m_position;
}

sf::Vector3f Physical::getVitesse()
{
  return m_dposition;
}

sf::Vector3f Physical::getAcceleration()
{
  return m_ddposition;
}