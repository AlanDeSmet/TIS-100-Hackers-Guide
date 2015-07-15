math.random() and math.randomseed()
===================================

In [Puzzle Lua](lua.html) `math.random(min,max)` and `math.randomseed(seed)` are not from the main Lua distribution, which is based on the C library's `rand()` and `srand(int)`.

Instead they probably come from [MoonSharp](http://www.moonsharp.org/), a Lua interpreter written in C#.  That is probably calling into Unity's System.Random.  That is probably based on C#'s [random.cs](http://referencesource.microsoft.com/#mscorlib/system/random.cs,bb77e610694e64ca). That, and thus TIS-100, is based on `ran3()` from _Numerical Recipes in C, Second Edition_.  _That_ is based on a random number generator by Donald Knuth in _Seminumerical Algorithms, second edition_, volume 2 of _The Art of Computer Programming_, sections 3.2-3.3.

There are two differences from the _Numerical Recipes_ version (besides the interface).  First, MBIG has been replaced with 2147483647 , which is 2<sup>31</sup>-1, or the largest 32-bit signed integer using two's complement.  Second, the outer labs() call in the initial calculation of mj was removed.

   * [random.c](random/random.c) [random.h](random/random.h) - Implementation of TIS-100's random number generator in C
   * [random.lua](random/random.lua) - Implementation of TIS-100's random number generator in Lua
   * [55847854.lua](random/55847854.lua) - Puzzle for TIS-100 that generates sequences for testing implementations.
   * [IN.1](random/IN.1), [IN.2](random/IN.2), [IN.3](random/IN.3), [IN.4](random/IN.4) - Test data
   * [Makefile](random/Makefile) - Runs tests against the above implementations

Many thanks to Rohansi on Reddit for discovering the MoonSharp to Unity to C# link and pointing me at the C# implementation.  Thanks to AapOpSokken on Reddit for catching that the labs() was removed.
