#include "Engine.h"

int main()
{
	FEngine* MyEngine = new FEngine();
	MyEngine->Init();
	MyEngine->Run();
	MyEngine->Term();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}