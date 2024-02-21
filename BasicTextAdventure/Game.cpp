#include <iostream>
#include "Game.h"



namespace SUD
{
	std::map<Game::ECommands, std::string> Game::m_TheCommands =
	{	// Make sure all commands have a space after them to ensure whole world matching.
		{ECommands::Go,   "GO "},
		{ECommands::Wait, "WAIT "},
		{ECommands::Help, "HELP "}
	};

	Game::Game(const std::string& dataFile)
		: m_Player(this)
	{
		if (LoadFile(dataFile))
		{
			if (VaidateData())
			{
				while (!m_Player.IsDead())
				{
					///		Show location and exits
					ShowLocation(m_Player);
					///		Ask for decision
					const auto command = GetCommand();
					///		Check decision is valid
					/// TODO
					///		Act on the command.
					ActOnCommand(command);
				}
			}
		}
	}

	bool Game::LoadFile(const std::string& dataFile)
	{
		// TODO 

		// The following is temp code until the file functions are implemented
		LocationObject rooms[] =
		{
			{"rm1", "Room 1"},
			{"rm2", "Room 2"},
			{"rm3", "Room 3"},
			{"rm4", "Room 4"},
			{"rm5", "Room 5"}
		};
		rooms[0].AddExit(Direction::EDirection::South, "1 South Door", "rm2");

		rooms[1].AddExit(Direction::EDirection::South, "2 South Door", "rm3");
		rooms[1].AddExit(Direction::EDirection::North, "2 North Door", "rm1");
		rooms[1].AddExit(Direction::EDirection::East, "2 East Door", "rm4");

		rooms[2].AddExit(Direction::EDirection::North, "3 North Door", "rm2");
		rooms[2].AddExit(Direction::EDirection::East, "3 East Door", "rm5");

		rooms[3].AddExit(Direction::EDirection::West, "4 West Door", "rm2");
		rooms[3].AddExit(Direction::EDirection::South, "4 South Door", "rm5");

		rooms[4].AddExit(Direction::EDirection::North, "5 North Door", "rm4");
		rooms[4].AddExit(Direction::EDirection::West, "5 West Door", "rm3");

		for (const auto& room : rooms)
		{
			m_AllLocations.emplace(room.Name(), room);
		}

		return true;
	}

	bool Game::SaveFile(const std::string& dataFile)
	{
		// TODO 
		return false;
	}

	bool Game::VaidateData()
	{
		// TODO 
		return true;
	}

	const LocationObject& Game::GetLocation(const std::string& name) const
	{
		const auto& iFound = m_AllLocations.find(name);
		if (iFound != m_AllLocations.end())
		{
			return iFound->second;
		}
		// else
		return m_AllLocations.begin()->second;
	}

	void Game::ShowLocation(const PlayerObject& player) const
	{
		const auto& location = GetLocation(player.GetLocationName());
		std::cout << "\n";
		std::cout << location.Description();
		std::cout << "\n\n";
		for (const auto item : location.GetExits())
		{
			std::cout << item.first << " - " << item.second << "\n";
		}
	}
	Game::CommandData Game::GetCommand() const
	{// TODO need to handle case sensitivity.

		CommandData result = CommandData(ECommands::Invalid, "");

		std::string input = "";
		while (input == "")										// Keep looping until the user enters something meaningful.
		{
			std::cout << "Please enter you command : ";
			std::getline(std::cin, input);
			if (input.size() > 0)	// Is anything entered?
			{
				for (auto& command : m_TheCommands)				// Loop through the list of acceptable commands and see if it matches.
				{
					if (input.size() >= command.second.size())	// Is the input long enough to be the command?
					{
						auto inputCommand = input.substr(0, command.second.size());		// Get the command entered
						if (inputCommand.compare(command.second) == 0)				// Does it match ?
						{
							result.Command = command.first;
							result.Parameter = input.substr(command.second.size());
							return result;										// Early exit.
						}
					}
				}
			}
		}
		return result;
	}

	bool Game::ActOnCommand(const Game::CommandData& command)
	{
		switch (command.Command)
		{
		case ECommands::Go:
			return ActOnGo(command);
		case ECommands::Wait:
			return ActOnWait(command);
		case ECommands::Help:
			return ActOnHelp(command);
		case ECommands::Invalid:
		default:
			return ActOnInvalid(command);
		}
		return false;	// Should never be executed.
	}


	bool Game::ActOnGo(const CommandData& command)
	{
		return m_Player.Move(command.Parameter);
	}

	bool Game::ActOnWait(const CommandData& command)
	{
		std::cout << "You wait and whistle a little tune, nothing changes\n";
		return true;
	}

	bool Game::ActOnInvalid(const CommandData& command)
	{
		std::cout << "You fumble around, but don't achieve anything, a bit like your typing.\n";
		return true;
	}

	bool Game::ActOnHelp(const CommandData& command)
	{
		// TODO This should share the data with m_TheCommands
		static const std::map<Game::ECommands, std::string> theHelp =
		{
			{ECommands::Go,   "GO <direction>   - Head off in that direction."},
			{ECommands::Wait, "WAIT <seconds>   - Wait for some time."},
			{ECommands::Help, "HELP <nothing>   - Show this information."}
		};
		std::cout << "\nHELP\n\n";
		for (const auto& item : theHelp)
		{
			std::cout << item.second << "\n";
		}
		std::cout << "\n";
		return true;
	}
}