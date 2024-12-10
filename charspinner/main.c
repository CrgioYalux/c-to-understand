#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: charspinner --spin=<int> [...CHARS]");
        return 1;
    }

    size_t argacc = 1; // escape program name
    
    while (argv[argacc] != NULL) {
        printf("Passed: %s\n", argv[argacc]);
        argacc++;
    }

    return 0;
}
