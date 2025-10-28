#pragma once
#include <SDL3/SDL.h>


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

	__forceinline UWorld* GetWorld() const { return World; }
	__forceinline int GetKeyCode() const { return KeyCode; }

	//Singleton
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

protected:
	void Input();
	void Tick(); // =Process
	void Render();

	class UWorld* World;

	bool bIsRunning = true;
	int KeyCode = 0;

	//Singleton
	static FEngine* Instance;

	class UTimer* Timer = nullptr;
	
};

#define GEngine	FEngine::GetInstance()