#include "random.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char * argv[]) {
	int i = 0;
	float f;
	int32_t out;
	int32_t seed;
	int32_t spec;
	int32_t test;
	if(argc != 3) {
		printf("Usage: %s <SPEC number> <test number>", argv[0]);
		exit(1);
	}
	spec = atoi(argv[1]);
	test = atoi(argv[2]);
	
	seed = calculate_seed(spec,test);
	math_randomseed(seed);
	for(i=0; i < 39; i++) { printf("%d\n", math_random(1,3)); }
	for(i=0; i < 39; i++) { printf("%d\n", math_random(1,999)); }
	for(i=0; i < 39; i++) { printf("%d\n", math_random(-3,-1)); }
	for(i=0; i < 39; i++) { printf("%d\n", math_random(-99,999)); }
	return 0;
}
