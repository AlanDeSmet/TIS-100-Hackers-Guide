#include "random.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>


typedef struct progress_tracker {
	int32_t count;
	time_t start;
} progress_tracker;

progress_tracker * new_progress_tracker(int32_t count) {
	progress_tracker * ret = malloc(sizeof(progress_tracker));
	ret->count = count;
	ret->start = time(NULL);
	return ret;
}

void report_progress_tracker(progress_tracker * p, int32_t i) {
	float rate;
	float portion = (float)i / (float)p->count;
	int32_t todo = p->count - i;
	float left;
	time_t now = time(NULL);
	rate = ((float)i)/(float)(now - p->start);
	left = ((float)todo)/rate;

	printf("%d (%.2f%%, %.0f per second, %.0f seconds to go)\n", i, portion*100.0, rate, left);
}

void delete_progress_tracker(progress_tracker * p) {
	free(p);
}


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

	progress_tracker * p = new_progress_tracker(INT32_MAX);
	for(i = 0; i < INT32_MAX; i++) {
		if((i%REPORT_FREQ) == 0) {
			report_progress_tracker(p, i);
		}
		if(validate(i)) {
			printf("The seed is %d\n", i);
			return 0;
		}
	}
	delete_progress_tracker(p);

	/*validate(55847854);*/

	/* run_test(55847854); */ /* Pre-July 13 */
	return 0;
}
