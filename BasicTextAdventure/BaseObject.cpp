#include "BaseObject.h"

BaseObject::BaseObject(const std::string& name, const std::string description)
	: m_Name(name)
	, m_Description(description)
{
	// TODO
}

bool BaseObject::LoadObject(std::ifstream& inputStream)
{
	// TODO
	return false;
}

bool BaseObject::SaveObject(std::ofstream& outputStream)
{
	// TODO
	return false;
}