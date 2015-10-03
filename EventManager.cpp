#include "EventManager.hpp"
#include "Window.hpp"

EventManager::EventManager()
{
	build();
}

void EventManager::build()
{
}

void EventManager::setCallback(Window* window )
{
	m_ptrWindow=window;
	m_ptrMap=m_ptrWindow->getMap();
}

void EventManager::run(sf::Event event)
{
	sf::Vector3f initial;
	if (event.type == sf::Event::Resized)
     {
          glViewport(0, 0, event.size.width, event.size.height);
     }
     else if (event.type == sf::Event::Closed)
     {
		close();
     }
     else if(event.key.code == sf::Keyboard::Escape)
	{
		close();
	}
	else if(event.type == sf::Event::KeyPressed)
	{
	      switch(event.key.code)
	      {
		case sf::Keyboard::A :
		  break;
		case sf::Keyboard::S :
		  break;
		case sf::Keyboard::Z :
		  break;
		case sf::Keyboard::Q :
		  break;
		case sf::Keyboard::D :
		  break;
		case sf::Keyboard::E:
		break;
	      }
	}
	else if(event.type == sf::Event::MouseMoved)
	{
			mouseMove(event.mouseMove.x,event.mouseMove.y);
	}
}

void EventManager::close()
{
		m_ptrWindow->close();
}

void EventManager::mouseMove(int x, int y)
{
	
	if(y<100)//upper part of the screen
	{
		m_ptrMap->getCamera()->setVitesseFlying(sf::Vector3f(0,0,10));
	}
	else if(y>m_ptrWindow->getSize().y-100) // lower
	{
		m_ptrMap->getCamera()->setVitesseFlying(sf::Vector3f(0,0,-10));
	}
	else if(x<100) //right
	{
		m_ptrMap->getCamera()->setVitesseFlying(sf::Vector3f(10,0,0));
	}
	else if(x>m_ptrWindow->getSize().x-100) //left
	{
		m_ptrMap->getCamera()->setVitesseFlying(sf::Vector3f(-10,0,0));
	}
	else
	{
		m_ptrMap->getCamera()->setVitesseFlying(sf::Vector3f(0,0,0));
	}
}
