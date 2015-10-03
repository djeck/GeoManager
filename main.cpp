#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

#include "MapManager.hpp"
#include "EventManager.hpp"
#include "Physical.hpp"
#include "personne.hpp"
#include "view.hpp"

int main()
{
  
    sf::RenderWindow window(sf::VideoMode(800, 600), "GeoManager");
    
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    window.setFramerateLimit(50);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_TEXTURE_3D);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    
    EventManager manager;
    manager.m_callback(window.close());
    
    Personne player;
    
    Personne player2;
    player2.setPosition(sf::Vector3f(10,10,0));
    
    View camera;
    camera.setPosition(sf::Vector3f(0,50,0));
    
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            manager.run(event);
        }
	
	
      player.calcul();
      player2.calcul();
      camera.calcul();
	
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

      glMatrixMode( GL_MODELVIEW );
      
      glLoadIdentity( );
      
      camera.init();
      
      player.draw();
      player2.draw();
      
      
      glFlush();
      window.display();
      
    }

    return 0;
}
