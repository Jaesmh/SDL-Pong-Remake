#include "GameSystem.h"

GameSystem::GameSystem(const std::string & Title, int XWinPos, int YWinPos, int Width, int Height, bool FullScreen)
	:_Title(Title), _XWinPos(XWinPos), _YWinPos(YWinPos), _Width(Width), _Height(Height), _FullScreen(FullScreen)
{
	if (IsClosed() == Initialize()) 
	{
		std::cerr << "SDL has failed to initialize..." << SDL_GetError() << std::endl;
		Sleep(2000);
		SDL_Quit();
		exit(1); 
	}
}

GameSystem::~GameSystem()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Mix_CloseAudio();
	atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(TTF_Quit);
	atexit(SDL_Quit);
}

void GameSystem::PollEvents()
{
	SDL_ShowCursor(SDL_DISABLE);

	if (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			_IsClosed = true;
			ShutDown();
			exit(1);
			break;

		default:
			break;
		}
	}
}

bool GameSystem::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cerr << "SDL could not initialize..." << SDL_GetError() << std::endl;
		_IsClosed = true;
		_Success = false;
		return _Success;
	}

	else
	{
		if (_FullScreen == false)
		{
			_WINFlag = NULL;
		}

		Window =
			SDL_CreateWindow
			(_Title.c_str(),
				_XWinPos,
				_YWinPos,
				_Width,
				_Height,
				_WINFlag);
	}

	if (Window == nullptr)
	{
		std::cerr << "The window could not be created..." << SDL_GetError() << std::endl;
		_IsClosed = true;
		_Success = false;
		return _Success;
	}

	else
	{
		Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}

	if (Renderer == nullptr)
	{
		std::cerr << "Renderer could not be created..." << SDL_GetError() << std::endl;
		_IsClosed = true;
		_Success = false;
		return _Success;
	}

	else if (IMG_Init(_IMGFlag) != _IMGFlag)
	{
		std::cerr << "SDL_image failed to initialize..." << SDL_GetError() << std::endl;
		_IsClosed = true;
		_Success = false;
		return _Success;
	}

	if (TTF_Init() == -1)
	{
		std::cerr << "SDL_tff failed to initialize..." << SDL_GetError() << std::endl;
		_IsClosed = true;
		_Success = false;
		return _Success;
	}

	else if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	{
		std::cerr << "SDL_mixer failed to initiaize..." << SDL_GetError() << std::endl;
	}

	if (_Success == true)
	{
		std::cout << "Program ran without error!" << std::endl;
	}

	return _Success;
}

void GameSystem::Render() const
{
	SDL_RenderPresent(Renderer);
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
	SDL_RenderClear(Renderer);
}

void GameSystem::ShutDown() const
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window); 
	Mix_CloseAudio(); 
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
