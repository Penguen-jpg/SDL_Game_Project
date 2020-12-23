#pragma once
#include <fstream>
#include <vector>
#include "Tile.h"
class Map
{
	public:
		static Map* getMap();
		void release();
		void loadMap(const char* path ,int sizeX, int sizeY);//讀取地圖(tileset)
		void drawMap();//畫出地圖
		Tile* addTile(int srcX, int srcY, int destX, int destY);//加入一個tile
		void updateMap();//更新地圖位置
	private:
		Map();
		~Map();

		static Map* map;//地圖
		std::vector<Tile*> tiles;//儲存tile
};