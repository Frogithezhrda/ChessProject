/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Manager.h"

#define BUFFER 1024
#define DELAY 5000
#define CONSOLE 'c'
#define GRAPHICS 'g'
#define INIT_STRING "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"//the board
#define TRY_AGAIN "0"

void handleMainGame(Manager* manager);
void handleGraphics(Manager* manager);

int main()
{
	srand(time_t(NULL));
	Manager* manager = new Manager(INIT_STRING);
	handleMainGame(manager);
	delete manager;
	manager = nullptr;
	return 0;
}


void handleMainGame(Manager* manager)
{
	char type = ' ';
	try
	{
		std::cout << "For Console Game - 'c', For Graphic Game 'g': " << std::endl;//choice between graphic and conole
		std::cin >> type;
		if (std::tolower(type) == CONSOLE)//if the player chode console, 
		{
			manager->handleConsoleMode();//call the console
		}
		else if (std::tolower(type) == GRAPHICS)//if the player chose graphics
		{
			handleGraphics(manager);//call the menegar
		}
		else//else
		{
			std::cerr << "Invalid input. Exiting program." << std::endl;//error message
		}
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Unknown Exception." << std::endl;//exeptions
	}
}

void handleGraphics(Manager* manager)
{
	Pipe p;
	bool isConnect = p.connect();
	std::string ans = "";
	char msgToGraphics[BUFFER];

	std::cout << "Starting Graphics.exe Just Put It In The Same Folder As The Game" << std::endl;//starting  graphics
	system("start chessGraphics.exe");

	while (!isConnect)//if graphics dident connect
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == TRY_AGAIN)//if they wanted to try again
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(DELAY);
			isConnect = p.connect();
		}
		else //if they dednt, close the pipe
		{
			p.close();
			return;
		}
	}

	strcpy_s(msgToGraphics, INIT_STRING); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	// get message from graphics
	manager->handleGraphicsMode(p);
	p.close();
}