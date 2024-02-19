#pragma once
#include <map>
#include "ItemObject.h"

namespace SUD
{
	/// <summary>
	/// A collection of items owned by a parent object
	/// An inventory can only have one instance of each item name, duplicates will be lost.
	/// </summary>
	class Inventory
	{
	public:
		/// <summary>
		/// Class constructor
		/// Initialises the inventory to be empty.
		/// </summary>
		Inventory();

		/// <summary>
		/// Add an item to the inventory.
		/// The source of the item does not need to be known, for loading.
		/// </summary>
		/// <param name="object">The object to add</param>
		/// <returns>true if the object was added</returns>
		bool Add(const ItemObject& object);

		/// <summary>
		/// Remove an item from the inventory
		/// </summary>
		/// <param name="name">The name of the item to remove</param>
		/// <param name="object">The object that is removed</param>
		/// <returns>True if it could be removed</returns>
		bool Remove(const std::string& name, ItemObject& object);

		/// <summary>
		/// Transfer an item from source inventory into this inventory.
		/// </summary>
		/// <param name="name">The name of the item to transfer</param>
		/// <param name="source">The source inventory</param>
		/// <returns>true if the item can be transfered</returns>
		bool TransferIn(const std::string& name, Inventory& source);

		/// <summary>
		/// List all items in the inventory
		/// </summary>
		/// <returns>Name, description</returns>
		std::map<std::string, std::string> List() const;

	private:
		std::map<std::string, ItemObject> m_Items;
	};
}