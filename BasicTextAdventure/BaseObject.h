#pragma once

#include <string>


/// <summary>
/// This object is the base class for all objects that may be used in the game.
/// </summary>
class BaseObject
{
public:
	/// <summary>
	/// Class constructor.
	/// </summary>
	BaseObject(const std::string& name = "", const std::string description = "");

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

	// Simple accessor functions
	std::string Name() const { return m_Name; }
	std::string Description () const { return m_Description; }

protected:
	std::string m_Name;					// The name of this object
	std::string m_Description;			// A user friendly description of the object to set the atmosphere.
};

