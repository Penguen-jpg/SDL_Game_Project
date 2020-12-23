#include "Graphics.h"
Graphics* Graphics::graphics = NULL;

Graphics::Graphics()
{
	initialized = init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0);
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

Graphics * Graphics::getGraphics()
{
	if (graphics == NULL)
	{
		graphics = new Graphics();
	}
	return graphics;
}

void Graphics::release()
{
	delete graphics;
	graphics = NULL;
}

bool Graphics::init(const char * title, int x, int y, bool fullscreen)
{
	srand(time(NULL));
	int flag = fullscreen;
	if (flag == 1)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL can't be initialized!\n";
		return false;
	}
	window = SDL_CreateWindow(title, x, y, WINDOW_WIDTH, WINDOW_HEIGHT, flag);
	if (!window)
	{
		std::cout << "failed to create window!\n";
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cout << "failed to create renderer!\n";
		return false;
	}
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	if (TTF_Init() == -1)
	{
		std::cout << "TTF can't be initialized!\n";
		return false;
	}
	camera.x = 0;
	camera.y = 0;
	camera.w = WINDOW_WIDTH;
	camera.h = WINDOW_HEIGHT;
	return true;
}

bool Graphics::isInitialized() const
{
	return initialized;
}

SDL_Texture * Graphics::loadTexture(const char * path)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer, path);
	if (texture == NULL)
	{
		std::cout << "failed to load texture!\n";
		return NULL;
	}
	return texture;
}

void Graphics::draw(SDL_Texture * texture, SDL_Rect * src, SDL_Rect * dest, SDL_RendererFlip flip)
{
	//相對於鏡頭做平移
	//dest->x -= camera.x;
	//dest->y -= camera.y;

	SDL_RenderCopyEx(renderer, texture, src, dest, NULL, NULL, flip);
}

SDL_Texture * Graphics::loadTextTexture(TTF_Font * font, std::string text, SDL_Color color)
{
	SDL_Surface* surface = TTF_RenderUTF8_Solid(font, text.c_str(), color);
	if (surface == NULL)
	{
		std::cout << "failed to create surface!\n";
		return NULL;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		std::cout << "failed to create texture!\n";
		return NULL;
	}
	SDL_FreeSurface(surface);
	return texture;
}

void Graphics::moveCamera(int x, int y)
{
	camera.x = x - WINDOW_WIDTH / 2;
	camera.y = y - WINDOW_HEIGHT / 2;
	/*if (camera.x < 0)
	{
	camera.x = 0;
	}
	if (camera.y < 0)
	{
	camera.y = 0;
	}
	if (camera.x > LEVEL_WIDTH - camera.w)
	{
	camera.x = LEVEL_WIDTH - camera.w;
	}
	if (camera.y > LEVEL_HEIGHT - camera.h)
	{
	camera.y = LEVEL_HEIGHT - camera.h;
	}*/
}

void Graphics::renderClear()
{
	SDL_RenderClear(renderer);
}

void Graphics::renderPresent()
{
	SDL_RenderPresent(renderer);
}

void Graphics::fillRect(SDL_Rect* rect)
{
	SDL_RenderFillRect(renderer, rect);
}
