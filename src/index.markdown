TIS-100 Hacker's Guide
======================

TIS-100 Assembly
----------------


### Comments

The character # and any characters after it on a line are ignored.



### Labels

A label, if present, must be the first thing on the line. It is terminated with a : which must be immediately adjacent to the label. Valid characters for labels are **TODO**.  A line may only have a single label.



### Storage

**`ACC`** - Accumulator. Register.  Can be used as a _source_ or _destination_. Initialized to 0.  Reads and writes are instantaneous.

**`BAK`** - Backup. Register.  Only `SAV` and `SWP` interact with `BAK`.  The identifier “`BAK`” is never a valid identifier in a program.

**`NIL`** - Nothing. Register. Can be used as a _source_, in which case “0” is returned.  Can be used as a _destination_, which which case the value is discarded.

**`UP`**, **`DOWN`**, **`LEFT`**, **`RIGHT`** - Connections to adjacent nodes. Ports.  Can be used as a _source_ or a _destination_.  When used as a destination, the value cannot be read by the adjacent node in the same cycle that it was written to.  Blocks until a _destination_ value is used as a _source_ by the adjacent node or a _source_ is used as a _destination_ by an adjacent node.

**`ANY`** - Port. Can be used as a _source_, in which case the value will be read from the first port with a waiting value, as searched in this order: **TODO**.  Can be used as a _destination_, in which case the value will be written to the first port with a waiting read, as searched in this order: **TODO**.
or _destination_

**`LAST`** - Port. Refers to the same port used by the last reference to `ANY`, either in read or write.

_source_ can be ACC, NIL, UP, DOWN, LEFT, RIGHT, ANY, LAST, or an integer from −999 through 999, inclusive.  If the value is an integer, it is used directory.  Otherwise the register or port is read for the value to use.

_destination_ can be ACC, NIL, UP, DOWN, LEFT, RIGHT, ANY, or LAST.



### NOP - No Operation - 1 cycle

**Syntax:** `NOP`

Does nothing.



### MOV - Move - 1-2 cycles

**Syntax:** `MOV` _source_ _destination_

Reads a value from _source_ and write it to _destination_.  If _source_ is a port, blocks until a value is present.  If _destination_ is a port, blocks until the value is received.

1 cycle when writing ACC or NIL.

2 cycles when writing to UP, DOWN, LEFT, or RIGHT, assuming the neighboring node is willing to retrieve the value on the second cycle.  The data is not yet in the port until the end of the first cycle.



### SWP - Swap - 1 cycle

**Syntax:** `SWP`

Swaps the values of ACC and BAK



### SAV - Save - 1 cycle

**Syntax:** `SAV`

Copies the value of ACC to BAK



### ADD - Add - 1 cycle

**Syntax:** `ADD` _source_

The _source_ value is added to the value in ACC, and the result placed in ACC. Results greater than 999 are limited to 999.  Results less than −999 are limited to −999.



### SUB - Subtract - 1 cycle

**Syntax:** `SUB` _source_

The _source_ value is subtracted to the value in ACC, and the result placed in ACC. Results greater than 999 are limited to 999.  Results less than −999 are limited to −999.



### NEG - Negate - 1 cycle

**Syntax:** `NEG` _source_

The value in ACC is negative (swapped between positive and negative) and written back into ACC.  0 is left unchanged.



### JMP - Jump - 1 cycle

**Syntax:** `JMP` _label_

Transfer execution to the first instruction after _label_.



### JEZ - Jump if equal to zero - 1 cycle

**Syntax:** `JEZ` _label_

If the ACC is 0, transfer execution to the first instruction after _label_.



### JNZ - Jump if not equal to zero - 1 cycle

**Syntax:** `JNZ` _label_

If the ACC is not 0, transfer execution to the first instruction after _label_.



### JGZ - Jump if greater than zero - 1 cycle

**Syntax:** `JGZ` _label_

If the ACC is greater than 0, transfer execution to the first instruction after _label_.



### JLZ - Jump if less than zero - 1 cycle

**Syntax:** `JLZ` _label_

If the ACC is greater than 0, transfer execution to the first instruction after _label_.



### JRO - Jump relative offset - 1 cycle

**Syntax:** `JRO` _source_

Transfer execution to the offset specified by _source_.  Offset is measured in instructions. Negative offsets can be used to move jump backward, positive offsets to jump forward, or 0 to execute the JRO instruction again.



TIS-100 Puzzle Lua
------------------

Puzzles in TIS-100 are implemented as [Lua](http://www.lua.org/) programs.

A puzzle must implement the following functions.  None of the functions take arguments.



### get_name()

Returns a single string used as the puzzle's title.  If the name is longer than 33 characters, it will not display correctly on the program editing screen.
The name will be forced into upper case before displaying if it isn't already.

	function get_name()
		return “EXAMPLE PUZZLE”
	end



### get_description()

Returns an array (numbered table) of strings.  Each entry in the array is a bullet point in the puzzle description and will be word-wrapped.  The space to display the description is 33×6; the bullets themselves (">") are outside of this space.
The name will be forced into upper case before displaying if it isn't already.

	function get_description()
		return {
			"THIS IS THE FIRST BULLET POINT AND WILL BE WRAPPED",
			"THIS IS ANOTHER BULLET POINT",
			}
	end



### get_streams()

Returns an array (numbered table) of input and output streams. Each stream is itself an array whose elements are

1. Type
2. Name
3. Position
4. Values

Type must be one of STREAM_INPUT, STREAM_OUTPUT, and STREAM_IMAGE.

The name is a simple string.  For STREAM_INPUT, the name should be 6 characters or less to avoid overlapping other streams.  For STREAM_OUTPUT, the name should be 8 characters or less.  The name is not used for STREAM_IMAGE.

The position is an integer from 0 through 3 representing the which column of nodes the stream is connected to. 0 represents the leftmost column and 3 the rightmost column.

The values are an array of integers.

 For STREAM_INPUT and STREAM_OUTPUT, the values should be in
the range -999 through 999.  These streams can only display the
first 39 elements.

For STREAM_INPUT, the values should be in the range 0 through
4.  There must be exactly 540 values, enough to fill a 30×18
image.  The image is filled top to bottom, left to right.  
The values are interpreted as:

<table>
<tr><th>Value</th><th colspan="3">Color</th></tr>
<tr><td style="text-align:center">0</td><td style="width: 1em; background-color: black">&nbsp;</td><td>Black</td><td>#000000</td></tr>
<tr><td style="text-align:center">1</td><td style="width: 1em; background-color: #464646">&nbsp;</td><td>Dark Grey</td><td>#464646</td></tr>
<tr><td style="text-align:center">2</td><td style="width: 1em; background-color: #9c9c9c">&nbsp;</td><td>Light Grey</td><td>#9c9c9c</td></tr>
<tr><td style="text-align:center">3</td><td style="width: 1em; background-color: #fafafa">&nbsp;</td><td>White</td><td>#fafafa</td></tr>
<tr><td style="text-align:center">4</td><td style="width: 1em; background-color: #c00b0b">&nbsp;</td><td>White</td><td>#c00b0b</td></tr>
</table>

get_streams() will be called twice, once for the first run of
a program and again for the second.  The first time math.random()
will be seeded with a fixed value to ensure that the first page
is identical between runs.
The fixed value is the SPEC or SEGMENT number.
The second time it is seeded with an
arbitrary number so that the second page is not predictable.
Generally the values from
get_streams() should be randomly generated.  Code should use
math.random(min,max) to generate random numbers.  Code should
not call math.randomseed(seed).
math.random(min,max) is not the Lua standard one; it has been
replaced with a custom version (TODOVERIFY)to ensure consistent
results across platforms.

The left side of the display has space for approximately 41
columns of information.  Additional columns will be rendered
underneath the nodes.  A STREAM_INPUT occupied about 7 columns,
a STREAM_OUTPUT about 9, and a STREAM_IMAGE about 34.


<table>
<tr>
	<th>Type</th>
	<th>Min</th>
	<th>Max</th>
	<th>Max Count</th>
	<th>Width</th>
</tr>
<tr>
	<td>STREAM_INPUT</td>
	<td>-999</td>
	<td>999</td>
	<td>39</td>
	<td>7</td>
</tr>
<tr>
	<td>STREAM_OUTPUT</td>
	<td>-999</td>
	<td>999</td>
	<td>39</td>
	<td>9</td>
</tr>
<tr>
	<td>STREAM_IMAGE</td>
	<td>0</td>
	<td>4</td>
	<td>540</td>
	<td>34</td>
</tr>
</table>




### get_layout()

Returns an array (numbered table) of types for the nodes.  The array must have exactly 12 elements, and represent the nodes in a 4×3 arrangement.  Valid values are TILE_COMPUTE (program node, T21), TILE_MEMORY (stack memory node, T30), and TILE_DAMAGED (unusable damaged node).

In this example the entire right column is damaged, the top and bottom nodes on the left are stack nodes, and the rest are compute nodes.

	function get_layout()
		return { 
		TILE_MEMORY,   TILE_COMPUTE,  TILE_COMPUTE,  TILE_DAMAGED,
		TILE_COMPUTE,  TILE_COMPUTE,  TILE_COMPUTE,  TILE_DAMAGED,
		TILE_MEMORY,   TILE_COMPUTE,  TILE_COMPUTE,  TILE_DAMAGED,
		}
	end


