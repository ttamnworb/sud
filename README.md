# SUD (Single User Dungeon)
This is the very beginings of a Text Adventure Game.

# Building
There is a Microsoft Visual Studio 2022 solution and project that can be used to build the code. If another environment is required all of the files are within a single directory and can be built into objects and then linked into an executable with standard platform libraries.

# Installation
The output is a single executable which does not need installation.  It can be run from Visual Studio or Windows Explorer.

# Usage
At this stage the application is not interactive, when it starts it executes the in built unit tests and then waits until the enter key is pressed to exit.

# Cross platform
At present there is nothing within the code that should not be fully portable to another platform.  

# Design
The current design is very basic.
There is a Game object that holds all the items and locations for the game.  When the Game object is created it will load the data from a file, parse it into memory, validate there is a complete set of data and then start the main game loop.  The loop will show the information about the current location, the possible exits and wait for the user to enter a command, Go east, use potion, etc.  The game will then act upon that command and resume the loop.
There are LocationObjects, which are rooms, corridiors, etc and these could have items within (provided by the Inventory class).  When the PlayerObject enters a location it should be oossible for the player to exchange items between their inventory and the locations inventory, picking up and dropping things.

# Future work
1. Finishing the code, specifically the Load/Save functionality.
2. Switch to a proper unit test framework (unable to get MS C++ Unit test framework to work at this time)
3. Implementing the main game loop.
4. At present items are index by a name variable, which is a string.  This should be replaced with a method that will allow quicker searching.  (It was done like this to make it easier to debug)
5. Add NPCs and combat.
6. Multiple players (The player object supports multiple instances, but the interface won't)
