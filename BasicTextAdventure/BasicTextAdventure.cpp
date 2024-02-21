// BasicTextAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UnitTests.h"
#include "Game.h"


int main(int argc, char* argv[])
{
	// TODO Separate the code into a library so it works with proper unit testing frameworks.

	if (argc > 1)
	{
		SUD_Tests::Tests();
		std::cout << "Tests complete - Press enter to exit\n";
	}
	else
	{
		SUD::Game game("nofile.txt");
	}
	return fgetc(stdin);
}
