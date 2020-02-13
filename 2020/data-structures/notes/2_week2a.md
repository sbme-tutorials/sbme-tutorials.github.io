---
layout: page
course: "sbe201"
category: "notes"
year: "2019"
title:  "Week 2 - Part1: Memory, pointers, and references"
by: "Asem"
---

* TOC
{:toc}

## Introduction

## Memory Layout

![stack](/gallery/stackheap.png)

What makes C and C++ very powerful is their flexibility in memory management. However, flexibility has a price. In contrast, some programming languages hide the memory details from the developer.

Basically, the memory space is divided into Stack memory and Heap memory as shown in the figure. Stack memory are limited in capacity compared to heap memory. In previous week, all examples and tasks, you allocated variables on the stack memory, and it was very simple.

### Flexible vs Opinionated Memory Management in Programming Languages

Languages like C and C++ we consider them offering flexible memory management. Other languages, like Java, C#, Python, have an automatic (opinionated) memory management. Each category has its advantages and disadvantages.

| Flexible languages | Opinionated languages |
|----------|-------------|
| More powerfull and efficient programs | Usually inefficient in comparison |
| Overhead to learn | Easier to learn |
| More complexity | Simplicity (no need to worry about memory management) |
| Memory leakage if abused | No memory leakage |

This image may convey the comparison between flexible languages and opinionated languages.

![](/gallery/cpp-swissknife.jpg)

## Variables on Stack Memory

Last week, all our variables were allocated on stack

```c++
char x = 's';

float pi = 3.1415;

int k = 0;

int j = k;

double e {2.71828};
```

- Variables created in stack memory are automatically deleted after going out of their scope.
- Allocating variables on stack is very straight forward, and we do not worry about deleting them after going out of scope.

## Address of a Variable in the Memory

To better understand and control the memory, you need to know what is the variable address.
Consider x, y, and z are three integers that created (created = allocated = declared) on stack.

```c++

// Declare integer x and initialize with 13.
int x = 13;

// Declare integer y and initialize with 1.
int y = 1;

// Declare integer z and initialize with 5.
int z = 5;
```

Their physical presence in memory looks like this:

![](/gallery/stackaddress.png)

## Address of a variable in C++

But how to get the address of a variable?

- By using `&` (ambersand operator).

We store the address of a variable in a special type called **pointer**.

- **Pointer** is a primitive data type.
- **Pointer** type occupies **8 bytes** (64-bit machines).
- **Pointer** is declared using the syntax `target_type *`.

```c++
int x = 13;
int y = 1;
int z = 5;

// Declare `pointer to integer` px and initialize with address of x.
int *px = &x; 

// Declare `pointer to integer` py and initialize with address of y.
int *py = &y; 

// Declare `pointer to integer` pz and initialize with address of z.
int *pz = &z;
```

## Why using Address

### Flexibility

Adresses gives a lot of flexibility to control variables. For example, you can modify a variable value if you have its address.

```c++
int x = 9;

std::cout << x << std::endl; // prints: 9

int *px = &x;

// Derefrencing px to access x.
*px = 13;

std::cout << x << std::endl; // prints 13
```

### Passing arguments by pointer

You can pass a **pointer to variable** as argument to a function.

```c++
void sum( double a , double b , double *presults )
{
    // Dereference the presults to access the underlying variable.
    *presults = a + b;
}

int main()
{
    double results = 0;

    sum( 13 , 5 , &results ); // Now results has new value.

    std::cout << results << std::endl; // Prints: 18
}
```

By the way, this is acceptable in C language. But in C++, we avoid this style of modifying variables, and always prefer to return the results.

This is better and simpler.

```c++
double sum( double a , double b )
{
    return a + b;
}

int main()
{
    double results = sum( 13 , 5 );
}

```

## Stack Memory vs. Heap Memory

| Stack Memory | Heap Memory |
|--------------|-------------|
| Limited capacity | Large capacity for scalable structures |
| Automatic memory management | Manual memory management |

## Variables on Heap Memory

Variables can also be created on heap.

```c++

// Allocate integer with initializing to zero on heap memory, and save the address in px.
int *px = new int{0};

// Another syntax to initialize heap memory variables.
// Allocate integer with initializing to 4 on heap memory, and save the address in py.
int *py = new int(4);

int *pz = new int(8);
```

Physically, they would look like this: 

![](/gallery/heapaddress.png)

## Memory Management

Variables created on heap using `new` operator, should be deleted manually after you no longer need that variable. Otherwise, if you didn't manually delete variables on heap, you will allocate a lot of space that will become unusable.

```c++
int *px = new int{0};

int *py = new int(4);

int *pz = new int(8);

delete px;
delete py;
delete pz;
```

### Important Rule for memory management

* When you finish coding, make sure to balance heap allocations & deallocations.
* #`new` = #`delete`.

## Reference types

References are very important type in C++, and using it in the right way makes your program very efficient. References are made to be alternative for pointers to enhance the readability of your code.

When you make a reference to a variable, you actually making an alias to that variable. In other words, you are making another name for the same variable.

```c++

// Declaration of integer x and initializing with zero.
int x = 0;

// Declaration of reference y and to be reference for x.
int &y = x;

// Now x and y, are the same variable, but with different name.

// Chaning y value, will also affect x, and vice versa.
y = 10;

std::cout << x << std::endl; // prints: 10
```

Recall the example of passing pointer as argument:

```c++
void sum( double a , double b , double *presults )
{
    // Dereference the presults to access the variable results.
    *presults = a + b;
}

int main()
{
    double results = 0;

    sum( 13 , 5 , &results );

    std::cout << results << std::endl;
}
```

This can be written in more elegant way using references:

```c++
void sum( double a , double b , double &results )
{
    // No need for dereference as we did in pointers, like it is a real variable!
    results = a + b;
}

int main()
{
    double results = 0;

    // No need to pass the address explicitly.
    sum( 13 , 5 , results );

    std::cout << results << std::endl;
}
```

**But again, it is very preferred to use the simplest form as possible**!

```c++
double sum( double a , double b )
{
    return a + b;
}

int main()
{
    double results = sum( 13 , 5 );
}
```