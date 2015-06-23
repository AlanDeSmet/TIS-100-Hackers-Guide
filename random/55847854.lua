function get_name()
	return "RANDOM VALIDATOR"
end

function get_description()
	return { "Calls math.random(1,3) 39 times",
		"Then math.random(1,999) 39 times",
		"Then math.random(-3,-1) 39 times",
		"Then math.random(-999,999) 39 times",
	}
end

function get_streams()
	math.randomseed(55847854)
	-- It's important to build an entire stream before
	-- moving to the next so it's clear how math.random
	-- is being called.
	input1 = {}
	for i = 1,39 do input1[i] = math.random(1, 3) end
	input2 = {}
	for i = 1,39 do input2[i] = math.random(1, 999) end
	input3 = {}
	for i = 1,39 do input3[i] = math.random(-3, -1) end
	input4 = {}
	-- We only go to down to -99 because as of June 22, 3 digit
	-- negative numbers are broken across two lines of the display
	for i = 1,39 do input4[i] = math.random(-99, 999) end
	return {
		{ STREAM_INPUT, "IN.1", 0, input1 },
		{ STREAM_INPUT, "IN.2", 1, input2 },
		{ STREAM_INPUT, "IN.3", 2, input3 },
		{ STREAM_INPUT, "IN.4", 3, input4 },
	}
end

function get_layout()
	return { 
		TILE_COMPUTE, 	TILE_COMPUTE, 	TILE_COMPUTE, 	TILE_COMPUTE,
		TILE_COMPUTE, 	TILE_COMPUTE,	TILE_COMPUTE, 	TILE_COMPUTE,
		TILE_COMPUTE, 	TILE_COMPUTE,	TILE_COMPUTE, 	TILE_COMPUTE,
	}
end
