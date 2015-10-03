#include "Window.hpp"

Window::Window(sf::VideoMode mode,std::string str) : sf::RenderWindow(mode,str)
{
	build();
}

void Window::build()
{
    setVerticalSyncEnabled(true);
    setActive(true);
    setFramerateLimit(50);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_TEXTURE_3D);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    
    m_listener = new EventManager();
    m_listener->setCloseCallback(this);
    m_map=new MapManager();
    
    m_map->addObject(new Object());// test

}

Window::~Window()
{
	delete m_listener;
	delete m_map;
}

void Window::start()
{
	while (isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
        {
            m_listener->run(event);
        }
      m_map->Calcul();
	 m_map->Print();
	 
      glFlush();
      display();
      
    }
}

