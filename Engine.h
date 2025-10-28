#pragma once
#include <SDL3/SDL.h>
#include "Input.h"

#pragma comment(lib, "SDL3")

class UWorld;

using namespace std;

class FEngine
{
protected: //Singleton
	FEngine();

public:
	virtual ~FEngine();

	virtual void Init();
	virtual void Run();
	virtual void Term();

	void OpenLevel();

	__forceinline UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return UInput::KeyCode;
	}

protected:
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool bIsRunning = true;

	//int KeyCode = 0;


public:
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}

	double GetWorldDeltaSeconds() const;


	SDL_Window* MyWindow = nullptr;
	SDL_Renderer* MyRenderer = nullptr;
	SDL_Event MyEvent = SDL_Event();

protected:
	static FEngine* Instance;

	class UTimer* Timer = nullptr;
	class UInput* InputDevice = nullptr;
};

//extern FEngine* GEngine;

#define GEngine		FEngine::GetInstance()