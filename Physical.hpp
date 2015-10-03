#ifndef PHYSICAL_HPP
#define PHYSICAL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>

class Physical
{

public:
  Physical();
  void setPosition(sf::Vector3f position);
  void setVitesse(sf::Vector3f position);
  void setAcceleration(sf::Vector3f position);

  sf::Vector3f getPosition();
  sf::Vector3f getVitesse();
  sf::Vector3f getAcceleration();

  void calcul();
  
  protected:
    
  sf::Vector3f m_position;
  sf::Vector3f m_dposition;
  sf::Vector3f m_ddposition;
  
  sf::Clock m_clock;
  sf::Time m_elapsed;
};

#endif
