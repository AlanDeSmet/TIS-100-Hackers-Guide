math.random() and math.randomseed()
===================================

In [Puzzle Lua](lua.html) `math.random(min,max)` and `math.randomseed(seed)` are not from the main Lua distribution, which is based on the C library's `rand()` and `srand(int)`.

Instead they come from [MoonSharp](http://www.moonsharp.org/), a Lua interpreter written in C#.  That is calling into Unity's System.Random in [Random.cs](https://github.com/Unity-Technologies/mono/blob/unity-staging/mcs/class/corlib/System/Random.cs).  That, and thus TIS-100, is based on `ran3()` from _Numerical Recipes in C, Second Edition_.  _That_ is based on a random number generator by Donald Knuth in _Seminumerical Algorithms, second edition_, volume 2 of _The Art of Computer Programming_, sections 3.2-3.3.

Differences from the _Numerical Recipes_ version (besides the interface):  1. MBIG has been replaced with 2147483647 , which is 2<sup>31</sup>-1, or the largest 32-bit signed integer using two's complement.  2. The outer labs() call in the initial calculation of mj was removed.

Like math.random, the order of the arguments doesn't matter.  Similarly to Lua, if a single argument is given, it behaves as if 1 was given as the second argument. _Unlike_ Lua, a single negative argument is valid, so math.random(-2) is equivalent to math.random(-2,1), while official Lua would fail with "bad argument #1 to 'random' (interval is empty)".  Given no arguments, returns 0.  The reference C# linking Random.cs to Lua is in 
[MathModule.cs](https://github.com/xanathar/moonsharp/blob/master/src/MoonSharp.Interpreter/CoreLib/MathModule.cs#L261-L294).

Implementations:

   * C#: Use Unity's [Random.cs](https://github.com/Unity-Technologies/mono/blob/unity-staging/mcs/class/corlib/System/Random.cs) and Moonsharp's [MathModule.cs](https://github.com/xanathar/moonsharp/blob/master/src/MoonSharp.Interpreter/CoreLib/MathModule.cs#L261-L294).  This is the canonical version.
   * C/C++: [random.c](random/random.c) [random.h](random/random.h). Does not implement single or zero argument versions.
   * Lua: [random.lua](random/random.lua)

[A small test suit for a C or Lua implementation of the random functions is available in the "random" subdirectory in this project at GitHub.](https://github.com/AlanDeSmet/TIS-100-Hackers-Guide/tree/gh-pages)

Many thanks to Rohansi on Reddit for discovering the MoonSharp to Unity to C# link and pointing me at the C# implementation.  Many, many thanks to AapOpSokken on Reddit for extensive additions and catching of details.
