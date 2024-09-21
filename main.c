#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 1024

typedef enum Side {Heads, Tails} Side;

int generate_random_num(int lower_bound, int upper_bound) {
    return (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
}

Side flip_coin(void) {
    return generate_random_num(0, 1) == 0 ? Heads : Tails;
}

double calculate_probability(int num_occurrence, int num_flips) {
    return ((double)num_occurrence / num_flips) * 100;
}

void print_results(int num_heads, int num_tails, unsigned long int num_flips) {
    printf("Heads: %d\n", num_heads);
    printf("Tails: %d\n", num_tails);
    printf("Flips: %lu\n", num_flips);
    printf("Probability of heads: %.2f%%\n", calculate_probability(num_heads, num_flips));
    printf("Probability of tails: %.2f%%\n", calculate_probability(num_tails, num_flips));
}

unsigned long int get_flips() {
    char buf[MAX];
    char *endptr;
    unsigned long int flips = 0;

    do {
        printf("Please enter a number of flips to perform: ");

        if (!fgets(buf, MAX, stdin)) {
            fprintf(stderr, "ERROR: Could not read input\n");
            return -1;
        }

        if (buf[0] == '-') {
            fprintf(stderr, "ERROR: Flips cannot be a negative value\n");
            continue;
        }

        flips = strtoul(buf, &endptr, 10);
        
        if (endptr == buf || *endptr != '\n') {
            fprintf(stderr, "ERROR: Invalid input\n");
            continue;
        }

        if (flips == 0) {
            fprintf(stderr, "ERROR: Flips must be greater than 0\n");
            continue;
        }

        break;
    } while (true);
    
    return flips;
}

int main(void) {
    int heads = 0;
    int tails = 0;
    unsigned long int flips = 0;

    srand(time(NULL));

    flips = get_flips();

    for (unsigned long int i = 0; i < flips; i++) {
        if (flip_coin() == Heads) {
            heads++;
        } else {
            tails++;
        }
    }

    print_results(heads, tails, flips);
}