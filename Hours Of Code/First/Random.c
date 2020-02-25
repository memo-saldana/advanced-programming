//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 25/02/2020
//
// Generate a random number withour rand()
#include <stdio.h>
#include <time.h>
#include <stdint.h>

struct xorshift64_state {
  uint64_t a;
};

uint64_t randomNumber(struct xorshift64_state *state, int range) {
    // xorshift64
    uint64_t x = state->a;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return state->a = x%range;

}

int main() {
    struct xorshift64_state *state;
    long int range;
    for (int i = 0; i < 10; i++) {
        printf("Input the wanted range for the number (0 to): ");
        scanf("%ld", &range);
        time_t now = time(0);
        state->a = now;
        printf("Random number: %lu\n", randomNumber(state, range));
    }

    return 0;
}