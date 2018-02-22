---
layout: page
course: "sbe201"
category: "assignment"
year: "2018"
title:  "Assignment 3 - Part 1: Arrays"
by: "Asem"
pdf: true
---

## Prerequisites

## Objectives

* Revisiting namespaces, references, and pointers.
* Work with multiple files.
* Work with multiple applications.
* Realize the dependencies between files.
* Implement basic array operations: 
  
  * print (traverse)
  * mean
  * standard deviation
  * max
  * min
  * counter

* Work with biological data in array structures.

  * Analyze DNA
  * Return the complementary sequence of DNA
  * Count a specific base pair in DNA
  * Analyze ECG: mean, standard deviation, max, and min.

* Compilation of multiple files.


## Assignment: Part 1

### Overview

You will learn how to work with multiple files. We will write our interesting functions in header files, and then use these functions in our interesting applications.

#### The header files (library)

We will work and implement our logic inside these files:

* `mathematics.hpp` to contain some **mathematical** functions like `calculation`.
* `arrays.hpp` to contain our **array** functions.
* `ecg.hpp` to contain analysis functions on **ECG**.
* `dna.hpp` to contain analysis functions on **DNA**.

Our source files of our applications that we are going to compile into useful and **very important applications**:

* `calculator.cpp` to implement the *Calculator* application, and depends on `mathematics.hpp`.
* `heron.cpp` to implement a simple application that implements *Heron Formula*, and also depends on `mathematics.hpp`.
* `analyzeECG.cpp` to implement **very useful** application for *ECG Analysis*, depends on `ecg.hpp`.
* `analyzeDNA.cpp` to implement **very useful** application for *DNA Analysis*, depends on `dna.hpp`.

You will find a useful header file `helpers.hpp`, **I don't recommend you to try understanding it before week 6**. We will just use two functions from `helpers.hpp` to load our **DNA** and **ECG** files from hard disk.

#### Dependency Graph

![dependencies](task3.svg)

By the way, keep in mind, that **application source files** that are compiled into **executable files**, has to be:

* including a `main` function. Each `main` function is a simply program entry point.
* and `main` function should be existing in a `.cpp` file.

You will also realize our header files begin and ends with

```c++
#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP

// includes of external headers here

// Your functions here

#endif // MATHEMATICS_HPP
```

No worries, they are called [header guards](https://en.wikipedia.org/wiki/Include_guard). Will be explained on next tutorial on **Sunday**. But just consider them as a skeleton (boilerplate) code.

### Requirement 1: **mathematics.hpp** file

* **R1.1** Make a `namespace mathematics` that will contain our functions.
* **R1.2** Implement our `calculation` function using either **if, else if, else** or **switch-case**.
* **R1.3** Implement [Heron Formula](https://en.wikipedia.org/wiki/Heron%27s_formula), that is used to compute the **triangle area** given its three sides, hmmmm very interesting. 

![tri](triangle.png)

$$A = \sqrt{s(s-a)(s-b)(s-c)},$$

where *s* is the *semiperimeter* of the triangle; that is,

$$ s=\frac{a+b+c}{2}. $$

Use this function declaration:

```c++
double heron( double a , double b , double c )
{
    // Logic here
}
```

You also need to `#include <cmath>` an an external header, to use `std::sqrt` function that computes the square root.

* **R1.4** It is your job now to implement the `main` function in `heron.cpp` file. It is required to make the *Heron Formula* application to receive the three dimensions of the triangle through terminal. So you will retrieve the three parameters through the `argv`. Remember that you will need to use `std::atof` function and `#include <string>`. To use `mathematics::heron`, add `#include "mathematics.hpp"`.

### Requirement 2: **arrays.hpp** file

* **R2.1** Make a `namespace arrays` that will contain our functions.
* **R2.2** Implement a function that prints all array elements on terminal, using the following declaration:

```c++
void printAll( double *base , int arraySize )
{
    // Logic here
}
```

* **R2.3**+**R2.4** Implement a function that returns the **maximum** element and another one for **minimum** element, using the following declarations:

```c++
double maxArray( double *base, int arraySize )
{
    // Logic here
}

double minArray( double *base, int arraySize )
{
    // Logic here
}
```
* **R2.5**+**R2.6** Implement a function that returns the **mean (average)** of array elements and another one that returns the **standard deviation**, using the following declaration:

```c++
double meanArray( double *base , int arraySize )
{
    // Logic here
}


double stdArray( double *base, int arraySize )
{
    // Logic here
}
```

### Requirement 3: **ecg.hpp** file


* **R3.1** Make a `namespace ecg` that will contain our function.
* **R3.2** Make a function that computes the **average**, **standard deviation**, **max**, and **min** of **ECG** signal. But these are not single variables so we can return. Alternatively, we will use **4 reference** variable in function declaration.

```c++
void analyzeECG( double *base , int arraySize , double &average, double &standardDev, double &max, double &min )
{
    // Logic here
}
```

Use the four functions we already implemented in `arrays.hpp`. Accordingly, **four lines** are sufficient to do this job. And yes, don't forget to `#include "arrays.hpp"` in the current header file.

### Requirement 4 (Bonus): **dna.hpp** file and revisiting **arrays.hpp** file

#### Revisit **arrays.hpp** file

* **R4.1** Make a function that counts a given character in array of characters, using the following declaration:

```c++
int countCharacter( char *basePointer , int size , char query )
{
    // Logic here
} 
```

#### Now **dna.hpp** file

* **R4.1** Make a `namespace dna` that will contain our functions.
* **R4.2** Implement `complementaryBase` function using either **if, else if, else** or **switch-case**, using the following declaration:

```c++
char complementaryBase( char base )
{
    // Logic here
}
```

* **R4.3** Implement `complementarySequence` function that returns the complementary **DNA** sequence.

Please beware that the double strands of our **DNA** are directional, and they have opposite directions.

For example, the sequence *ACG* has a complementary sequence *CGT*, **not** *TGC*.

So in your for loop, you may read the *original* sequence from begining, and write the complementary sequence starting from the *end* of the complementary sequence array.

By the way, you have to allocate the complementary sequence on the heap (dynamic array).

Use the following declaration:

```c++
char * complementarySequence( char *base, int size )
{
    // Your logic here
}
```

* **R4.4** Implement `analyzeDNA` function that counts the 4 bases in a sequence, and returns the complementary sequence. Again, you have four counters and a complementary sequence. So you only return the complementary sequence, and the counters will saved back to reference integers. Use the following declaration:

```c++
char *analyzeDNA( char *base, int size, int &countA, int &countC, int &countG, int &countT )
{
    // Your logic here.

    // It is safer to re-initialize thr four counters to zeros. Don't trust the caller function ;)
}
```