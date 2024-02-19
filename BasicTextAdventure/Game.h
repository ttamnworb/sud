#pragma once

#include <string>
#include <map>
#include "LocationObject.h"
#include "Inventory.h"
#include "ItemObject.h"
#include "PlayerObject.h"

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


private:
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

private:
	Locations m_AllLocations;
	Inventory m_AllInventory;
	PlayerObject m_Player;
};

