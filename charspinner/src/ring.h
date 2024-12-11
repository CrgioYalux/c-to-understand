#include <stdio.h>    

typedef struct Node {
    void *value;
    struct Node *left;
    struct Node *right;
} node_t;

typedef enum RingDirectionOptions {
    LEFT = 1,
    RIGHT = 2
} ring_direction_options_t;

typedef struct Ring {
    size_t length;
    struct Node *pivot;
    ring_direction_options_t direction;
    // void (*spin)(size_t times); // not really feasible
} ring_t;

void ring_spin(ring_t *ring, size_t times);
void ring_push(ring_t *ring, node_t *node);
ring_t *ring_new(ring_direction_options_t direction, node_t *pivot);
void ring_pop(ring_t *ring);
void ring_print(ring_t *ring, void (*print_cb)(void *value));
void node_print(node_t *node, ring_direction_options_t direction, size_t length, void (*print_cb)(void *value));
