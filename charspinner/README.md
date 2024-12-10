### Use

- Spinning from left to right

```bash
$ charspinner --spin=1 a e g h j 3 2 5 
$ 5 a e g h j 3 2
```

- Spinning from right to left

```bash
$ charspinner --spin=-3 a e g h j 3 2 5 
$ h j 3 2 5 a e g
```

### Specifics about the implementation
- I plan to use a Ring data structure. Basically, a node-based data structure that links nodes from both the left and right sides. When the ring contains more than one node, then no node can be unlinked on any of its sides.
(C) <-> A <-> B <-> C <-> (A)

### Future
- Make the `spin` function, which I will, for starters, define as a separate function, a part of the whole Ring object. Make it work like a *method* in OOP.
