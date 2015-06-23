test: testlua testc

clean:
	rm -f a.out IN lua.TEST c.TEST

testlua: IN random.lua
	lua random.lua > lua.TEST
	diff IN lua.TEST

testc: IN a.out
	./a.out > c.TEST
	diff IN c.TEST

all: IN a.out

a.out: random.c
	gcc $< -lm -o $@

IN: IN.1 IN.2 IN.3 IN.4
	cat IN.1 IN.2 IN.3 IN.4 > $@

