// BasicTextAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// #include "UnitTests.h"
#include "Game.h"


int main()
{
	//SUD_Tests::Tests();
	//std::cout << "Tests complete - Press enter to exit\n";

	SUD::Game game("nofile.txt");
	return fgetc(stdin);
}
