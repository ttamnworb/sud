#include "ItemObject.h"


ItemObject::ItemObject(const std::string& name, const std::string description, const int uses)
	: BaseObject(name, description)
	, m_NumberOfUses(uses)
	, m_TimesUsed(0)
{}

bool ItemObject::LoadObject(std::ifstream& inputStream)
{
	// TODO
	return false;
}

bool ItemObject::SaveObject(std::ofstream& outputStream)
{
	// TODO
	return false;
}

bool ItemObject::UseObject()
{
	bool result(false);
	if (m_TimesUsed < m_NumberOfUses)
	{
		++m_TimesUsed;
		result = true;
	}
	return result;
}