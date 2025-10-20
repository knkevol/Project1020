#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//FEngine* MyEngine = new FEngine();
	//MyEngine->Init();
	//MyEngine->Run();
	//MyEngine->Term();

	//delete MyEngine;
	//MyEngine = nullptr;


	string line;
	ifstream file("Level101.map");
	if (file.is_open()) 
	{
		
		while (getline(file, line)) 
		{
			cout << line << endl;
		}
		file.close();
	}
	else 
	{
		cout << "Error";
	}

	return 0;
}