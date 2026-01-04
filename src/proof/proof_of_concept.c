#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

// Le type definit servant a stocker la graine, le nombre premier et la valeur courante generee
typedef struct x Generator;

struct x {
    uint64_t seed, p, x;
};

bool arePrimeTogether(uint64_t a, uint64_t b);
uint64_t gcd(uint64_t a, uint64_t b);
uint64_t Generator_next(Generator *p_gen);

int main() {

    // 2 grands nombres premiers
    uint64_t p1 = 9007199254740881;
    uint64_t p2 = 922337203685477647;

    // Calcule la graine
    uint64_t seed = time(NULL) * __UINT64_MAX__;
    uint64_t offset = time(NULL) * __UINT32_MAX__;

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
    while (!arePrimeTogether(seed+(i*offset) % seed, seed)) {
        i++;
    }

    printf("Seed              : %lu\n", seed);
    printf("Prime (with seed) : %lu\n", (seed+(i*offset)) % seed);

    
    // Le nombre premier avec la seed
    uint64_t p = seed+(i*offset) % seed;
    uint64_t MAX = 100;

    printf("Enter to show the %lu first genereated numbers", MAX);
    getchar();

    // Instance du generateur
    Generator gen = {
        .seed = seed,
        .p = p,
        .x = 0,
    };

    // Calcule MAX valeurs et stocke le min et le max
    uint64_t max = gen.x;
    uint64_t min = seed;
    for (uint64_t i =0; i<MAX; i++) {
        Generator_next(&gen);
        printf("%lu : %lu\n", i+1, gen.x);
        if (max < gen.x) {
            max = gen.x;
        }
        else if (min > gen.x) {
            min = gen.x;
        }
    }

    printf("Max : %lu\n", max);
    printf("Min : %lu\n", min);
}

// Genere le prochain terme 
uint64_t Generator_next(Generator *p_gen) {
    p_gen->x = (p_gen->x+p_gen->p)%p_gen->seed;
    return p_gen->x;
}

// Retourne vrai si les 2 nombres sont premiers entre eux
bool arePrimeTogether(uint64_t a, uint64_t b) {
    return gcd(a,b) == 1;
}

// Calcule le pgcd via une fonction recursive
uint64_t gcd(uint64_t a, uint64_t b) {
    uint64_t r = a % b;
    if (r == 0) {
        return b;
    }
    else {
        return (gcd(b, r));
    }
}