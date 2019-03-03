Save File Format EARLY DRAFT
================

**This is an early draft**

Save files are stored in a user specific location:

   * Windows: `%userprofile%\Documents\My Games\TIS-100\(USERID)\save and save.dat`
   * Mac OS X: `~/Library/Application Support/TIS-100/0/save and save.dat`
   * Linux: `~/.local/share/TIS-100/$(USERID)/save and save.dat`

$(USERID) is a integer number, not zero padded. It may be 17 or 18 digits long.
    
Filename
--------

Save filenames are composed of three parts:

	BASE.I.txt

For built in puzzles, the BASE filename is the segment number (for example "00150" for the first puzzle, SELF-TEST DIAGNOSTIC).  The number is always 0 padded to 5 digits
For custom puzzles, it is the prefix "SPEC", followed by the 8 digit SPEC number(for example "19700519").

I is 0, 1, or 2, and correspond with the first, second, and third save slots, respectively.  The number corresponds with the slot, not the order it was saved in.  So if a player selects the third spot at the first and only place to enter a solution, only a "2" file will exist.

.txt is fixed.


File Format
-----------

The file is broken into nodes.  The nodes are numbered starting with 0 and incrementing up to 11.  The numbers correspond with the nodes in TIS-100 going from left to right and moving down a row and repeating upon reaching the end of a row.

_Memory and damaged nodes are skipped._  So changing the layout of a puzzle will change which nodes various sections of code appear in.  If there is a surplus of code TODOCHECK it will be appended to the last node until it runs out of space.

TODO: How are too long lines handled?

TODO: How are spurious @ signs handled?

TODO: How are too long nodes handled?

TODO: What if the blank line between nodes is missing?

A node begins at the start of a line with an at sign ("@") immediately followed by a node number.  The following lines, up to 15, are the node's program.  There is then a blank line if another node follows.  If a node has no code, there will be two blank lines between it and the next node.

	
save.dat
--------

save.dat contains the most recent and lowest scores a user as achieved for a given puzzle in nodes, cycles, and instructions.

	Best.61212.Nodes = 6
	Best.62711.Cycles = 3768
	Best.62711.Instructions = 51

	Last.61212.0.Nodes = 6
	Last.62711.0.Cycles = 3768
	Last.62711.0.Instructions = 51
	Last.SPEC76722950.0.Cycles = 7061

They are sorted Best before Last, built in before custom, then by number, for Last scores which save slot, an finally Cycles, then Instructions Nodes.  This corresponds with a direct sort of the ASCII values.

The end of the file has three additional values:

	NewUniquePlayerID = 260648815294639196
	Options.Fullscreen = False
	TutorialSeen = True
  
TODO: Are there entries for a puzzle that exists but hasn't been attempted?

TODO: Are entries needed for TIS-100 to "see" the save files?



