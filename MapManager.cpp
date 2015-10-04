#include "MapManager.hpp"

MapManager::MapManager()
{
	m_camera=new View();
	build();
}

MapManager::~MapManager()
{
	for(Map::iterator it= m_vector.begin();it!=m_vector.end();it++)
	{
		delete(*it);
	}
	
	for(int i = 0;i<m_mesh.size();i++)
	{
		delete(m_mesh.at(i));
	}
	
	delete m_camera;
}

void MapManager::build()
{
    loadFromFile("../map.txt");
    
    //test
    m_mesh[0]=new Mesh();
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
		Object* objet=*it;
		if(m_mesh.find(objet->getId())!=m_mesh.end())
			m_mesh[objet->getId()]->draw(objet->getPosition(),objet->getRotation());
		else
			std::cout<<"impossible de trouver le mesh pour l'objet "<<objet->getId()<<std::endl;
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
			int kind;
			fscanf(file, "%d %f %f %f\n", &kind, &position.x, &position.y, &position.z );
			Object *obj = new Object(position);
			obj->setId(kind);
			addObject(obj);
			std::cout<<"added object in "<<position.x<<" - "<<position.y<<" - "<<position.z<<std::endl;
		}
		else if ( strcmp( lineHeader, "c" ) == 0 )
		{
			sf::Vector3f position;
			fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z );
			m_camera->setPosition(position);
			std::cout<<"set camera in "<<position.x<<" - "<<position.y<<" - "<<position.z<<std::endl;
		}
		
	}// end of loop
}

View* MapManager::getCamera()
{
	return m_camera;
}

void MapManager::addMesh(int id,Mesh* arg0)
{
	if(m_mesh.find(id)==m_mesh.end())
		m_mesh[id]=arg0;
}


drawable* MapManager::getPtrMesh()
{
	return &m_mesh;
}

