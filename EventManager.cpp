#include "EventManager.hpp"

EventManager::EventManager()
{
	build();
}

void EventManager::build()
{

}

void EventManager::setCloseCallback(sf::RenderWindow* window )
{
	m_ptrWindow=window;
}

void EventManager::run(sf::Event event)
{
	
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
}
void EventManager::close()
{
	m_ptrWindow->close();
}
