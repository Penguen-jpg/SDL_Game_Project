#pragma once
#include "SDL.h"
#include "Vector2D.h"
class Transform
{
	public:
		Transform();
		Transform(int x, int y, int w, int h);
		Transform(float x, float y);

		SDL_Rect src;
		SDL_Rect dest;
		Vector2D position;
		Vector2D velocity;
};