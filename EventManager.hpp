#ifndef EVENT_MANAGER
#define EVENT_MANAGER

#include <SFML/Graphics.hpp>
#include "MapManager.hpp"

class Window;

class EventManager
{
public:
	EventManager();
	void setCallback(Window* window);
	void run(sf::Event event);
private:
	void mouseMove(int x,int y);
	void build();
	void close();
	Window* m_ptrWindow;
	MapManager* m_ptrMap;
};


#endif
