#pragma once

#include <string>
#include <map>
#include "LocationObject.h"
#include "Inventory.h"
#include "ItemObject.h"
#include "PlayerObject.h"

namespace SUD
{
	/// <summary>
	///  This is the main game object
	/// </summary>
	class Game
	{
		// This object will load in the map and object data.
		// There should be one player who will start at a certain location (TBD)
	public: // Types
		typedef std::map<std::string, LocationObject> Locations;
	public:

		/// <summary>
		/// Class constructor
		/// Load the specified data file and construct the data
		/// Validate/Verify the data is correct
		/// While (!Player.isDead())
		///		Show location
		///		Show Possible exits
		///		Ask for decision
		///		Check decision is valid
		///		Move
		/// </summary>
		/// <param name="dataFile">The name of the file that defines the game's map</param>
		Game(const std::string& dataFile);

		/// <summary>
		/// Get read only access to all the rooms in the game.
		/// </summary>
		/// <returns></returns>
		const Locations& AllLocation() const { return m_AllLocations; }

		/// <summary>
		/// Get read only access to all items in the game.
		/// </summary>
		/// <returns></returns>
		const Inventory& AllInventory() const { return m_AllInventory; }

		/// <summary>
		/// Get the named location
		/// </summary>
		/// <returns>The </returns>
		const LocationObject& GetLocation(const std::string& name) const;

	private:	// Types
		/// <summary>
		/// The enum containing all acceptable commands
		/// </summary>
		enum class ECommands { Invalid, Go, Wait, Help };

		/// <summary>
		/// The structure containing the command to execute and the parameter.
		/// </summary>
		struct CommandData
		{
			ECommands	Command;
			std::string	Parameter;
			CommandData(const ECommands com, const std::string& par)
				: Command(com), Parameter(par)
			{}
		};

	private:	// Methods
		/// <summary>
		/// Load the data structures from the file and store them in the relevant member data
		/// </summary>
		/// <param name="dataFile">The name of the datafile</param>
		/// <returns></returns>
		bool LoadFile(const std::string& dataFile);

		/// <summary>
		/// Save the data file
		/// </summary>
		/// <param name="dataFile">The name of the data file</param>
		/// <returns></returns>
		bool SaveFile(const std::string& dataFile);

		/// <summary>
		/// Check that the data loaded is all there, every link named has a corresponding object
		/// </summary>
		/// <returns></returns>
		bool VaidateData();

		/// <summary>
		/// Show the current location and exits.
		/// </summary>
		void ShowLocation(const PlayerObject& player) const;

		/// <summary>
		/// Get the players next command/instruction
		/// Validates the command
		/// </summary>
		/// <returns>The command entered and its parameter</returns>
		CommandData GetCommand() const;

		/// <summary>
		/// Act on the command supplied.
		/// </summary>
		/// <param name="command"></param>
		/// <returns>True if the command could be acted on</returns>
		bool ActOnCommand(const CommandData& command);

		/// <summary>
		/// Act on a GO command
		/// </summary>
		/// <param name="command"></param>
		/// <returns></returns>
		bool ActOnGo(const CommandData& command);

		/// <summary>
		///  Act on a wait command
		/// </summary>
		/// <param name="command"></param>
		/// <returns></returns>
		bool ActOnWait(const CommandData& command);

		/// <summary>
		/// Act on an invalid command
		/// </summary>
		/// <param name="command"></param>
		/// <returns></returns>
		bool ActOnInvalid(const CommandData& command);

		/// <summary>
		/// Show the possible commands.
		/// </summary>
		/// <param name="command"></param>
		/// <returns></returns>
		bool ActOnHelp(const CommandData& command);

	private:
		static std::map<Game::ECommands, std::string> m_TheCommands;
		Locations m_AllLocations;
		Inventory m_AllInventory;
		PlayerObject m_Player;
	};
}
