#include "Direction.h"

namespace SUD
{
	std::map<Direction::EDirection, std::string> Direction::m_Map;
	std::map<std::string, Direction::EDirection> Direction::m_MapReversed;

	std::string Direction::ToString(const EDirection input)
	{
		InitialiseMap();
		const auto iFound = m_Map.find(input);
		if (iFound != m_Map.end())
		{
			return iFound->second;
		}
		return m_Map[EDirection::North];	// TODO : Should be an unknown value, but there is no error handling at the moment
	}

	Direction::EDirection Direction::FromString(const std::string& input)
	{
		InitialiseMap();
		const auto iFound = m_MapReversed.find(input);
		if (iFound != m_MapReversed.end())
		{
			return iFound->second;
		}
		return EDirection::North;			// TODO : Should be an unknown value, but there is no error handling at the moment
	}

	void Direction::InitialiseMap()
	{
		static bool bMapInitialised(false);
		if (!bMapInitialised)
		{
			bMapInitialised = true;
			m_Map.emplace(EDirection::North, "NORTH");
			m_Map.emplace(EDirection::East, "EAST");
			m_Map.emplace(EDirection::South, "SOUTH");
			m_Map.emplace(EDirection::West, "WEST");
			m_Map.emplace(EDirection::Up, "UP");
			m_Map.emplace(EDirection::Down, "DOWN");

			for (const auto& item : m_Map)
			{
				m_MapReversed.emplace(item.second, item.first);
			}
		}
	}
}