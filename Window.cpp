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
    
    m_map=new MapManager(); // always before
	
	
    m_listener = new EventManager();
    m_listener->setCallback(this);

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

MapManager* Window::getMap()
{
	if(m_map!=0)
		return m_map;
	std::cout<<"Erreur acces impossible au gestionnaire de map initilisez le avant"<<std::endl;
	return 0;
}
