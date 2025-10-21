#pragma once

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

protected:
	void Input();
	void Tick(); // =Process
	void Render();

	class UWorld* World;

	bool bIsRunning = true;
	int KeyCode = 0;

	//Singleton
	static FEngine* Instance;
	
};

#define GEngine	FEngine::GetInstance()