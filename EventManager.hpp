#ifndef EVENT_MANAGER
#define EVENT_MANAGER

#include <SFML/Graphics.hpp>
#include "personne.hpp"

class EventManager
{
public:
	EventManager();
	void setCloseCallback(void (*callback)());
	void run(sf::Event event);
	void (*m_callback)();
private:
	void build();
	
};
#endif
