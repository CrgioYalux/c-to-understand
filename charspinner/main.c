#include <stdio.h>
#include <stdlib.h>
#include "src/ring.h"

void print_int_ring(void *value) {
    int value_as_int = *((int*)value);
    printf("[at %p] value: %d\n", value, value_as_int);
}

int main(int argc, char **argv) {
    /*if (argc < 4) {*/
    /*    printf("Usage: charspinner --spin/-s <int> [...CHARS]\n");*/
    /*    return 1;*/
    /*}*/
    /**/
    /*size_t argacc = 1; // escape program name*/
    /**/
    /*while (argv[argacc] != NULL) {*/
    /*    printf("Passed: %s\n", argv[argacc]);*/
    /*    argacc++;*/
    /*}*/

    node_t *a = malloc(sizeof(node_t));
    node_t *b = malloc(sizeof(node_t));
    node_t *c = malloc(sizeof(node_t));

    int va = 100, vb = 200, vc = 300;

    a->value = &va;
    b->value = &vb;
    c->value = &vc;

    ring_t *ring = ring_new(LEFT, NULL);
    ring_push(ring, a);
    ring_push(ring, b);
    ring_push(ring, c);

    ring_print(ring, &print_int_ring);

    ring_pop(ring);
    ring_pop(ring);
    ring_pop(ring);
    
    ring_print(ring, &print_int_ring);

    free(ring);

    return 0;
}
