#include <iostream>
#include "BaseObject.h"
#include "Direction.h"
#include "LocationObject.h"
#include "ItemObject.h"
#include "Inventory.h"
#include "UnitTests.h"

namespace SUD_Tests
{
	/// <summary>
	/// A very simple class to handle test anouncement and results.
	/// </summary>
	class TestResult
	{
	public:
		TestResult(const std::string& testName)
			: m_Name(testName)
			, m_Result(true)
		{
			std::cout << "Testing " << m_Name.c_str() << "\n";
		}
		~TestResult()
		{
			std::cout << "Finished Testing " << m_Name.c_str() << " result = " << (m_Result?"PASS":"FAIL") << "\n";
		}
		void AddResult(const bool result)
		{
			m_Result = m_Result && result;
		}
		bool Result()const { return m_Result; }
	private:
		std::string m_Name;
		bool m_Result;
	};



	Tests::Tests()
	{
		bool result(true);
		result = result && BaseObject();
		result = result && Direction();
		result = result && LocationObject();

		// Not implemented the game/player tests yet
		// result = result && PlayerObject();
		// result = result && Game();
		
		// These objects are for later extension to make the game more interesting.
		// result = result && Inventory();
		// result = result && ItemObject();

	}

	bool Tests::BaseObject()
	{
		TestResult tr("BaseObject");
		// A base object has a name and a description which do not change during its life.

		// TODO Not sure there is much to be gained from testing that these values can't be changed.

		return tr.Result();
	}

	bool Tests::Direction()
	{
		TestResult tr("Direction");
		{
			// The direction class has two static functions to convert between enum and string and back.
			// Any enum direction should be converted to a string which should be converted back to its enum.

			bool result(true);
			const auto values =
			{	// TODO Find a way to avoid duplicating this list of values.
				SUD::Direction::EDirection::North,
				SUD::Direction::EDirection::East,
				SUD::Direction::EDirection::South,
				SUD::Direction::EDirection::West,
				SUD::Direction::EDirection::Up,
				SUD::Direction::EDirection::Down
			};

			for (const auto expected : values)
			{
				const auto str = SUD::Direction::ToString(expected);
				const auto actual = SUD::Direction::FromString(str);
				result = result && (expected == actual);
			}
			tr.AddResult(result);
		}
		return tr.Result();
	}

	bool Tests::Game()
	{
		TestResult testResult("Game");

		// The game object should load all game data when the object is created.
		// The game object should validate that all the data is present and correct:
		//			All locations have 1 or more exits
		//			All exists point to valid locations
		//			All items referenced by inventories exist.
		// The game object should create the player object and move it to the starting location.
		// The game object should execute the main game loop.

		return testResult.Result();	// TODO Needs implementing.
	}

	bool Tests::Inventory()
	{
		TestResult testResult("Inventory");

			// An Inventory is a collection of zero of more ItemObjects
			// An item can be added to an inventory.
			// An item can be transfered from on inventory to another.
			// An item in an inventory can be used.
			SUD::Inventory  testInv;

			testInv.Add({ "Object 1", "The first Object" });
			testInv.Add({ "Object 2", "The second Object" });

			{
				// Check to see that the inventory contains the expected items
				const std::map<std::string, std::string> expected =
				{
					{ "Object 1", "The first Object" },
					{ "Object 2", "The second Object" }
				};
				auto actual = testInv.List();
				bool result = (actual.size() == expected.size());
				for (auto item = expected.begin(); item != expected.end() && result; ++item)
				{
					result = result && (actual[item->first] == item->second);
				}
				std::cout << "Inventory content test = " << (result ? "Pass" : "Fail") << "\n";
				testResult.AddResult(result);
			}
			// Adding to the inventory has been tested by setting up the inventory.
			{
				// Transfer object 2 to this new inventory
				const std::map<std::string, std::string> expected =
				{
					{ "Object 2", "The second Object" }
				};

				SUD::Inventory Inv2;
				Inv2.TransferIn("Object 2", testInv);
				auto actual = Inv2.List();
				bool result = (actual.size() == expected.size());
				for (auto item = expected.begin(); item != expected.end() && result; ++item)
				{
					result = result && (actual[item->first] == item->second);
				}
				std::cout << "Inventory 2 content test = " << (result ? "Pass" : "Fail") << "\n";
				testResult.AddResult(result);
			}
			{
				// An object in an inventory can have the use function called.
				bool result = false;	/// TODO
				// does the object exist in the inventory?
				// If it does then 
				//		read the number of uses left
				//		Call use()
				//		read the number of uses and ensure that it is one less than before.
				// else
				//		Test Error.
				testResult.AddResult(result);
			}
			return testResult.Result();;
		
	}

	bool Tests::ItemObject()
	{
		TestResult testResult("ItemObject");

		// When an item is used it should adjust its internal use counter.
		// When the there are no more uses left the object should fail to call use
		// An item should not know what inventory it is in.
		return testResult.Result();	// TODO Needs implementing.
	}

	bool Tests::LocationObject()
	{
		TestResult testResult("LocationObject");

		// A location should have one or more exits.
		// Each exit is assigned a direction and a direction can only have one exit assigned to it.
		// An exit leads to another location, identified by its name.
		// A direction that does not have an exit will return an invalid location name ("").
		// A location will return a list of possible exits that it has.

		// Generate a location with a North and south exit
		SUD::LocationObject room;
		room.AddExit(SUD::Direction::EDirection::North, "The north door", "NorthRoom");
		room.AddExit(SUD::Direction::EDirection::South, "The south door", "SouthRoom");
		{
			TestResult subtest("Get Exit Tests");
			// Ask the location what the possible exits are (N&S should be the answer)
			const std::map<std::string, std::string> expected =
			{
				{"NORTH", "The north door"},
				{"SOUTH", "The south door"}
			};
			auto actual = room.GetExits();
			bool result = (actual.size() == expected.size());
			for (auto item = expected.begin(); item != expected.end() && result; ++item)
			{
				result = result && (actual[item->first] == item->second);
			}
			subtest.AddResult(result);
			testResult.AddResult(result);
		}
		{
			// Ask the location to get the destination when exiting East
			// Expected result = Invalid location name
			TestResult subtest("Test East Exit");
			const std::string expected = "";
			auto actual = room.GetDestination(SUD::Direction::EDirection::East);
			const bool result = (expected.compare(actual) == 0);
			subtest.AddResult(result);
			testResult.AddResult(result);
		}
		{
			// Ask the location to get the destination when exiting North
			// Expected result = NorthRoom
			TestResult subtest("Test North Exit");
			const std::string expected = "NorthRoom";
			auto actual = room.GetDestination(SUD::Direction::EDirection::North);
			const bool result = (expected.compare(actual) == 0);
			subtest.AddResult(result);
			testResult.AddResult(result);
		}
		return testResult.Result();
	}

	

	bool Tests::PlayerObject()
	{
		TestResult testResult("PlayerObject");

		// A player has an inventory
		// A player has a current location
		// A player can move to a new location
		// When the player moves they should have their new location and exits described to them.
		// A player should be able to pick up items in their current location.

		return testResult.Result();	// TODO Needs implementing.
	}


}