#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//FEngine* MyEngine = new FEngine();
	//MyEngine->Init();
	//MyEngine->Run();
	//MyEngine->Term();

	//delete MyEngine;
	//MyEngine = nullptr;

	string Buffer;
	ifstream MapFile("Level101.map");
	if (MapFile.is_open())
	{
		while (getline(MapFile, Buffer))
		{
			cout << Buffer << endl;
			
		}
		MapFile.close();
	}
	else 
	{
		cout << "Error";
	}

	return 0;
}