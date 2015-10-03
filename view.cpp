#include "view.hpp"


View::View()
{
  varInit();
}

void View::varInit()
{
  gluPerspective(70,(double)640/480,1,1000);
  m_targetPosition.x=0;
  m_targetPosition.y=0;
  m_targetPosition.z=0;
}

View::View(sf::Vector3f position)
{
  m_position=position;
  varInit();
}

void View::init()
{
  gluLookAt(m_position.x,m_position.y,m_position.z,
	    m_targetPosition.x,m_targetPosition.y,m_targetPosition.z,0,0,1);
}

void View::setTarget(sf::Vector3f target)
{
  m_targetPosition=target;
}

sf::Vector3f View::gettarget()
{
  return m_targetPosition;
}


void View::calcul()
{
  m_elapsed = m_clock.restart();
  
  m_dposition += m_ddposition*m_elapsed.asSeconds();
  m_position += m_dposition*m_elapsed.asSeconds();
  
  m_targetPosition += m_dtargetPosition*m_elapsed.asSeconds();
  
}

void View::setVitesseFlying(sf::Vector3f vitesse)
{
  m_dposition=vitesse;
  m_dtargetPosition=vitesse;
}

