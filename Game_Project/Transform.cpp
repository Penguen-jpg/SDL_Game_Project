#include "Transform.h"

Transform::Transform()
{

}

Transform::Transform(int x, int y, int w, int h)
	:position(0.0f, 0.0f) , velocity(0.0f, 0.0f)
{
	src.x = 0;
	src.y = 0;
	src.w = w;
	src.h = h;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
}

Transform::Transform(float x, float y)
	:position(x, y)
{

}
