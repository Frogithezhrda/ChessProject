/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Manager.h"

using std::cout;
using std::endl;
using std::string;

void handleMainGame(Manager* manager);
void handleGraphics(Manager* manager);

void main()
{
	srand(time_t(NULL));
	Manager* manager = NULL;
	handleMainGame(manager);
	delete manager;
}


void handleMainGame(Manager* manager)
{
	char type = ' ';
	std::string move = "";
	bool isWhiteTurn = true;
	std::cout << "For Console Game - 'c, For Graphic Game 'g': " << std::endl;
	std::cin >> type;
	if (std::tolower(type) == 'c')
	{
		manager = new Manager("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
		while (move != "quit")
		{
			manager->printTurn(manager->isWhiteTurn());
			manager->getBoard().printBoard();
			std::cout << "Enter your move or type 'quit' to exit: ";
			std::cin >> move; //players input
			manager->handleConsole(move);
		}
	}
	else if (std::tolower(type) == 'g')
	{
		handleGraphics(manager);
	}
	else
	{
		std::cerr << "Invalid input. Exiting program." << endl;
	}
}

void handleGraphics(Manager* manager)
{
	Pipe p;
	bool isConnect = p.connect();
	string ans;
	std::cout << "Starting Graphics.exe Just Put It In The Same Folder As The Game" << std::endl;
	system("start chessGraphics.exe");

	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	manager = new Manager(msgToGraphics);
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		// YOUR CODE
		manager->handleConsole(msgFromGraphics);
		manager->printTurn(manager->isWhiteTurn());
		manager->getBoard().printBoard();
		strcpy_s(msgToGraphics, std::to_string(manager->getErrorCode()).c_str()); // msgToGraphics should contain the result of the operation
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);
		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
}