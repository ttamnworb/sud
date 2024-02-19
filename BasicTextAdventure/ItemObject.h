#pragma once
#include "BaseObject.h"

namespace SUD
{
	/// <summary>
	/// This class represents a single inanimate object in the game, i.e. key, rock, bottle, etc.
	/// </summary>
	class ItemObject : public BaseObject
	{
	public:
		/// <summary>
		/// Class constructor
		/// </summary>
		ItemObject(const std::string& name = "", const std::string description = "", const int uses = 1);

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
		/// Attempt to use the object
		/// </summary>
		/// <returns>Return true if the object could be used.</returns>
		bool UseObject();


	private:
		int m_NumberOfUses;			// The number of times the object can be used.
		int m_TimesUsed;			// The number of times this object has been used.
	};
}