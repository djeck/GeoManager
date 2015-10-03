#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

#include "Window.hpp"
#include "Object.hpp"
#include "MapManager.hpp"
#include "EventManager.hpp"
#include "Physical.hpp"
#include "view.hpp"

int main()
{
	Window window(sf::VideoMode(800, 600), "GeoManager");
	window.start();

    return 0;
}
