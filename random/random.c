#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * This is based on ran3 from Numerical Methods in C, Second Edition
 * It has been modified to roughly match the Lua math.random/math.randomseed
 * interface.
 */

/* This is MAX_INT, and matches TIS-100's behavior */
#define MBIG 2147483647
#define MSEED 161803398
#define MZ 0
#define FAC (1.0/MBIG)

static int inext,inextp;
static long ma[56];

float math_randomseed(int32_t idum) {
	long mj,mk;
	int i,ii,k;
	mj=labs(MSEED-labs(idum));
	mj %= MBIG;
	ma[55]=mj;
	mk=1;
	for (i=1;i<=54;i++) {
		ii=(21*i) % 55;
		ma[ii]=mk;
		mk=mj-mk;
		if (mk < MZ) mk += MBIG;
		mj=ma[ii];
	}
	for (k=1;k<=4;k++)
		for (i=1;i<=55;i++) {
			ma[i] -= ma[1+(i+30) % 55];
			if (ma[i] < MZ) ma[i] += MBIG;
		}
	inext=0;
	inextp=31;
}

int32_t math_random(int32_t mini, int32_t maxi) {
	long mj;
	int32_t range;
	float f;

	if (++inext == 56) inext=1;
	if (++inextp == 56) inextp=1;
	mj=ma[inext]-ma[inextp];
	if (mj < MZ) mj += MBIG;
	ma[inext]=mj;
	f = mj*FAC;

	range = 1+maxi-mini;
	return floor(f * range) + mini;
}

