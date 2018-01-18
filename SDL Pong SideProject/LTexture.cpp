#include "LTexture.h"



LTexture::LTexture()
{
}

SDL_Texture * LTexture::LoadTexture(const std::string & file_path, SDL_Renderer * Renderer)
{
	SDL_Surface* TempSurface = IMG_Load(file_path.c_str());
	SDL_Texture* NewTexture = SDL_CreateTextureFromSurface(Renderer, TempSurface);
	Free(TempSurface);

	return NewTexture;
}

void LTexture::Draw(SDL_Renderer* Renderer, SDL_Texture* tex, SDL_Rect &dst)
{
	SDL_RenderCopy(Renderer, tex, nullptr, &dst);
}

void LTexture::Draw(SDL_Renderer* Renderer, SDL_Rect &src, SDL_Texture* tex, SDL_Rect &dst)
{
	SDL_RenderCopy(Renderer, tex, &src, &dst);
}

void LTexture::Draw(SDL_Renderer * Renderer, SDL_Rect dst)
{
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(Renderer, &dst);
}

void LTexture::Free(SDL_Surface* Surface)
{
	SDL_FreeSurface(Surface);
}