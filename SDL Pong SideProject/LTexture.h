#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "GameSystem.h"

class LTexture
{
public:
	LTexture();
	static SDL_Texture* LoadTexture(const std::string& file_path, SDL_Renderer* Renderer);
	static void Draw(SDL_Renderer* Renderer, SDL_Texture* tex, SDL_Rect &dst);
	static void Draw(SDL_Renderer* Renderer, SDL_Rect &src, SDL_Texture* tex, SDL_Rect &dst);
	static void Free(SDL_Surface* Surface);
};

#endif //LTEXTURE_H