#include "Label.h"

Label::Label(std::string text, const char * path, int size, SDL_Color color, int x, int y)
{
	labelRect.x = x;
	labelRect.y = y;
	labelTexture = AssetManager::getAssetManager()->getText(text, color, path, size);
	SDL_QueryTexture(labelTexture, NULL, NULL, &labelRect.w, &labelRect.h);
}

Label::~Label()
{

}

void Label::setText(std::string text, SDL_Color color, const char * path, int size)
{
	labelTexture = AssetManager::getAssetManager()->getText(text, color, path, size);
	SDL_QueryTexture(labelTexture, NULL, NULL, &labelRect.w, &labelRect.h);
}

void Label::drawLabel()
{
	Graphics::getGraphics()->draw(labelTexture, NULL, &labelRect);
}
