#include "Tile.h"

Tile::Tile(int srcX, int srcY, int destX, int destY, const char* path)
	:position(destX, destY)
{
	SCALE_FACTOR = 2;
	setTex(path);
	setSrc(srcX, srcY, TILE_WIDTH, TILE_HEIGHT);
	setDest(destX, destY, TILE_WIDTH, TILE_HEIGHT);
}

Tile::~Tile()
{
	//SDL_DestroyTexture(texture);
}

void Tile::updateTilePos()
{
	//相對於鏡頭做平移
	dest.x = (int)position.x;
	dest.y = (int)position.y;
}

