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
	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;
	
	return 0;
}