#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "MapManager.hpp"
#include "EventManager.hpp"
#include "Physical.hpp"
#include "view.hpp"
#include "Object.hpp"
#include "view.hpp"

class Window : public sf::RenderWindow
{
public:
	Window(sf::VideoMode mode,std::string str);
     ~Window();
	void start();
private:
	void build();
	EventManager* m_listener;
	MapManager* m_map;
};
#endif
