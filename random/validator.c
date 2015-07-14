#include "random.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char * argv[]) {
	int i = 0;
	float f;
	int32_t out;
	math_randomseed(55847854);
	for(i=0; i < 39; i++) { printf("%d\n", math_random(1,3)); }
	for(i=0; i < 39; i++) { printf("%d\n", math_random(1,999)); }
	for(i=0; i < 39; i++) { printf("%d\n", math_random(-3,-1)); }
	for(i=0; i < 39; i++) { printf("%d\n", math_random(-99,999)); }
	return 0;
}
