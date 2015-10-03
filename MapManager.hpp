#ifndef MAP_MANAGER
#define MAP_MANAGER

#include <SFML/Graphics.hpp>
#include "personne.hpp"

class MapManager
{
public:
	MapManager();
	~MapManager();
private:
	void build();
	std::vector<Personne> m_vector;
};
#endif
