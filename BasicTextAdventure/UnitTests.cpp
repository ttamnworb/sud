#include <iostream>
#include "LocationObject.h"
#include "ItemObject.h"
#include "Inventory.h"
#include "UnitTests.h"

namespace SUD_Tests
{
	void Tests()
	{
		TestLocation();
		TestInventory();
	}

	void TestLocation()
	{
		// Generate a location with a North and south exit
		SUD::LocationObject room;
		room.AddExit(SUD::Direction::EDirection::North, "The north door", "NorthRoom");
		room.AddExit(SUD::Direction::EDirection::South, "The south door", "SouthRoom");
		{
			// Ask the location what the possible exits are (N&S should be the answer)
			auto exits = room.GetExits();
			const std::map<std::string, std::string> expected =
			{
				{"North", "The north door"},
				{"South", "The south door"}
			};
			bool result = (exits.size() == expected.size());
			for (auto item = expected.begin(); item != expected.end() && result; ++item)
			{
				result &= (exits[item->first] == item->second);
			}
			std::cout << "Get Exits test = " << (result ? "Pass" : "Fail") << "\n";
		}
		{
			// Ask the location to get the destination when exiting East (empty string should be the answer)
			auto eastExit = room.GetDestination(SUD::Direction::EDirection::East);
			const std::string expected = "";
			std::cout << "Test East exit result = " << (expected.compare(eastExit) == 0 ? "Pass" : "Fail") << "\n";
		}
		{
			// Ask the location to get the destination when exiting North (NorthRoom should be the answer)
			auto northExit = room.GetDestination(SUD::Direction::EDirection::North);
			const std::string expected = "NorthRoom";
			std::cout << "Test North exit result = " << (expected.compare(northExit) == 0 ? "Pass" : "Fail") << "\n";
		}
	}

	void TestInventory()
	{
		SUD::Inventory  testInv;

		testInv.Add({ "Object 1", "The first Object" });
		testInv.Add({ "Object 2", "The second Object" });

		{
			// Check to see that the inventory contains the expected items
			auto result = testInv.List();
			const std::map<std::string, std::string> expected =
			{
				{ "Object 1", "The first Object" },
				{ "Object 2", "The second Object" }
			};
			bool overall = (result.size() == expected.size());
			for (auto item = expected.begin(); item != expected.end() && overall; ++item)
			{
				overall &= (result[item->first] == item->second);
			}
			std::cout << "Inventory content test = " << (overall ? "Pass" : "Fail") << "\n";
		}
		{
			// Transfer object 2 to this new inventory
			SUD::Inventory Inv2;
			Inv2.TransferIn("Object 2", testInv);
			auto result = Inv2.List();
			const std::map<std::string, std::string> expected =
			{
				{ "Object 2", "The second Object" }
			};
			bool overall = (result.size() == expected.size());
			for (auto item = expected.begin(); item != expected.end() && overall; ++item)
			{
				overall &= (result[item->first] == item->second);
			}
			std::cout << "Inventory 2 content test = " << (overall ? "Pass" : "Fail") << "\n";
		}

	}
}