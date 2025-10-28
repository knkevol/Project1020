#include "Timer.h"

UTimer::UTimer()
{
	CurrentTime = 0;
	LastTime = 0;
	DeltaSeconds = 0.0f;
}

UTimer::~UTimer()
{
}

void UTimer::Tick()
{
	CurrentTime = SDL_GetTicksNS();

	DeltaSeconds = (double)(CurrentTime - LastTime) / 1000000000.0;

	LastTime = CurrentTime; //끝났을때 시작시간을 넣어줘야 이전시간.


}