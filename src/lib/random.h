#ifndef RANDOM_H
#define RANDOM_H

typedef struct _RNG RNG;

RNG *RNG_create(uint64_t base);
void RNG_destroy(RNG *rng);

double RNG_random(RNG *rng);
uint64_t RNG_random_raw(RNG *rng);
double RNG_random_range(RNG *rng, uint64_t a, uint64_t b);

#endif