Lua Library
===========

These are the functions and variables exposed to the [Lua puzzle programs](lua.html)

   * _Base_ are part of the base Lua release
   * _Moon_ are new to MoonSharp
   * _TIS_ are new to TIS-100

Constants
---------

Lua puzzles should probably not rely on specific values for the `STREAM_` and `TILE_` constants.

   * **`STREAM_INPUT`**  = 2000. _TIS_

   * **`STREAM_OUTPUT`** = 2001. _TIS_

   * **`STREAM_IMAGE`**  = 2002. _TIS_

   * **`TILE_COMPUTE`**  = 1000. _TIS_

   * **`TILE_MEMORY`**   = 1001. _TIS_

   * **`TILE_DAMAGED`**  = 1002. _TIS_

   * **`_VERSION`**      = "MoonSharp 0.9.5.0". _Moon_

Functions
---------

   * **`assert(v [, message])`** - _Base_ As of July 5, 2015, if `v` is false, causes compilation to fail with a "The script took too long to finish executing and was aborted" error.  Otherwise does nothing.  _Likely of dubious use in puzzle Lua._ [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-assert).  (In theory: If `v` is false, exits with message `message` or "assertion failed!" if no `message` is specified. Otherwise returns all arguments. )

   * **`collectgarbage([opt [, arg]])`** - _Base_ Interface for managing garbage collection. _Likely of dubious use in puzzle Lua._ [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-collectgarbage). **TODO** What does this do in practice?

   * **`error(message [, level])`** -  _Base_ As of July 5, 2015, causes compilation to fail with a "The script took too long to finish executing and was aborted" error.  _Likely of dubious use in puzzle Lua._ [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-error). (In theory: throws an error.)

   * **`ipairs(t)`** - _Base_ Iterates over the table `t` as though it was an array, returning the keys 1, 2,... and their matching values until the next integer key is missing. [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-ipairs). Example:

		local input = { 1, 2, 3, 4, 5 }
		local output = {}
		for i,v in ipairs(input) do
			output[i] = input[i] * 2
		end

   * **`next(table [, index])`** - _Base_ Returns the next index and value from the `table`. If `index` is nil, returns the first index and value. Items in the table may be returned in any order.  Adding a new index to the table may cause existing indices to be invalid.  In most cases `pairs()` or `ipairs()` will be simpler.  [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-next)

   * **`pack(...)`** - _Moon_ Alias for `table.pack`.

   * **`pairs(t)`** - _Base_ Iterates over all index value pairs in table `t`.  If the table is being used as an array with integer indices, `ipairs()` may be a better solution.  [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-pairs)

   * **`print(...)`** - _Base_ Prints one or more values separated with tabs and terminated with a newline. _Likely of dubious value in puzzle Lua._ [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-print)

   * **`select(index, ...)`** - _Base_ If `index` is a integer value greater or equal to 1, returns remaining arguments from that point forward. [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-select)

   * **`tonumber(e [, base])`** - _Base_ Return `e` as a number. If `base` is specified, `e` is interpreted as being in that base. Return nil is e cannot be parsed. [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-tonumber)

   * **`tostring(v)`** - _Base_ Return `v` as a string. Numbers are converted to a string representation. Functions and tables return "function: _address_" and "table: _address_" respectively. [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-tostring)

   * **`type(v)`** - _Base_ Returns a string describing the type of `v`.  Responses include "string", "number", "boolean", "nil", "table", and "function".   May return "userdata" or "thread" in some cases.  [Lua documentation](http://www.lua.org/manual/5.2/manual.html#pdf-type)

   * **`unpack(list [, i [, j]]))`** - _Moon_ Alias for `table.unpack`.


math
----

The math library

   * **`math.abc`** - 

   * **`math.acos`** - 

   * **`math.asin`** - 

   * **`math.atan`** - 

   * **`math.atan2`** - 

   * **`math.ceil`** - 

   * **`math.cos`** - 

   * **`math.cosh`** - 

   * **`math.deg`** - 

   * **`math.exp`** - 

   * **`math.floor`** - 

   * **`math.fmod`** - 

   * **`math.frexp`** - 

   * **`math.ldexp`** - 

   * **`math.log`** - 

   * **`math.max`** - 

   * **`math.min`** - 

   * **`math.modf`** - 

   * **`math.pow`** - 

   * **`math.rad`** - 

   * **`math.random`** - 

   * **`math.randomseed`** - 

   * **`math.sin`** - 

   * **`math.sinh`** - 

   * **`math.sqrt`** - 

   * **`math.tan`** - 

   * **`math.tanh`** - 

   * **`math.pi`** 3.14159265358979 

   * **`math.huge`** 1.79769313486232E+308 **TODO** Is this infinity?






Other
-----

   * **`_G`** - _Base Lua._ A table containing all of these variables, tables, and functions, including `_G` itself.

   * **`bit32`** -        TABLE

   * **`_MOONSHARP`** -   Information about the MoonSharp implementation.  It is recommended that Lua puzzles do not interact with these variables.  The below values are from the Linux version of TIS-100 and may vary on other platforms.

     * **`is_aot`** = false
     * **`is_clr4`** = false
     * **`is_mono`** = true
     * **`is_pcl`** = false
     * **`is_unity`** = true
     * **`luacompat`** = "5.2"
     * **`platform`** = "limited.unity.mono.clr2"
     * **`version`** = "0.9.5.0"

   * **`package.loaded`** - `package` only contains `loaded`

     *  **`string`** TABLE
     *  **`table`** TABLE
     *  **`math`** TABLE
     *  **`bit32`** TABLE

   * **`string`** -       TABLE

   * **`table`** -        TABLE

Not Available
-------------

These functions are present in standard Lua, but are not available in TIS-100. 

   * `coroutine`
   * `debug`
   * `dofile`
   * `load`
   * `loadfile`
   * `loadstring`
   * `module`
   * `os`
   * `pcall`
   * `rawequal`
   * `rawget`
   * `rawlen`
   * `rawset`
   * `require`
   * `setmetatable`
   * `xpcall`
