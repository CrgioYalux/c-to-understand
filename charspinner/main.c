#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/ring.h"
#include <getopt.h>

void print_int_ring(void *value) {
    int value_as_int = *((int*)value);
    printf("[%d] ", value_as_int);
}

void print_str_ring(void *value) {
    char *value_as_str = ((char*)value);
    printf("[%s] ", value_as_str);
}

#define how_to_use_message "Usage: %s [--spin value] [...values]\n"

int main(int argc, char **argv) {
    if (argc < 4) {
        printf(how_to_use_message, argv[0]);
        return 1;
    }

    char *argvSpinLabel = argv[1];
    int argvSpinValue = 0;

    struct option long_options[] = {
        {"spin", required_argument, 0, 's'},
        {"direction", required_argument, 0, 0},
        { 0 }
    };
    
    int opt;
    while ((opt = getopt_long(argc, argv, "vi:", long_options, NULL)) != -1) {
        switch (opt) {
            case 's':
                argvSpinValue = atoi(optarg);
                break;
            default:
                fprintf(stderr, how_to_use_message, argv[0]);

        }
    }

    size_t values_start_index = 0;
    ring_t *ring = ring_new(RING_DIRECTION_RIGHT, NULL);

    while ((values_start_index + 3) < argc) {
        node_t *node = malloc(sizeof(node_t));
        node->value = argv[(values_start_index + 3)];
        ring_push(ring, node);

        values_start_index++;
    }

    ring_print(ring, &print_str_ring);

    ring_spin(ring, argvSpinValue);
    
    ring_print(ring, &print_str_ring);

    for (size_t i = 0; i < values_start_index; i++) {
        ring_pop(ring);
    }

    free(ring);

    return 0;
}
