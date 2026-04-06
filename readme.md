Welcome!

# C basic datatype library
This repository contains a bunch of libraries of datatypes I usually make use of when working with stuffs.
The motivation came from me having to rewrite the exact same code all the time, so I thought I might as well just keep it as a library.

# Future plans
- [ ] Work on Fibonacci heap
- [ ] Use some advanced pointer stuffs to allow this to work for any datatype
- [ ] Use template for inheritance between `bst`, `avl`, `wbt` all that
- [ ] add unit testing through boost library
- [ ] use Github Actions + Docker to verify unit tests.
- [x] use documentation through DOxygen
- [ ] use errno somewhere...?

## questions
### for marcelo
- how do I handle the print for `void *` type?
- can I assume all `void *` pointers are pointing on something on the stack?
- Since I'm using a key + value pair for bst, should I do the same for linkedlist?
- My current structure follows: Ever struct has a function pointer for the `print_fn` (and the others), should I instead make it so that every struct points to a struct that works as a "base", which contains pointers pointing to `print_fn`, `cmp_fn`...
- Should I use errno for functions like `linked_list_delete_count` for when `count` is too large? Or exit? What's the good thing to do as a library?
- should it be `typedef void(print_fn)(void *);` or `typedef void(*print_fn)(void *);`

### for purva
- For Fibonacci heap, should I "randomly" insert new nodes in root list (eg. random position).
