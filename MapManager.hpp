#ifndef MAP_MANAGER
#define MAP_MANAGER

#include <stdio.h>
#include <string.h>
#include "Object.hpp"
#include "view.hpp"

typedef std::vector<Object*> Map;

class MapManager
{
public:
	MapManager();
	~MapManager();
	void Print();
	void Calcul();
	void addObject(Object* arg0);
	Map* getPtrMap();
	View* getCamera();
	
private:
	void build();
	Map m_vector;
	View *m_camera;
	void loadFromFile(std::string path);
};
#endif
