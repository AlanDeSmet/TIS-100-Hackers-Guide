#! /usr/bin/lua

require "random"

if #arg ~= 2 then
	print("Usage:", arg[0], "<SPEC number> <test number>")
	os.exit(1)
end

spec = tonumber(arg[1])

test = tonumber(arg[2])
if test < 1 or test > 3 then
	print("Test number is unlikely to be outside of the range 1 through 3.", arg[2], "was received.")
	os.exit(1)
end
 
seed = calculate_seed(arg[1], test)
math_randomseed(seed)
for i=1,39 do print(math_random(1,3)) end
for i=1,39 do print(math_random(1,999)) end
for i=1,39 do print(math_random(-3,-1)) end
for i=1,39 do print(math_random(-99,999)) end
