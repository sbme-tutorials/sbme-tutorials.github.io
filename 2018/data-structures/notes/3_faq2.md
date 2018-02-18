---
layout: page
course: "sbe201"
category: "faq"
year: "2018"
title:  "FAQ #2: Why `int *p = &x` != `*p = &x`"
by: "Asem"
---

## FAQ #2. Why `int *p = &x` != `*p = &x`

### A Declaration+Initialization vs. Dereferencing

```c++
int x = 1;
// Declaring a pointer-to-integer and initializing it to address of x.
int *px = &x; // Compiles (Type Match)!

// Dereferencing px and assignment by address of integer
*px = &x; // Compiler Error (Type Mismatch)!
```

In other words,

```c++
int x = 1;
int *px = &x;
```

is equivalent to

```c++
int x = 1;
int *px;
px = &x;
```

Which is **not** equivalent to

```c++
int x = 1;
int *px;
*px = &x; // Compiler Error (Type Mismatch)!
```

### Short Story

* Asterisk `*` in declarations expressions (`int *p;`) means you are declaring a pointer `p`.
* Asterisk `*` in non-declaration expressions (`*p;`)  means you are dereferencing a pointer (get the variable pointed by the address in `p`).

You can also make it simpler for your self if you wish.

```c++
int x = 1;

// To declare and initialize pointers to zero address,
// you can use either nullptr or 0.
int *px = nullptr;

px = &x;
```
