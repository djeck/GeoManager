#include "MapManager.hpp"

MapManager::MapManager()
{
	m_camera=new View();
	build();
}

MapManager::~MapManager()
{
	for(std::vector<Object*>::iterator it= m_vector.begin();it!=m_vector.end();it++)
	{
		delete(*it);
	}
	
	delete m_camera;
}

void MapManager::build()
{
    loadFromFile("../map.txt");
}

void MapManager::addObject(Object* arg0)
{
	m_vector.push_back(arg0);
}
void MapManager::Print()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

     glMatrixMode( GL_MODELVIEW );
      
     glLoadIdentity( );
	 
	m_camera->init();
	
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
	m_camera->calcul();
}

Map* MapManager::getPtrMap()
{
	return &m_vector;
}

void MapManager::loadFromFile(std::string path)
{
	FILE * file = fopen(path.c_str(), "r");
	
	if( file == NULL )
	{
		std::cout<<"Impossible to open the file: "<<path<<std::endl;
		return;
	}
	while( 1 )
	{
 
		char lineHeader[128];
   
		int res = fscanf(file, "%s", lineHeader); // read word of the line
		if (res == EOF)
			break; // EOF = End Of File: end of loop
			
		if ( strcmp( lineHeader, "o" ) == 0 ) // object
		{
			sf::Vector3f position;
			fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z );
			addObject(new Object(position));
			std::cout<<"added object in "<<position.x<<" - "<<position.y<<" - "<<position.z<<std::endl;
		}
		else if ( strcmp( lineHeader, "c" ) == 0 )
		{
			sf::Vector3f position;
			fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z );
			m_camera->setPosition(position);
		}
		
	}// end of loop
}

View* MapManager::getCamera()
{
	return m_camera;
}



