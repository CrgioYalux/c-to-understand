### Use

- Spinning from left to right

```bash
$ charspinner --spin 1 a e g h j 3 2 5 
$ 5 a e g h j 3 2
```

- Spinning from right to left

```bash
$ charspinner --spin -3 a e g h j 3 2 5 
$ h j 3 2 5 a e g
```

### Specifics about the implementation
- I plan to use **something like a** Ring data structure (aka [circular buffer](https://en.wikipedia.org/wiki/Circular_buffer)). Basically, a node-based data structure that links nodes from both the left and right sides. When the ring contains more than one node, then no node can be unlinked on any of its sides.
(C) <-> A <-> B <-> C <-> (A)

### TODO 
- [ ] Create a ring with the values passed in the arguments
- [ ] Allow the `spin` function to determine the spin direction with the sign of the value passed

### Future
- ~Make the `spin` function, which I will, for starters, define as a separate function, a part of the whole Ring object. Make it work like a *method* in OOP.~ 
Not really a thing in C for what I've read, can't really escape passing the 

```c
#include <stdio.h>

typedef struct Node {
    void *value;
    void (*print)(struct Node *node, const char *some_text);
} node_t;

void print(node_t *node, const char *some_text) { // hopefully this ends with \0
    printf("passed text says '%s'\nwhile node value is %d\n", some_text, *(int*)node->value);
}

int main() {
    node_t node = { 0 };

    int x = 10;
    node.value = &x;
    node.print = &print;

    node.print(&node, "some text"); // you still need to pass the caller node
                                    // to the method being called
    /*
    $ ./main
    passed text says 'some text'
    while node value is 10
    */

    // node.print("some text"); // you can't do this

    return 0;
}
```

