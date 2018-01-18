#include "LMusic.h"

LMusic::LMusic()
{
	Mix_Volume(30, -1);
}

void LMusic::PlayChunk(Mix_Chunk * Chunk)
{
	Mix_PlayChannel(0, Chunk, 0);
}

void LMusic::PlayMusic(Mix_Music * Music)
{
	if (Mix_PlayingMusic() == NULL)
	{
		Mix_PlayMusic(Music, -1);
	}

	if (Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
}

Mix_Music* LMusic::LoadMusic(Mix_Music * Music, const std::string file_path)
{
	Music = Mix_LoadMUS(file_path.c_str());
	return Music;
}

Mix_Chunk* LMusic::LoadChunk(Mix_Chunk * Chunk, const std::string file_path)
{
	Chunk = Mix_LoadWAV(file_path.c_str());
	return Chunk;
}

void LMusic::FreeMusic(Mix_Music * Music)
{
	Mix_FreeMusic(Music);
}

void LMusic::FreeChunk(Mix_Chunk * Chunk)
{
	Mix_FreeChunk(Chunk);
}
