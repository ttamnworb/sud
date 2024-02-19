#pragma once

/// This is by no means and exclusive set of tests.
// It needs to be in a proper test framework, but I couldn't get that to build/


namespace SUD_Tests
{
	/// <summary>
	/// Perform all unit tests
	/// </summary>
	void Tests();

	/// <summary>
	/// Perform the tests on the location object
	/// </summary>
	void TestLocation();

	/// <summary>
	/// Perform the inventory tests
	/// </summary>
	void 	TestInventory();
}