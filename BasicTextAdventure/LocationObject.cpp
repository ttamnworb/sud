#include "Direction.h"
#include "LocationObject.h"

LocationObject::LocationObject()

	: BaseObject()
{}

bool LocationObject::LoadObject(std::ifstream& inputStream)
{
	// TODO Load the data from the file.
	return false;
}

void LocationObject::AddExit(const Direction::EDirection direction, const std::string& exitDescription, const std::string& roomName)
{
	m_Exits.emplace(direction, Exit(exitDescription, roomName));
}

bool LocationObject::SaveObject(std::ofstream& outputStream)
{
	// TODO Save the data from the file.
	return false;
}


std::map<std::string, std::string> LocationObject::GetExits() const
{
	std::map<std::string, std::string> result;
	
	for (const auto& destination : m_Exits)
	{
		result.emplace(Direction::ToString(destination.first), destination.second.Description);
	}
	return result;
}

std::string LocationObject::GetDestination(const Direction::EDirection& direction)
{
	return m_Exits[direction].NextLocation;
}


