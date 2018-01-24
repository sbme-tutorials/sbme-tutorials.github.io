---
layout: page
title:  "RPC is Not Dead: Rise, Fall and the Rise of Remote Procedure Calls"
by: "Muzammil Abdul Rehman and Paul Grosu"
---

## Introduction

## Variables and Collections

### Single Variables

#### Plain Data Types (PDT) in C++

* `boolean`: holds logical value (i.e `true` or `false`), it occupies *1 byte* of memory.
* `char`: a character (e.g `'a'`,`'b'`,..) , it occupies *1 byte* of memory.
* `int`: an integer (e.g ...,-1,0,1,2,..), it occupies *4 bytes* of memory (for 64-bit machines).
* `float`: a real-number-like (e.g 0.5, 3.141, 9.81), it occupies *4 bytes* of memory.
* `double`: it is like float, but higher precision, occupies *8 bytes* of memory.
* pointers: it holds an address of a variable in memory, occupies *8 bytes* of memory (for 64-bit machines).
* references: an alias to a variable (same entity, but different name/label).

Short story: pointers and references are made to make life easier and flexible when controlling variables as we will see later in this course.

### Collections of Variables (Data Structures)

<!-- 
Show an array of floats representing an ECG signal. 
Show a linked-list of tasks.
Show a tree of life.
-->

### Construction of Variables

Assume you have variable `x = 17`.

* The variable name is `x`.
* The value is `17`.

To construct a variable you need to:

1. Declare a variable (Compiler Requirement).
    * Indicate your variable *type*.
    * Indicate your variable *name* that your are going to refer later.
2. Initialize that variable (For god's sake).
    * Give it an initial value.

First for all:

```C++
// A line begins with (//) double forward-slash is a comment line.
// Compiler Ignores comments.
// Comments are not contributing to your application logic.
// Comments are message to the readers of your code.
```

```C++
// Declare a character variable.
// Variable names are not the actual value!
char x;
```

### Construction of Collections (What?!)

This is what we are going to study through this course:

* Different data structures (i.e collections of elements).
* How to construct collections.
* How to insert elements to our collection.
* How to modify element in our collection.
* How to delete an element.
* How to traverse our collection (i.e print all its elements).
* Applying algorithms on our collection.
* Searching for an element in our collection.

## Basic Operations on Plain Data Types (PDT)

### Arithmetic Operations

### Logical Operations

## Basic Control Statements

### Conditions: if, else if, else, switch-case

### Loops: for, while

## Functions

### Declaration and Definition

## Writing your first application

### Boiler-plate codes

### Hello, world

### Task 1: Basic C++ operations

## References

{% bibliography --file data-structures --cited %}
