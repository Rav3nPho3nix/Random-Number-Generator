#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "random.h"

struct _RNG {
    uint64_t seed, prime, value;
};

bool _are_coprime(uint64_t a, uint64_t b);
uint64_t _gcd(uint64_t a, uint64_t b);

RNG *RNG_create(uint64_t base) {
    RNG *rng = malloc(sizeof(RNG));

    // Les nombres premiers
    uint64_t p1 = 9007199254740881;
    uint64_t p2 = 922337203685477647;

    // Calcule la seed
    uint64_t seed = base * __UINT64_MAX__;
    uint64_t offset = base * __UINT32_MAX__;

    // Fonction de chaos
    for (int i=0; i<10000; i++) {
        seed = ( ( ( (seed * p2) << 2 ) *p1 ) % __UINT16_MAX__ ) * ((p1*p2)%__UINT32_MAX__) ;
    }
    // Assure l'imparite de la seed
    seed = (seed%2 == 0) ? seed+1 : seed;
    
    // Trouver un nombre premier avec lui
    // => On ne selectionne pas un nombre "proche" de lui => Eviter la predictibilite
    // Si c'est un consécutif de la seed, le resultat est prévisible
    uint64_t i = 1;
    while (!_are_coprime(seed+(i*offset) % seed, seed)) {
        i++;
    }

    rng->seed = seed;

    // Le nombre premier avec la seed
    rng->prime = seed+(i*offset) % seed;

    rng->value = 0;

    return rng;
}

uint64_t RNG_random_raw(RNG *rng) {
    rng->value = (rng->value + rng->prime) % rng->seed;
    return rng->value;
}

double RNG_random(RNG *rng) {
    return (double) (RNG_random_raw(rng)) / (double) (rng->seed);
}

double RNG_random_range(RNG *rng, uint64_t a, uint64_t b) {
    return RNG_random(rng) * (b-a) + a;
}

void RNG_destroy(RNG *rng) {
    free(rng);
}

// Return if a and b are prime together
bool _are_coprime(uint64_t a, uint64_t b) {
    return _gcd(a,b) == 1;
}

// Calculate the gcd
uint64_t _gcd(uint64_t a, uint64_t b) {
    uint64_t r = a % b;
    if (r == 0) {
        return b;
    }
    else {
        return (_gcd(b, r));
    }
}