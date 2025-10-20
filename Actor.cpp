#include "Actor.h"

#include "Windows.h"

AActor::AActor()
{
	//cout << "AActor 持失切" << "\n";
	Shape = ' ';
	Location = 0, 0;
	//ZOrder = 0;
}

AActor::~AActor()
{
	//cout << "AActor 社瑚切" << "\n";
}

void AActor::Tick()
{
	//cout << "AActor Tick" << "\n";
}

void AActor::Render()
{
	COORD Position;
	Position.X = Location.X;
	Position.Y = Location.Y;
	SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);

	cout << Shape;
}
