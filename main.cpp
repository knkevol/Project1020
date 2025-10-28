#include "Engine.h"
#include <SDL3/SDL_main.h>

//int main()
//{
//	//GEngine->Init();
//	//GEngine->Run();
//	//GEngine->Term();
//
//	//delete GEngine;
//
//
//	
//
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	// Play Time
	SDL_Time DeltaSeconds = SDL_GetTicks64();

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	//Current Time
	DeltaSeconds = SDL_GetTicks64() - DeltaSeconds;

	//delete GEngine;
	
	return 0;
}