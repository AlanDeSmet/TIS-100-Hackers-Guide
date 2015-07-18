#! /usr/bin/lua

require "random"

local output

output= {0,0}
for i=1,1000 do
	x = math_random(1,2)
	output[x] = output[x] + 1
end
--print(output[1],output[2]);
assert(output[1] > 450 and output[1] < 550)
assert(output[2] > 450 and output[2] < 550)

output= {0,0}
for i=1,1000 do
	x = math_random(2,1)
	output[x] = output[x] + 1
end
--print(output[1],output[2]);
assert(output[1] > 450 and output[1] < 550)
assert(output[2] > 450 and output[2] < 550)

output= {0,0}
for i=1,1000 do
	x = math_random(2)
	output[x] = output[x] + 1
end
--print(output[1],output[2]);
assert(output[1] > 450 and output[1] < 550)
assert(output[2] > 450 and output[2] < 550)

output= {}
output[-1] = 0
output[-2] = 0
for i=1,1000 do
	x = math_random(-2,-1)
	output[x] = output[x] + 1
end
--print(output[-1],output[-2]);
assert(output[-1] > 450 and output[-1] < 550)
assert(output[-2] > 450 and output[-2] < 550)

output= {}
output[-1] = 0
output[-2] = 0
for i=1,1000 do
	x = math_random(-1,-2)
	output[x] = output[x] + 1
end
--print(output[-1],output[-2]);
assert(output[-1] > 450 and output[-1] < 550)
assert(output[-2] > 450 and output[-2] < 550)

output= {}
for i=-2,1 do output[i] = 0 end
for i=1,1000 do
	x = math_random(-2)
	output[x] = output[x] + 1
end
--print(output[-2],output[-1],output[0],output[1]);
for i=-2,1 do
	assert(output[i] > 200 and output[i] < 300)
end

print("Lua unit tests passed")
os.exit(0)
