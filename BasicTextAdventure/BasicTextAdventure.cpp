// BasicTextAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LocationObject.h"
#include "Inventory.h"

void TestLocation ()
{
	// Generate a location with a North and south exit
	LocationObject room;
	room.AddExit(Direction::EDirection::North, "The north door", "NorthRoom");
	room.AddExit(Direction::EDirection::South, "The south door", "SouthRoom");
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
		auto eastExit = room.GetDestination(Direction::EDirection::East);
		const std::string expected = "";
		std::cout << "Test East exit result = " << (expected.compare(eastExit) == 0 ? "Pass" : "Fail") << "\n";
	}
	{
		// Ask the location to get the destination when exiting North (NorthRoom should be the answer)
		auto northExit = room.GetDestination(Direction::EDirection::North);
		const std::string expected = "NorthRoom";
		std::cout << "Test North exit result = " << (expected.compare(northExit) == 0 ? "Pass" : "Fail") << "\n";
	}
}

void TestInventory()
{
	Inventory  testInv;
	
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
		Inventory Inv2;
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

void Tests()
{
	TestLocation();
	TestInventory();
}
int main()
{
	Tests();
	std::cout << "Tests complete - Press enter to exit\n";
	return fgetc(stdin);
}
