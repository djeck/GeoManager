#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "EventManager.hpp"


class Window : public sf::RenderWindow
{
public:
	Window(sf::VideoMode mode,std::string str);
     ~Window();
	void start();
	MapManager* getMap(); 
private:
	void build();
	
	EventManager* m_listener;
	MapManager* m_map;
};

#endif
