#ifndef MAP_MANAGER
#define MAP_MANAGER

#include <stdio.h>
#include <string.h>
#include "Object.hpp"
#include "Mesh.hpp"
#include "view.hpp"

typedef std::vector<Object*> Map;
typedef std::map<int,Mesh*> drawable;

class MapManager
{
public:
	MapManager();
	~MapManager();
	void Print();
	void Calcul();
	void addObject(Object* arg0);
	void addMesh(int id,Mesh* arg0);
	Map* getPtrMap();
	drawable* getPtrMesh();
	View* getCamera();
	
private:
	void build();
	Map m_vector;
	drawable m_mesh;
	View *m_camera;
	void loadFromFile(std::string path);
};
#endif
