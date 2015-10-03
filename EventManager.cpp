#include "EventManager.hpp"

EventManager::EventManager()
{
	build();
}

void EventManager::build()
{

}

void EventManager::setCloseCallback(void (*callback)() )
{
	m_callback=callback;
}

void EventManager::run(sf::Event event)
{
	
	if (event.type == sf::Event::Resized)
     {
          glViewport(0, 0, event.size.width, event.size.height);
     }
     else if (event.type == sf::Event::Closed)
     {
		m_callback();
     }
     else if(event.key.code == sf::Keyboard::Escape)
	{
		m_callback();
	}
	else if(event.type == sf::Event::KeyPressed)
	{
	      switch(event.key.code)
	      {
		case sf::Keyboard::A :
		  player.setRotationMV(sf::Vector3f(0,25,50));
		  break;
		case sf::Keyboard::S :
		  camera.setVitesseFlying(sf::Vector3f(0,0,-3));
		  break;
		case sf::Keyboard::Z :
		  camera.setVitesseFlying(sf::Vector3f(0,0,3));
		  break;
		case sf::Keyboard::Q :
		  camera.setVitesseFlying(sf::Vector3f(3,0,0));
		  break;
		case sf::Keyboard::D :
		  camera.setVitesseFlying(sf::Vector3f(-3,0,0));
		  break;
		case sf::Keyboard::E:
		  player.setVitesse(sf::Vector3f(-3,0,0));
		  player2.setVitesse(sf::Vector3f(3,0,0));
		break;
	      }
	}
}
