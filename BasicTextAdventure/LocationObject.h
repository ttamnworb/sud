#pragma once
#include <list>
#include <map>
#include "Direction.h"
#include "BaseObject.h"
#include "ItemObject.h"

namespace SUD
{
	/// <summary>
/// This class represents a room within the game.
/// The room may have zero or more objects inside it.
/// The room may have 1 or more exits in it.
/// </summary>

	class LocationObject : public BaseObject
	{
	public:
		/// <summary>
		/// Class constructor
		/// </summary>
		LocationObject(const std::string& name = "", const std::string description = "");

		/// <summary>
		/// Read this type of object from the given stream
		/// </summary>
		/// <param name="inputStream">The input</param>
		/// <returns>true if the object was read</returns>
		virtual bool LoadObject(std::ifstream& inputStream);

		/// <summary>
		/// Add an exit to this room
		/// TODO : This should be replaced by the load and save functions, or at least made private and used by them
		/// </summary>
		/// <param name="direction"></param>
		/// <param name="exitName"></param>
		/// <param name="exitDescription"></param>
		/// <param name="roomName"></param>
		/// <param name="roomDescription"></param>
		void AddExit(const Direction::EDirection direction, const std::string& exitDescription, const std::string& roomName);

		/// <summary>
		/// Write this type of object to the given stream
		/// </summary>
		/// <param name="outputStream">The output</param>
		/// <returns>true if the object was written</returns>
		virtual bool SaveObject(std::ofstream& outputStream);

		/// <summary>
		/// Get a list of the exit directions and descriptions.
		/// </summary>
		/// <returns>A map containing the required data</returns>
		std::map<std::string, std::string> GetExits() const;

		/// <summary>
		/// Get the destination of the exit.
		/// </summary>
		/// <param name="direction"></param>
		/// <returns>The name of the location that will be moved to</returns>
		std::string GetDestination(const Direction::EDirection& direction) const;

	private:
		struct Exit
		{
			std::string Description;					// A quick description of what the exit looks like, i.e. "An old rusty metal door"
			std::string	NextLocation;					// The name of the next location

			Exit(const std::string& desc = "", const std::string& next = "")
				: Description(desc), NextLocation(next)
			{}
		};

	private:
		std::map<Direction::EDirection, Exit> m_Exits;
	};

}