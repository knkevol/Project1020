#pragma once
class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	void Init();
	void Run();
	void Term();

private:
	void Input();
	void Tick(); // Process
	void Render();

};

