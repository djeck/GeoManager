#ifndef VIEW_HPP
#define VIEW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/OpenGL.hpp>
#include "Physical.hpp"

class View : public Physical
{
private:
  sf::Vector3f m_targetPosition;
  sf::Vector3f m_dtargetPosition;
  
  void varInit();
  
  sf::Clock m_clock;
  sf::Time m_elapsed;
public:
  View();
  View(sf::Vector3f position);

  void setTarget(sf::Vector3f target);
  sf::Vector3f gettarget();
  void init();
  
  void setVitesseFlying(sf::Vector3f vitesse);
  void calcul();
  
};

#endif