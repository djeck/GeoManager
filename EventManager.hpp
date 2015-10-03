#ifndef EVENT_MANAGER
#define EVENT_MANAGER

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class EventManager
{
public:
	EventManager();
	void setCloseCallback(sf::RenderWindow* window);
	void run(sf::Event event);
private:
	void build();
	void close();
	sf::RenderWindow* m_ptrWindow;
	
};
#endif
