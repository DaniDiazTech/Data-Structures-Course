# Stack

A stack is a linear data structure, meaning the data is stored in a contiguous space in memory.

It follows the LIFO (Last-in, First-out) principle, which means that when we insert
an element, it becomes the "top" of the stack. If we don't insert any more elements, then
the next member of the stack to take out will be this element we just inserted.

We refer to the data stored in the stack as element because we can really store anything we want inside it.

The Stack has three following methods.

- `top()`: Returns the element at the top of the stack
- `push()`: Inserts an element at the top of the stack.
- `pop()`: Takes out the element at the top of the stack and returns it.
- `size()`: Returns an integer, the number of elements the stack currently stores.
- `empty()`: You guessed it! Returns a boolean indicating if the stack is empty or not.

Because the stack is inherently dynamic, we need to use a dynamic data structure (a data structure that grows or shrinks depending on the quantity of its elements)
like a vector in c++ to implement it.

Stacks are extremely useful in programming. The most common use is the recursion stack, which we use to temporally store the calls a recursive function
(a function that calls itself repeatedly).

One example of how we use stacks, is in the DFS or depth-first-search algorithm.
