#ifndef LMUSIC_H
#define LMUSIC_H

#include "GameSystem.h"

class LMusic
{
public:
	LMusic();
	static void LoadMusic(Mix_Music* Music, const std::string file_path);
	static void LoadChunk(Mix_Chunk* Chunk, const std::string file_path);
	static void FreeMusic(Mix_Music* Music);
	static void FreeChunk(Mix_Chunk* Chunk);
};

#endif //LMUSIC_H

