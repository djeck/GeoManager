#ifndef MAP_MANAGER
#define MAP_MANAGER

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "view.hpp"

class MapManager
{
public:
	MapManager();
	~MapManager();
	void Print();
	void Calcul();
	void addObject(Object* arg0);
private:
	void build();
	std::vector<Object*> m_vector;
	View m_camera;
};
#endif
