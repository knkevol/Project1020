#include "Actor.h"

#include "Windows.h"

AActor::AActor()
{
	//cout << "AActor ������" << "\n";
	Shape = ' ';
	Location = 0, 0;
	//ZOrder = 0;
}

AActor::~AActor()
{
	//cout << "AActor �Ҹ���" << "\n";
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
