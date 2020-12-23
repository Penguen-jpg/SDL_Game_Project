#pragma once
#include "Object.h"
#include "Vector2D.h"
class Tile :public Object
{
	public:
		Tile(int srcX, int srcY, int destX, int destY, const char* path);
		~Tile();

		void updateTilePos();//§ó·s¦ì¸m
	private:
		Vector2D position;
		static const int TILE_WIDTH = 16;
		static const int TILE_HEIGHT = 16;
};