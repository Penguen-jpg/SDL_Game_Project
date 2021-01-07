#include "Object.h"

Object::Object(const char *path)
	: SCALE_FACTOR(2), flip(SDL_FLIP_NONE)
{
	setTex(path);
}

Object::~Object()
{

}

void Object::draw()
{
	Graphics::getGraphics()->draw(texture, &src, &dest, flip);
}

SDL_Rect Object::getSrc() const
{
	return src;
}

SDL_Rect Object::getDest() const
{
	return dest;
}

SDL_Texture * Object::getTex() const
{
	return texture;
}

void Object::setSrc(int x, int y, int w, int h)
{
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}

void Object::setDest(int x, int y, int w, int h)
{
	dest.x = x;
	dest.y = y;
	dest.w = w * SCALE_FACTOR;
	dest.h = h * SCALE_FACTOR;
}

void Object::setTex(const char * path)
{
	texture = AssetManager::getAssetManager()->getTexture(path);
}