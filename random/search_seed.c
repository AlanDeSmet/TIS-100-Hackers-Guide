#include "random.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>


int validate(int32_t seed) {
	int i;
	int results[] = { 2, 1, 3, 2, 2, 3, 3, 2, 3, 3, 3, 2, 1, 2, 1, 2, 1, 3, 3, 2, 3, 3, 2, 2, 2, 1, 1, 2, 1, 1, 2, 1, 3, 2, 1, 2, 3, 3, 3 };
	math_randomseed(seed);
	for(i=0; i < 39; i++) {
		int32_t this = math_random(1,3);
		if(this != results[i]) {
			return 0;
		}
	}
	return 1;
}

#define REPORT_FREQ 100000

int main(int argc, char * argv[]) {
	int i = 0;
	float f;
	int32_t out;
	time_t start, now;

	start = time(NULL);
	for(i = 0; i < INT32_MAX; i++) {
		if((i%REPORT_FREQ) == 0) {
			float rate;
			float portion = (float)i / (float)INT32_MAX;
			int32_t todo = INT32_MAX - i;
			float left;
			now = time(NULL);
			rate = ((float)i)/(float)(now - start);
			left = ((float)todo)/rate;

			printf("%d (%.2f%%, %.0f per second, %.0f seconds to go)\n", i, portion*100.0, rate, left);
		}
		if(validate(i)) {
			printf("The seed is %d\n", i);
			return 0;
		}
	}

	validate(55847854);

	/* run_test(55847854); */ /* Pre-July 13 */
	return 0;
}
