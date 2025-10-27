#define SDL_ENABLE_OLD_NAMES

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <vector>

#pragma comment(lib, "SDL3") //x64 SDL3.lib



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
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	SDL_Window* MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);
	SDL_Event MyEvent;

	bool bIsRunning = true;
	while (bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			//window
			if (MyEvent.type == SDL_EVENT_QUIT) // close event
			{
				//close window
				bIsRunning = false;
			}
		}
		else //screen update
		{
			//command queue >> to gpu
			//int RandColor = rand() % 256;
			SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
			//SDL_SetRenderDrawColor(MyRenderer, 10, 50, 50, 255);
			SDL_RenderClear(MyRenderer);


			
			for (int i = 0; i < 100; i++ )
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(255), SDL_rand(255), SDL_rand(255), 0);

				SDL_FRect MyRect = { SDL_rand(640), SDL_rand(480), SDL_rand(200) + 1, SDL_rand(200) + 1 };
				SDL_RenderFillRect(MyRenderer, &MyRect);
				SDL_RenderDrawRect(MyRenderer, &MyRect);
				
			}
			
			
			
			

			
			SDL_RenderPresent(MyRenderer);

			
		}
	}
	
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();


	return 0;
}