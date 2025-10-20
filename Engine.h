#pragma once
class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	void Init();
	void Run();
	void Term();

protected:
	void Input();
	void Tick(); // =Process
	void Render();

	bool bIsRunning = true;

};

