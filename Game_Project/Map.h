#pragma once
#include <fstream>
#include <vector>
#include "Tile.h"
class Map
{
	public:
		static Map* getMap();
		void release();
		void loadMap(const char* path ,int sizeX, int sizeY);//Ū���a��(tileset)
		void drawMap();//�e�X�a��
		Tile* addTile(int srcX, int srcY, int destX, int destY);//�[�J�@��tile
		void updateMap();//��s�a�Ϧ�m
	private:
		Map();
		~Map();

		static Map* map;//�a��
		std::vector<Tile*> tiles;//�x�stile
};