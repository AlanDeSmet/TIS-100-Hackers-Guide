test: testlua testc

clean:
	rm -f validator IN lua.TEST c.TEST random.o validator.o 55847854.1.IN 55847854.2.IN

testlua: 55847854.1.IN 55847854.2.IN random.lua validator.lua
	lua unittest.lua
	lua validator.lua 55847854 1 > lua.TEST
	diff 55847854.1.IN lua.TEST
	lua validator.lua 55847854 2 > lua.TEST
	diff 55847854.2.IN lua.TEST

testc: 55847854.1.IN 55847854.2.IN validator
	./validator 55847854 1 > c.TEST
	diff 55847854.1.IN c.TEST
	./validator 55847854 2 > c.TEST
	diff 55847854.2.IN c.TEST

validator: random.o validator.o
	gcc -o $@ $^ -lm

unittest: random.o unittest.o
	gcc -o $@ $^ -lm

%.IN: %.IN.1 %.IN.2 %.IN.3 %.IN.4
	cat $^ > $@

.c.o:
	gcc -g -c -o $*.o $<
	#gcc -O3 -march=native -c -o $*.o $<
