Puzzle Lua
==========

Puzzles in TIS-100 are implemented as [Lua](http://www.lua.org/) programs.

As of June 24, 2015, TIS-100 uses [MoonSharp 0.9.5.0](http://www.moonsharp.org/) to interprete the puzzles.

A puzzle must implement the following functions.  None of the functions take arguments.

Global variables do persist between function calls.  Global variables are discarded when TIS-100 notices and loads an updated version of the puzzle.

[Notes on matching the style used by the official puzzles](lua-style.html).




### get_name()

`get_name()` is evaluated only once upon load, no later than upon entering the `SPECIFICATION EDITOR`.  It will not be re-evaluated on re-entering the `SPECIFICATION EDITOR`, nor upon entering the program editor. 

Returns a single string used as the puzzle's title.  If the name is longer than 33 characters, it will not display correctly on the program editing screen.
The name will be forced into upper case before displaying if it isn't already.


	function get_name()
		return "EXAMPLE PUZZLE"
	end



### get_description()

`get_description()` is evaluated only once upon entering the program editor. It will not be re-evaluated.

Returns an array (numbered table) of strings.  Each entry in the array is a bullet point in the puzzle description and will be word-wrapped.  The space to display the description is 33×6; the bullets themselves (">") are outside of this space.
The name will be forced into upper case before displaying if it isn't already.


	function get_description()
		return {
			"THIS IS THE FIRST BULLET POINT AND WILL BE WRAPPED",
			"THIS IS ANOTHER BULLET POINT",
			}
	end



### get_streams()

`get_streams()` is evaluated upon entering `SPECIFICATION EDITOR` to provide compiler error messages.  Evaluated twice more each time you enter the solution editor.  Evaluated once more after finishing the first page of a puzzle.  Evaluated once more after stopping a run.

Returns an array (numbered table) of input and output streams. Each stream is itself an array whose elements are

1. Type
2. Name
3. Position
4. Values

Type must be one of `STREAM_INPUT`, `STREAM_OUTPUT`, and `STREAM_IMAGE`.

The name is a simple string.  For `STREAM_INPUT`, the name should be 6 characters or less to avoid overlapping other streams.  For `STREAM_OUTPUT`, the name should be 8 characters or less.  The name is not used for `STREAM_IMAGE`.

The position is an integer from 0 through 3 representing the which column of nodes the stream is connected to. 0 represents the leftmost column and 3 the rightmost column.

The values are an array of integers.

For `STREAM_INPUT` and `STREAM_OUTPUT`, the values should be in
the range -999 through 999.  These streams can only display the
first 39 elements.

For `STREAM_IMAGE`, the values should be in the range 0 through
4.  There must be exactly 540 values, enough to fill a 30×18
image.  The image is filled top to bottom, left to right.  
The values are interpreted as:

<table>
<tr><th>Value</th><th colspan="3">Color</th></tr>
<tr><td style="text-align:center">0</td><td style="width: 0.6923em; background-color: black">&nbsp;</td><td>Black</td><td>#000000</td></tr>
<tr><td style="text-align:center">1</td><td style="width: 0.6923em; background-color: #464646">&nbsp;</td><td>Dark Grey</td><td>#464646</td></tr>
<tr><td style="text-align:center">2</td><td style="width: 0.6923em; background-color: #9c9c9c">&nbsp;</td><td>Light Grey</td><td>#9c9c9c</td></tr>
<tr><td style="text-align:center">3</td><td style="width: 0.6923em; background-color: #fafafa">&nbsp;</td><td>White</td><td>#fafafa</td></tr>
<tr><td style="text-align:center">4</td><td style="width: 0.6923em; background-color: #c00b0b">&nbsp;</td><td>Red</td><td>#c00b0b</td></tr>
</table>

([How STREAM_IMAGE behaves from the TIS-100 assembly point of view.](display.html))

`get_streams()` will be called twice, once for the first run of
a program and again for the second.  The first time math.random()
will be seeded with a fixed value to ensure that the first page
is identical between runs.
The fixed value is the `SPEC` or `SEGMENT` number.
The second time it is seeded with an
arbitrary number so that the second page is not predictable.
Generally the values from
`get_streams()` should be randomly generated.  Code should use
`math.random(min,max)` to generate random numbers.  Code should
not call `math.randomseed(seed)`.
`math.random(min,max)` is based on the C# System.Random, not the version from the primary Lua implementation. [Details on math.random's implementation are available.](random.html)

The left side of the display has space for approximately 41
columns of information.  Additional columns will be rendered
underneath the nodes.  A `STREAM_INPUT` occupied about 7 columns,
a `STREAM_OUTPUT` about 9, and a `STREAM_IMAGE` about 34.


<table>
<tr>
	<th>Type</th>
	<th>Min</th>
	<th>Max</th>
	<th>Max Count</th>
	<th>Width</th>
</tr>
<tr>
	<td><code>STREAM_INPUT</code></td>
	<td class="n">-999</td>
	<td class="n">999</td>
	<td class="n">39</td>
	<td class="n">7</td>
</tr>
<tr>
	<td><code>STREAM_OUTPUT</code></td>
	<td class="n">-999</td>
	<td class="n">999</td>
	<td class="n">39</td>
	<td class="n">9</td>
</tr>
<tr>
	<td><code>STREAM_IMAGE</code></td>
	<td class="n">0</td>
	<td class="n">4</td>
	<td class="n">540</td>
	<td class="n">34</td>
</tr>
</table>

	function get_streams()
		return { 
			{ STREAM_INPUT,  "IN", 1, {1,2,3,4,5,6} },
			{ STREAM_OUTPUT, "IN", 1, {1,2,3,4,5,6} },
		}
	end



### get_layout()

`get_layout()` is evaluated only once upon load, no later than upon entering the program editor.  It will not be re-evaluated on re-entering the `SPECIFICATION EDITOR`, nor upon entering the program editor. 

Returns an array (numbered table) of types for the nodes.  The array must have exactly 12 elements, and represent the nodes in a 4×3 arrangement.  Valid values are `TILE_COMPUTE` (program node, T21), `TILE_MEMORY` (stack memory node, T30), and `TILE_DAMAGED` (unusable damaged node).

In this example the entire right column is damaged, the top and bottom nodes on the left are stack nodes, and the rest are compute nodes.

	function get_layout()
		return { 
		TILE_MEMORY,   TILE_COMPUTE,  TILE_COMPUTE,  TILE_DAMAGED,
		TILE_COMPUTE,  TILE_COMPUTE,  TILE_COMPUTE,  TILE_DAMAGED,
		TILE_MEMORY,   TILE_COMPUTE,  TILE_COMPUTE,  TILE_DAMAGED,
		}
	end


