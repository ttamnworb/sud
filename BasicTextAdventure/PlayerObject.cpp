#include "PlayerObject.h"

PlayerObject::PlayerObject()
	: BaseObject()
{
}


bool PlayerObject::TeleportPlayer(const std::string& newLocation)
{
	// TODO
	return false;
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