#include "MapManager.hpp"

MapManager::MapManager()
{
	build();
}

MapManager::~MapManager()
{
	for(std::vector<Object*>::iterator it= m_vector.begin();it!=m_vector.end();it++)
	{
		delete(*it);
	}
}

void MapManager::build()
{
    m_camera.setPosition(sf::Vector3f(0,30,0));
}

void MapManager::addObject(Object* arg0)
{
	m_vector.push_back(arg0);
}
void MapManager::Print()
{
	m_camera.init();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

     glMatrixMode( GL_MODELVIEW );
      
     glLoadIdentity( );
	 
	
	
	for(std::vector<Object*>::iterator it= m_vector.begin();it!=m_vector.end();it++)
	{
		(*it)->draw();
	}
	
}

void MapManager::Calcul()
{
	for(std::vector<Object*>::iterator it= m_vector.begin();it!=m_vector.end();it++)
	{
		(*it)->calcul();
	}
	m_camera.calcul();
}
