#include <stdio.h>
#include <stdlib.h>
#include "ring.h"

void ring_spin(ring_t *ring, size_t times) {
    if (!ring) return;
    if (ring->length < 2) return;

    while (times) {
        if (ring->direction == LEFT) {
            // Z A [B] C D - spin times=1 LEFT
            // D Z [A] B C
            ring->pivot = ring->pivot->left;
        } else {
            // Z A [B] C D - spin times=1 RIGHT
            // A B [C] D E
            ring->pivot = ring->pivot->right;
        }
        times--;
    }
}

void ring_pop(ring_t *ring) {
    if (!ring || (ring != NULL && ring->length == 0)) return;

    ring->length = ring->length - 1;
    
    if (ring->length == 0) {
        free(ring->pivot);
        ring->pivot = NULL;
        return;
    }

    if (ring->length == 1) {
        if (ring->direction == LEFT) {
            node_t *aux = ring->pivot->left;
            ring->pivot->left = NULL;
            ring->pivot->right = NULL;
            free(aux);
        } else {
            node_t *aux = ring->pivot->right;
            ring->pivot->right = NULL;
            ring->pivot->right = NULL;
            free(aux);
        }
        return;
    }

    if (ring->direction == LEFT) {
        node_t *aux = ring->pivot->left;

        ring->pivot->left->left->right = ring->pivot;
        ring->pivot->left = ring->pivot->left->left;

        free(aux);
    } else {
        node_t *aux = ring->pivot->right;
        ring->pivot->right->right->left = ring->pivot;
        ring->pivot->right = ring->pivot->right->right;

        free(aux);
    }
}

void ring_push(ring_t *ring, node_t *node) {
    if (!ring) return;

    ring->length = ring->length + 1;

    if (ring->length == 1) {
        ring->pivot = node;
        return;
    }
    
    if (ring->length == 2) {
        ring->pivot->left = node;
        ring->pivot->right = node;

        node->right = ring->pivot;
        node->left = ring->pivot;

        return;
    }

    if (ring->direction == LEFT) {
        ring->pivot->left->right = node;
        node->left = ring->pivot->left;

        ring->pivot->left = node;
        node->right = ring->pivot;
    } else {
        ring->pivot->right->left = node;
        node->right = ring->pivot->right;

        ring->pivot->right = node;
        node->left = ring->pivot;
    }
}

ring_t *ring_new(ring_direction_options_t direction, node_t *pivot) {
    ring_t *ring = malloc(sizeof(ring_t));
    
    ring->direction = direction;
    ring->length = 0;

    if (pivot) {
        ring->pivot = pivot;
        ring->length++;
    }

    return ring;
}

void ring_print(ring_t *ring, void (*print_cb)(void *value)) {
    if (!ring) return;
    if (ring->length == 0) {
        printf("Nothing to show. Length = 0\n");
        return;
    }
    node_print(ring->pivot, ring->direction, ring->length, print_cb);
}

void node_print(node_t *node, ring_direction_options_t direction, size_t length, void (*print_cb)(void *value)) {
    if (!node || length == 0) return;

    print_cb(node->value);
    printf("items left: %ld\n\n", length);

    node_print(
        direction == LEFT ? node->left : node->right,
        direction,
        length - 1,
        print_cb
    );
}
