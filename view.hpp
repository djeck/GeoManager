#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include <SFML/OpenGL.hpp>
#include "Physical.hpp"

class View : public Physical
{

public:
  View();
  View(sf::Vector3f position);

  void setTarget(sf::Vector3f target);
  sf::Vector3f gettarget();
  
  
  void setVitesseFlying(sf::Vector3f vitesse);
  void init();
  void calcul();
  
private:
    
  
  sf::Vector3f m_targetPosition;
  sf::Vector3f m_dtargetPosition;
  
  void varInit();
  
  sf::Clock m_clock;
  sf::Time m_elapsed;
};

#endif