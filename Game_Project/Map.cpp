#include "Map.h"
#include <iostream>
Map* Map::map = NULL;

Map::Map()
{
	loadMap("assets/map_complete.map", 50, 40);
}

Map::~Map()
{
	int size = tiles.size();
	for (int n = 0; n < size; n++)
	{
		delete tiles[n];
		tiles[n] = NULL;
	}
	tiles.clear();
}


Map * Map::getMap()
{
	if (map == NULL)
	{
		map = new Map();
	}
	return map;
}

void Map::release()
{
	delete map;
	map = NULL;
}

void Map::loadMap(const char * path, int sizeX, int sizeY)
{
	tiles.reserve(sizeX * sizeY);//���ťX�O����Ŷ�
	std::fstream mapFile;
	char tileChar;//Ū�i�Ӫ��r��
	mapFile.open(path);//�}��
	if (!mapFile)
	{
		std::cout << "failed to open file\n";
	}
	int srcX, srcY;//�ӷ���x�y�ЩMy�y��
	for (int row = 0; row < sizeY; row++)
	{
		for (int col = 0; col < sizeX; col++)
		{
			tileChar = mapFile.get();//Ūy�y��
			srcY = atoi(&tileChar) * 16;
			tileChar = mapFile.get();//Ūx�y��
			srcX = atoi(&tileChar) * 16;
			tiles.emplace_back(addTile(srcX, srcY, col * 32, row * 32));//�إ�Tile
			mapFile.ignore();//�����U�@�Ӧr��(�Ů�)
		}
	}
	mapFile.close();//����
}

void Map::drawMap()
{
	for (unsigned int n = 0; n < tiles.size(); n++)
	{
		Graphics::getGraphics()->draw(tiles[n]->getTex(), &tiles[n]->getSrc(), &tiles[n]->getDest());
	}
}

Tile* Map::addTile(int srcX, int srcY, int destX, int destY)
{
	Tile* tile = new Tile(srcX, srcY, destX, destY, "assets/tiles_new.png");
	return tile;
}

void Map::updateMap()
{
	for (int n = 0; n < tiles.size(); n++)
	{
		tiles[n]->updateTilePos();
	}
}
