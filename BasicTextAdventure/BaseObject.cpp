#include "BaseObject.h"

namespace SUD
{
	const std::string BaseObject::InvalidName = "";

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
}