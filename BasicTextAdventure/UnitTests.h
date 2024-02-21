#pragma once

/// This is by no means and exclusive set of tests.
// It needs to be in a proper test framework, but I couldn't get that to build/


namespace SUD_Tests
{
	class Tests
	{
	public:
		/// <summary>
		/// Perform all unit tests
		/// </summary>
		Tests();


		/// <summary>
		/// Perform the base object tests
		/// </summary>
		/// <returns>True if all tests pass</returns>
		bool BaseObject();

		/// <summary>
		/// Perform the direction tests
		/// </summary>
		/// <returns>True if all tests pass</returns>
		bool Direction();

		/// <summary>
		/// Perform the game tests
		/// </summary>
		/// <returns>True if all tests pass</returns>
		bool Game();

		/// <summary>
		/// Perform the inventory tests
		/// </summary>
		/// <returns>True if all tests pass</returns>
		bool Inventory();
		
		/// <summary>
		/// Perform the item object tests
		/// </summary>
		/// <returns>True if all tests pass</returns>
		bool ItemObject();
		
		/// <summary>
		/// Perform the tests on the location object
		/// </summary>
		/// <returns>True if all tests pass</returns>
		bool LocationObject();

		/// <summary>
		/// Perform the player object tests
		/// </summary>
		/// <returns>True if all tests pass</returns>
		bool PlayerObject();



	};
}