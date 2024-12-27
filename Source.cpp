/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Manager.h"
#include <crtdbg.h>

#define BUFFER 1024
#define DELAY 5000
#define CONSOLE 'c'
#define GRAPHICS 'g'
#define INIT_STRING "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#define TRY_AGAIN "0"

void handleMainGame(Manager* manager);
void handleGraphics(Manager* manager);

void main()
{
	srand(time_t(NULL));
	Manager* manager = new Manager(INIT_STRING);
	handleMainGame(manager);
	delete manager;
	manager = nullptr;
	printf("%d", _CrtDumpMemoryLeaks());
}


void handleMainGame(Manager* manager)
{
	char type = ' ';
	std::cout << "For Console Game - 'c', For Graphic Game 'g': " << std::endl;
	std::cin >> type;
	if (std::tolower(type) == CONSOLE)
	{
		manager->handleConsoleMode();
	}
	else if (std::tolower(type) == GRAPHICS)
	{
		handleGraphics(manager);
	}
	else
	{
		std::cerr << "Invalid input. Exiting program." << std::endl;
	}
}

void handleGraphics(Manager* manager)
{
	Pipe p;
	bool isConnect = p.connect();
	std::string ans = "";
	char msgToGraphics[BUFFER];

	std::cout << "Starting Graphics.exe Just Put It In The Same Folder As The Game" << std::endl;
	system("start chessGraphics.exe");

	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == TRY_AGAIN)
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(DELAY);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}

	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, INIT_STRING); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	// get message from graphics
	manager->handleGraphicsMode(p);
	p.close();
}