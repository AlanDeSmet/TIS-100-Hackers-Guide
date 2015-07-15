-- Based on http://tis100.complexity.nl/puzzles/30000000.lua by AapOpSokken on Reddit at https://www.reddit.com/r/tis100/comments/3d7qjz/what_are_the_new_random_number_seeds_for_tests/

function get_name()
    return "math.randomseed test"
end

function get_description()
	return { "RETURNS THE RANDOM SEED IN POS/NEG." }
end

lastseed = 0

math.randomseed = function (s) lastseed = s end

function get_streams()
    input1 = {}
    input2 = {}
    pos = lastseed or 1234
    neg = - pos
    for i = 39,1,-1 do
        input1[i] = pos % 10
        pos = (pos - (pos % 10)) / 10
        input2[i] = neg % 10
        neg = (neg - (neg % 10)) / 10
    end
    return {
        { STREAM_INPUT, "POS", 1, input1 },
        { STREAM_INPUT, "NEG", 2, input2 },
    }
end

function get_layout()
    return { 
        TILE_COMPUTE,     TILE_COMPUTE,    TILE_COMPUTE,     TILE_COMPUTE,
        TILE_COMPUTE,     TILE_COMPUTE,    TILE_COMPUTE,     TILE_COMPUTE,
        TILE_COMPUTE,     TILE_COMPUTE,    TILE_COMPUTE,     TILE_COMPUTE,
    }
end
