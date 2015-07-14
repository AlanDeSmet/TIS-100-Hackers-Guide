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

a.out: random.o validator.o
	gcc -o $@ $^ -lm

search: random.o search_seed.o
	gcc -o $@ $^ -lm

IN: IN.1 IN.2 IN.3 IN.4
	cat IN.1 IN.2 IN.3 IN.4 > $@

1.IN: 1.IN.1 1.IN.2 1.IN.3 1.IN.4
	cat 1.IN.1 1.IN.2 1.IN.3 1.IN.4 > $@

.c.o:
	gcc -g -c -o $*.o $<
	#gcc -g -c -o $*.o $<
