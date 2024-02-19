#include "Inventory.h"


/// <summary>
/// Class constructor
/// Initialises the inventory to be empty.
/// </summary>
Inventory::Inventory()
{}

/// <summary>
/// Add an item to the inventory.
/// The source of the item does not need to be known, for loading.
/// </summary>
/// <param name="object">The object to add</param>
/// <returns>true if the object was added</returns>
bool Inventory::Add(const ItemObject& object)
{
	m_Items.emplace(object.Name(), object);
	return true;	// TODO - Not required, but nice for consistency.
}

/// <summary>
/// Remove an item from the inventory
/// </summary>
/// <param name="name">The name of the item to remove</param>
/// <param name="object">The object that is removed</param>
/// <returns>True if it could be removed</returns>
bool Inventory::Remove(const std::string& name, ItemObject& object)
{
	bool result(false);
	const auto found = m_Items.find(name);
	if (found != m_Items.end())
	{
		object = found->second;
		m_Items.erase(name);
		result = true;
	}
	return result;
}


/// <summary>
/// Transfer an item from source inventory into this inventory.
/// </summary>
/// <param name="name">The name of the item to transfer</param>
/// <param name="source">The source inventory</param>
/// <returns>true if the item can be transfered</returns>
bool Inventory::TransferIn(const std::string& name, Inventory& source)
{
	bool result(false);
	ItemObject object;
	
	if (source.Remove(name, object))
	{
		Add(object);
		result = true;
	}
	return result;
}

/// <summary>
/// List all items in the inventory
/// </summary>
/// <returns>Name, description</returns>
std::map<std::string, std::string> Inventory::List() const
{
	std::map<std::string, std::string> result;

	for (const auto item : m_Items)
	{
		result.emplace(item.first, item.second.Description());
	}
	return result;
}