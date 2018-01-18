#ifndef LMUSIC_H
#define LMUSIC_H

#include "GameSystem.h"

class LMusic
{
public:
	LMusic();
	static void PlayChunk(Mix_Chunk* Chunk);
	static void PlayMusic(Mix_Music* Music);
	static Mix_Music* LoadMusic(Mix_Music* Music, const std::string file_path);
	static Mix_Chunk* LoadChunk(Mix_Chunk* Chunk, const std::string file_path);
	static void FreeMusic(Mix_Music* Music);
	static void FreeChunk(Mix_Chunk* Chunk);
};

#endif //LMUSIC_H

