#pragma once
#include <list>
#include "BaseObject.h"
#include "ItemObject.h"
#include "LocationObject.h"

/// <summary>
/// This object is represents the player
/// A player will always have a valid location
/// A Player has an inventory of zero or more objects
///		A player can add or remove items from the current location.
///		A player can use any object in the current location.
/// A player can move through any exit if it exists and they pass the required criteria.
/// </summary>
class PlayerObject : public BaseObject
{
public:
	/// <summary>
	/// Class constructor
	/// </summary>
	PlayerObject();

	/// <summary>
	/// Move the player, ignoring exits, to the named location.
	/// Originally just to place the player when the game starts up, but 
	/// it might be useful if there is a need for a teleport spell, etc.
	/// </summary>
	/// <param name="newLocation"></param>
	/// <returns> true if the player was moved </returns>
	bool TeleportPlayer(const std::string& newLocation);

	/// <summary>
	/// Read this type of object from the given stream
	/// </summary>
	/// <param name="inputStream">The input</param>
	/// <returns>true if the object was read</returns>
	virtual bool LoadObject(std::ifstream& inputStream);

	/// <summary>
	/// Write this type of object to the given stream
	/// </summary>
	/// <param name="outputStream">The output</param>
	/// <returns>true if the object was written</returns>
	virtual bool SaveObject(std::ofstream& outputStream);

	/// <summary>
	/// The player is dropping an item into the current room
	/// </summary>
	/// <param name="itemName">The name of the object</param>
	/// <returns>True if the object can be dropped</returns>
	bool DropObject(const std::string& itemName);

	/// <summary>
	/// The player is picking an item up from the current room.
	/// </summary>
	/// <param name="itemName">The name of the object</param>
	/// <returns>True if the object can be added</returns>
	bool PickObject(const std::string& itemName);

	/// <summary>
	/// Has something killed the player?
	/// </summary>
	/// <returns></returns>
	bool IsDead() const { return false; }	// TODO there is nothing in the map yet

private:
	std::list<ItemObject> m_Inventory;				// The content of the room
	std::string m_CurrentLocationName;				// The players current location.
};

