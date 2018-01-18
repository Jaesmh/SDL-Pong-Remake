#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <Windows.h>

//To Be Implemented Within Each Class^
class GameSystem
{
protected:
	SDL_Renderer* Renderer = nullptr;
	SDL_Window* Window = nullptr;
	SDL_Event Event;
public:
	GameSystem(const std::string& Title, int XWinPos, int YWinPos, int Width, int Height, bool FullScreen);
	~GameSystem();
	inline bool IsClosed() { return _IsClosed; }
	bool Initialize();
	virtual void PollEvents();
	void Render() const;
	void ShutDown() const;
	void PlayMusic();
private:
	Mix_Music* PongMusic = nullptr;
	int _WINFlag = SDL_WINDOW_FULLSCREEN_DESKTOP;
	bool _FullScreen = false;
	int &_Width, &_Height;
	int &_XWinPos, &_YWinPos;
	const std::string &_Title;
	bool _Success = true;
	bool _IsClosed = false;
	int _IMGFlag = IMG_INIT_PNG;
};

#endif GAMESYSTEM_H