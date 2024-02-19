#include "Game.h"
#include "PlayerObject.h"


namespace SUD
{
	PlayerObject::PlayerObject(Game* pGame)
		: BaseObject()
		, m_pGame(pGame)
	{
		if (m_pGame == nullptr)
		{
			throw std::exception("Invalid Game pointer");	// TODO improve error handling.
		}
	}


	bool PlayerObject::TeleportPlayer(const std::string& newLocation)
	{
		bool result(false);
		const auto& allLocations = m_pGame->AllLocation();
		const auto& iFound = allLocations.find(newLocation);	// Check that the new location is an existing location.
		if (iFound != allLocations.end())
		{
			m_CurrentLocationName = newLocation;
			result = true;
		}
		return result;
	}

	bool PlayerObject::Move(const std::string& direction)
	{
		bool result(false);
		// get the exits for the current location and check that direction is accessible.
		const auto& currentLocation = m_pGame->GetLocation(m_CurrentLocationName);
		const auto& exits = currentLocation.GetExits();
		const auto& iFound = exits.find(direction);
		if (iFound != exits.end())
		{
			// TODO If the exit conditions are met (NYI) 
			// Make the new location the current location.
			Direction::EDirection direction = Direction::FromString(iFound->first);
			m_CurrentLocationName = currentLocation.GetDestination(direction);
			result = true;
		}
		return result;
	}

	bool PlayerObject::LoadObject(std::ifstream& inputStream)
	{
		// TODO 
		return false;
	}

	bool PlayerObject::SaveObject(std::ofstream& outputStream)
	{
		// TODO 
		return false;
	}

	bool PlayerObject::DropObject(const std::string& itemName)
	{
		// TODO 
		return false;
	}

	bool PlayerObject::PickObject(const std::string& itemName)
	{
		// TODO 
		return false;
	}
}