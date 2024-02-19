#pragma once
#include <string>
#include <map>


namespace SUD
{
	/// <summary>
	/// This class holds everything to do with movement directions.
	/// </summary>
	class Direction
	{
	public:
		/// <summary>
		/// The possible directions of travel
		/// </summary>
		enum class EDirection
		{
			North,
			East,
			South,
			West,
			Up,
			Down
		};

		/// <summary>
		/// Convert from the enum to a string.
		/// </summary>
		/// <param name="input">The direction to convert</param>
		/// <returns>The string representing the direction</returns>
		static std::string ToString(const EDirection input);

		/// <summary>
		/// Convert from a string to the enum.
		/// </summary>
		/// <param name="input">The string representing the direction to convert</param>
		/// <returns>The direction</returns>
		static EDirection FromString(const std::string& input);

	private:
		static std::map<EDirection, std::string> m_Map;
		static std::map<std::string, EDirection> m_MapReversed;

		/// <summary>
		/// Initialise the data in the map structures.
		/// </summary>
		static void InitialiseMap();
	};
}