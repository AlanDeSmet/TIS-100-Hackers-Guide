#include "random.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <time.h>


int32_t progress_count;
time_t progress_start;

void init_progress_tracker(int32_t count) {
	progress_count = count;
	progress_start = time(NULL);
}

void report_progress_tracker(int32_t i) {
	float rate;
	float portion = (float)i / (float)progress_count;
	int32_t todo = progress_count - i;
	float left;
	time_t now = time(NULL);
	rate = ((float)i)/(float)(now - progress_start);
	left = ((float)todo)/rate;

	printf("%10d (%.2f%%, %.0f per second, %.0f seconds to go)              \r", i, portion*100.0, rate, left);
	fflush(stdout);
}


int validate(int32_t *expected,int32_t seed) {
	int i;
	math_randomseed(seed);
	for(i=0; i < 39; i++) {
		int32_t this = math_random(1,3);
		if(this != *expected) { return 0; }
		expected++;
	}
	for(i=0; i < 39; i++) {
		int32_t this = math_random(1,999);
		if(this != *expected) { return 0; }
		expected++;
	}
	for(i=0; i < 39; i++) {
		int32_t this = math_random(-3,-1);
		if(this != *expected) { return 0; }
		expected++;
	}
	for(i=0; i < 39; i++) {
		int32_t this = math_random(-99,999);
		if(this != *expected) { return 0; }
		expected++;
	}
	return 1;
}

#define REPORT_FREQ 500000

int main(int argc, char * argv[]) {
	int i = 0;
	float f;
	int32_t out;
	int32_t expected[39*4];

	for(i = 0; i < 39*4; i++) {
		char line[64];
		char * got;
		if(feof(stdin) || ferror(stdin)) {
			printf("Unexpected end of input");
			exit(1);
		}
		fgets(line, sizeof(line)-1, stdin);
		expected[i] = atoi(line);
	}

	init_progress_tracker(INT32_MAX);
	for(i = 0; i < INT32_MAX; i++) {
		if((i%REPORT_FREQ) == 0) {
			report_progress_tracker(i);
		}
		if(validate(expected, i)) {
			printf("\nThe seed is %d\n", i);
			return 0;
		}
	}

	/*validate(55847854);*/

	return 0;
}
