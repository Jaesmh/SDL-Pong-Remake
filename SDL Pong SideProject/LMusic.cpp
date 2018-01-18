#include "LMusic.h"

LMusic::LMusic()
{
}

void LMusic::LoadMusic(Mix_Music * Music, const std::string file_path)
{
	Music = Mix_LoadMUS(file_path.c_str());
}

void LMusic::LoadChunk(Mix_Chunk * Chunk, const std::string file_path)
{
	Chunk = Mix_LoadWAV(file_path.c_str());
}

void LMusic::FreeMusic(Mix_Music * Music)
{
	Mix_FreeMusic(Music);
}

void LMusic::FreeChunk(Mix_Chunk * Chunk)
{
	Mix_FreeChunk(Chunk);
}
