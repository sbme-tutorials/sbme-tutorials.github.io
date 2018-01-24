---
layout: page
title:  "Basics of C++ and Git"
by: "Asem"
---

## Introduction

## Variables and Collections

### Single Variables

#### Plain Data Types (PDT) in C++

* `bool`: boolean variable holds logical value (i.e `true` or `false`), it occupies **1 byte** of memory.
* `char`: a character (e.g `'a'`,`'b'`,..) , it occupies **1 byte** of memory.
* `int`: an integer (e.g ...,-1,0,1,2,..), it occupies **4 bytes** of memory (for 64-bit machines).
* `float`: a real-number-like (e.g 0.5, 3.141, 9.81), it occupies **4 bytes** of memory.
* `double`: it is like float, but higher precision, occupies **8 bytes** of memory.
* pointers: it holds an address of a variable in memory, occupies **8 bytes** of memory (for 64-bit machines).
* references: an alias to a variable (same entity, but different name/label).

Short story: pointers and references are made to make life easier and flexible when controlling variables as we will see later in this course.

### Collections of Variables (Data Structures)

<!-- 
Show an array of floats representing an ECG signal. 
Show a linked-list of tasks.
Show a tree of life.
-->

### Construction of Variables

A variable has: 

1. **Data Type**: `int`, `char`, `bool`, ..., etc.
2. **Name**: name of the variable to be used throughout your code.
3. **Value**: the content of the variable.

Don't mix between them!

To construct a variable you need to:

1. Declare a variable (Compiler Requirement).
    * Indicate your variable **type**.
    * Indicate your variable **name** that your are going to refer later.
2. Initialize that variable (For god's sake).
    * Give it an initial value.

#### Example

First for all:

```C++
// What comes after double forward-slash (//) in a line is a comment.
// Compiler Ignores comments.
// Comments are not contributing to your application logic.
// Comments are message to the readers of your code.
```

```C++
// Declare a character variable.
// Variable names are not the actual value!
char x;
// What is the value of x?!
// When not initialized, x will hold a value from garbage.

// Please, always initialize your variables.

// Declaration of character with initializng to 's'.
char x = 's';

// Declaration of float whith initializing to 3.1415.
float pi = 3.1415;


// If no interesting value to initialize your variable with, initialize with 0.
int k = 0;

// You can initialize a variable with the value of another variable.
int j = k;

// Another way to initialize a variable is using braces, it is up to you.
double e {2.71828};
```

One way to avoid bugs (undefined behaviour) is initializing your variables.

### Construction of Collections (What?!)

This is what we are going to study through this course:

* Different data structures (i.e collections of elements): Array, Linked List, Stack, Queue, Tree.
* How to **construct** collections.
* How to **insert** elements to our collection.
* How to **modify** element in our collection.
* How to **delete** an element.
* How to **traverse** our collection (i.e print all its elements).
* Applying **algorithms** on our collection.
* **Searching** for an element in our collection.

## Basic Operations on Plain Data Types (PDT)

### Arithmetic Operations

```C++
int x = 12;
int y = 5;

x + y; // 17
x - y; // 7
x * y; // 60
x / y; // 2
x % y; // 2


// x = x+y
x += y; // x is now 17.

// increment: x = x+1
++x; // x is now 18.

// x = x-y
x -= y; // x is now 13.

// decrement: x = x-1
--x; // x is now 12.

double u = 12.5;
double v { 3 };

u / v;  // 4.166667
```

### Logical Operations

```C++
int x = 3;
int y = 4;

// equal
x==y; // False

// not equal
x!=y; // True

// less than
x<y; // True

// greater than
x>y; // False

// less than or equal
x<=y; // True

// greater than or equal
x>=y; // False

// logical and
x == 3 && y > x; // True
x != 3 && y > x; // False
true && true; // True
5 < 10 && 13 >= 11; // True
5 % 2 == 1 || 3 / 2 > 1; // False
5 % 2 == 1 || 3 / 2.0 > 1; // True


// logical or
true || true; // True
true || false; // True
false || true; // True
false || false; // False
5 % 2 == 1 || 3 / 2 > 1; // True
```

## Basic Control Statements

### Conditions: if, else if, else, switch-case

```C++

bool myCondition = 5 % 2 == 1 || 3 / 2 > 1;

if( myCondition )
{
  // Some operations here.
}
else
{
  // Other operations here.
}

char mark = 73;
char grade = 'D';

if( mark > 85 )
{
  grade = 'A';
}
else if( mark > 75 )
{
  grade = 'B';
}
else if( mark > 65 )
{
  grade = 'C';
}
else
{
  grade = 'D';
}

int minimumGrade = 0;

switch (grade)
{
  case 'A':
  {
    minimumGrade = 85;
  } break;
  
  case 'B':
  {
    minimumGrade = 75;
  } break;
  
  case 'C':
  {
    minimumGrade = 65;
  } break;
  
  default:
  {
    minimumGrade = 85;
  } break;
}

```

### Loops: for, while

{% katex %}
c = \pm\sqrt{a^2 + b^2}
{% endkatex %}

{% katex display %}
c = \pm\sqrt{a^2 + b^2}
{% endkatex %}

## Functions

### Declaration and Definition

## Writing your first application

### Boiler-plate codes

### Hello, world

### Task 1: Basic C++ operations

## Scope and Lifetime

## References

{% bibliography --file data-structures --cited %}
