#ifndef INCLUDE_TIS_100_RANDOM_H
#define INCLUDE_TIS_100_RANDOM_H

#include <stdint.h>

float math_randomseed(int32_t idum);
int32_t math_random(int32_t mini, int32_t maxi);
int32_t calculate_seed(int32_t specnum, int32_t test);

#endif
