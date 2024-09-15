#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void print_results(int num_heads, int num_tails, int num_flips) {
    printf("Heads: %d\n", num_heads);
    printf("Tails: %d\n", num_tails);
    printf("Flips: %d\n", num_flips);
    printf("Probability of heads: %.2f%%\n", calculate_probability(num_heads, num_flips));
    printf("Probability of tails: %.2f%%\n", calculate_probability(num_tails, num_flips));
}

int main(void) {
    int heads = 0;
    int tails = 0;
    long int flips = 0;
    char buf[MAX];
    char *endptr;

    srand(time(NULL));

    printf("Please enter a number of flips to perform: ");
    fgets(buf, MAX, stdin);
    flips = strtol(buf, &endptr, 10);

    for (int i = 0; i < flips; i++) {
        if (flip_coin() == Heads) {
            heads++;
        } else {
            tails++;
        }
    }

    print_results(heads, tails, flips);
}