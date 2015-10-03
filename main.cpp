#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

#include "Physical.hpp"
#include "personne.hpp"
#include "view.hpp"

int main()
{
  

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    window.setFramerateLimit(50);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_TEXTURE_3D);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    
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
            if (event.type == sf::Event::Resized)
            {
                glViewport(0, 0, event.size.width, event.size.height);
            }
            else if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.key.code == sf::Keyboard::Escape)
	    {
	      window.close();
	    }
	    else if(event.type == sf::Event::KeyPressed)
	    {
	      switch(event.key.code)
	      {
		case sf::Keyboard::A :
		  player.setRotationMV(sf::Vector3f(0,25,50));
		  break;
		case sf::Keyboard::S :
		  camera.setVitesseFlying(sf::Vector3f(0,0,-3));
		  break;
		case sf::Keyboard::Z :
		  camera.setVitesseFlying(sf::Vector3f(0,0,3));
		  break;
		case sf::Keyboard::Q :
		  camera.setVitesseFlying(sf::Vector3f(3,0,0));
		  break;
		case sf::Keyboard::D :
		  camera.setVitesseFlying(sf::Vector3f(-3,0,0));
		  break;
		case sf::Keyboard::E:
		  player.setVitesse(sf::Vector3f(-3,0,0));
		  player2.setVitesse(sf::Vector3f(3,0,0));
		break;
	      }
	    }
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
