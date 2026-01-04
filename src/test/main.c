#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "../lib/random.h"

int main() {
    RNG *rng = RNG_create(time(NULL));
    printf("Valeur entiere : %lu\n", RNG_random_raw(rng));
    printf("Entre 0 et 1   : %lf\n", RNG_random(rng));
    printf("Entre 1 et 10  : %lf\n", RNG_random_range(rng, (uint64_t) 1, (uint64_t) 10));
}