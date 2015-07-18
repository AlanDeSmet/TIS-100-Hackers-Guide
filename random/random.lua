-- math_randomseed and math_random are based on ran3 from 
-- Numerical Methods in C, Second Edition.  It has been 
-- modified to roughly match the Lua math.random/math.randomseed
-- interface.

-- This is MAX_INT, and matches TIS-100's behavior
local MBIG = 2147483647
local MSEED = 161803398
local MZ = 0
local FAC = (1.0/MBIG)

local inext = 0
local inextp = 31
local ma = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

function math_randomseed(idum)
	local mj = MSEED - math.abs(idum)
	
	mj = mj % MBIG
	ma[55] = mj
	local mk = 1
	local i
	for i=1,54 do
		local ii = (21*i)%55
		ma[ii] = mk
 		mk = mj - mk
 		if mk < MZ then mk = mk + MBIG end
 		mj = ma[ii]
	end

	local k
	for k=1,4 do
		for i=1,55 do
			ma[i] = ma[i] - ma[1+(i+30)%55]
			if ma[i] < MZ then ma[i] = ma[i] + MBIG end
		end
	end
	inext = 0
	inextp = 31
end

function math_random(mini, maxi)
	if(mini > maxi) then
		tmp = maxi
		maxi = mini
		mini = tmp
	end

	inext = inext+1
 	if inext == 56 then inext=1 end
	inextp = inextp+1
 	if inextp == 56 then inextp=1 end
 	local mj = ma[inext] - ma[inextp]
 	if mj < MZ then mj = mj + MBIG end
 	ma[inext] = mj
 	local f = mj * FAC;
	local range = 1+maxi-mini;
 	return math.floor((f * range) + mini);
end

math_randomseed(0)

function calculate_seed(specnum, test)
	return (specnum * 100 + test - 1) % 4294967296 -- 2^32
end

