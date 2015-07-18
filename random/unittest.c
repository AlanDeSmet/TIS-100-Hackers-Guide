#include "random.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int counts[10];
void wipe_counts() {
	int i;
	for(i = 0; i < (sizeof(counts)/sizeof(counts[0])); i++) {
		counts[i] = 0;
	}
}

void myassert_impl(char * filename, int linenum, int test, char * expr) {
	if(test) { return; }
	fprintf(stderr, "ERROR: %s:%d: %s evaluated to false.", filename, linenum, expr);
	exit(1);
}

#define myassert(test) myassert_impl(__FILE__, __LINE__, test, #test)


int main(int argc, char * argv[]) {
	int i = 0;
	float f;

	wipe_counts();
	for(i = 0; i < 1000; i++) { counts[math_random(1,2)]++; }
	/*printf("%d %d\n", counts[1], counts[2]);*/
	myassert(counts[1] > 450 && counts[1] < 550);
	myassert(counts[2] > 450 && counts[2] < 550);

	wipe_counts();
	for(i = 0; i < 1000; i++) { counts[math_random(2,1)]++; }
	/*printf("%d %d\n", counts[1], counts[2]);*/
	myassert(counts[1] > 450 && counts[1] < 550);
	myassert(counts[2] > 450 && counts[2] < 550);

	wipe_counts();
	for(i = 0; i < 1000; i++) { counts[math_random(-2,-1)+3]++; }
	/*printf("%d %d\n", counts[1], counts[2]);*/
	myassert(counts[1] > 450 && counts[1] < 550);
	myassert(counts[2] > 450 && counts[2] < 550);

	wipe_counts();
	for(i = 0; i < 1000; i++) { counts[math_random(-1,-2)+3]++; }
	/*printf("%d %d\n", counts[1], counts[2]);*/
	myassert(counts[1] > 450 && counts[1] < 550);
	myassert(counts[2] > 450 && counts[2] < 550);

	fprintf(stderr, "C unit tests passed\n");
	return 0;
}
