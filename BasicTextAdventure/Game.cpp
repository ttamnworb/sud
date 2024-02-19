#include "Game.h"

Game::Game(const std::string& dataFile)
{
	if (LoadFile(dataFile))
	{
		if (VaidateData())
		{
			while (!m_Player.IsDead())
			{
				///		Show location
				///		Show Possible exits
				///		Ask for decision
				///		Check decision is valid
				///		Move
			}
		}
	}
}

bool Game::LoadFile(const std::string& dataFile)
{
	// TODO 
	return false;
}

bool Game::SaveFile(const std::string& dataFile)
{
	// TODO 
	return false;
}

bool Game::VaidateData()
{
	// TODO 
	return false;
}