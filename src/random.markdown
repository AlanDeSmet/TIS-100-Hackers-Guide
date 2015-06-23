math.random() and math.randomseed()
===================================

In [Puzzle Lua](lua.html) `math.random(min,max)` and `math.randomseed(seed)` are not from the main Lua distribution, which is based on the C library's `rand()` and `srand(int)`.

Instead they probably come from [MoonSharp](http://www.moonsharp.org/), a Lua interpreter written in C#.  That is probably based on C#'s [random.cs](http://referencesource.microsoft.com/#mscorlib/system/random.cs,bb77e610694e64ca). That, and thus TIS-100, is based on `ran3()` from _Numerical Recipes in C, Second Edition_.  _That_ is based on a random number generator by Donald Knuth in _Seminumerical Algorithms, second edition_, volume 2 of _The Art of Computer Programming_, sections 3.2-3.3.

The only difference from the _Numerical Recipes_ version (besides the interface) is that MBIG has been replaced with 2147483647 , which is 2<sup>31</sup>-1, or the largest 32-bit signed integer using two's complement.

[Implementations in C and Lua, as well as a simple test suite based on output from TIS-100 are available](random/)

