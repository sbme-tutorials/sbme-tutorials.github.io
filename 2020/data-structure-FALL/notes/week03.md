---
layout: page
course: "sbe201"
category: "notes"
year: "2020"
title:  "Week 3: Static Arrays and Dynamic Arrays"
by: "Asem"
---

* TOC
{:toc}

## Introduction to Arrays

The main features that characterize arrays structure:

1. Arrays are the **simplest** data structure.
2. The array elements are **placed contiguously** in memory.
3. We **refer** to arrays by the **address of the first element**.
4. Iteration over arrays are very straight forward.

Arrays can be constructed on stack (Static Arrays) and can also constructed on heap (Dynamic Arrays).

## Static Arrays

* **Static Arrays** are **fixed** in size.
* **Size** of static arrays should be **determined at compile-time** (before run-time).
* No need to delete static arrays, they are deleted automatically after going out of scope.

### Constructing Static Array

![](/gallery/dna_array.svg)

Static arrays can be constructed like so,

```c++
// Construction of array-of-integers with size 10.
int array1[10];

// Construction of array-of-characters with size 150.
char array2[150];


// Construction + Initialization of array-of-doubles with size 4
double physicalConstants[] = { 3.1415926 , 2.717 , 1.618 , 1.0 };

// Construction + Initialization of array-of-characters of size 6
char dna[] = { 'A' , 'A' , 'C' , 'T' , 'G' , 'C' };
```

### Accessing Elements of Array

To access array elements, we use the first element address as a **reference**. First element address is also known as *base pointer*. Let `double a[10]` a declaration of static array of 10 elements:

* The first element in the array is `a[0]`.
* The array base pointer is the address of first element, i.e `&a[0]`.
* The second element is `a[1]`.
* The index of array represents the offset (distance) from the first element.

#### Example: Factorials Sequence

Let `factorial` an integer array holding a lookup table for factorial numbers

--
```c++
int factorial[5];

factorial[0] = 1;
factorial[1] = 1;
factorial[2] = 2 * factorial[1];
factorial[3] = 3 * factorial[2];
factorial[4] = 4 * factorial[3];

```

#### Example: DNA Sequence

![dna](/gallery/dna-rna-double-helix-rotating-animation-13.gif)

Let `dna` a characters array holding some genetic sequence.

```c++
// Alternative way of Construction + Initialization of array-of-characters of size 6
char dna[] = { 'A' , 'A' , 'C' , 'T' , 'G' , 'C' };

std::cout << dna[0] << std::endl; // Prints: A

dna[1] = 'T'; // Modifies the second element to 'T'.

std::cout << dna[1] << std::endl; // Prints: T
```

### Iterating Over Static Array

```c++
for( int i = 0; i < 6 ; ++i )
{
    std::cout << dna[i] << ", ";
}

std::cout << std::endl;
```

#### Example: Calculating the mean (avarage) of array elements

Implement the following mean function (logic), to calculate the average of array elements.

$$ \bar{x} = \frac{1}{n}\left (\sum_{i=1}^n{x_i}\right ) = \frac{x_1+x_2+\cdots +x_n}{n} $$

```c++
double mean( double *array , int size )
{
    double sum = 0;
    for( int i = 0 ; i < size ; ++i )
    {
        sum = sum + array[ i ];
    }
    return sum / size;
}

int main()
{
    double ecg_samples[] = { 9.1 , 12.9, 12.4, 15.2, 19.0, 23.3 };
    
    // As we said, we refer to arrays by the address of first element.
    double ecg_mean = mean( &ecg_samples[0] , 6 );
    return 0;
}
```

## Dynamic Arrays

* **Dynamic Arrays** are allocated on **heap**.
* **Size** of dynamic arrays can be **determined either at compilation or at run-time (flexible)**.
* You can construct **very large** dynamic arrays on heap, unlike static arrays.
* You **need to manually delete dynamic arrays** after you no longer need them.

### Constructing Dynamic Array

```c++
// Construction of array-of-integers with arbitrary.
int size = 0;
std::cin >> size; // size determined at run-time.

// You cannot construct static arrays with an arbitrary size like in dynamic array.
int *array1 = new int[ size ];

// Construction of array-of-characters with size 150000 (around 150 Mega Bytes in memory).
char dna_chromosome11 = new char[ 150000 ];
```

### Deleting Dynamic Array: Memory Management

```c++
int *array1 = new int[ 900 ];

char *dna_chromosome11 = new char[ 150000 ];

// Do some interesting analysis on your genome.
someInterestingFunction( &dna_chromosome[0] , 150000 );

// Another operations on array1
anotherInterestingFunction( &array1[0] , 900 );

// After we no longer need array1,
delete [] array1; // Note the square brackets!
delete [] dna_chromosome;
```

## Special Case: Array of Characters (String)

In C language, strings (or array of characters) has to be null terminated (add `\0` element at the end). Many libraries that processes strings assume strings to be null terminated. We can later avoid this peculiarity by using the `std::string` object from the standard template library to save a lot of time and prevent headache. **In this semester, you are allowed to use `std::string` _after week 5_**.

### For the moment

```c++
// Alternative way of Construction + Initialization of array-of-characters of size 6
char dna[] = { 'A' , 'A' , 'C' , 'T' , 'G' , 'C' , '\0'};

std::cout << dna << std::endl; // Prints: AACTGC
```

## Basic Operations on Static and Dynamic Arrays

### Copying between arrays

Assume that you want to copy an array to another array (either static or dynamic).

```c++
#include <algorithm> // Needed for std::copy
#include <iostream> // Needed for std::cout
int main()
{
    char dna1[] = { 'A' , 'A' , 'C' , 'T' , 'G' , 'C' , '\0'};

    char dna2[ 7 ];

    std::copy( &dna1[0] , &dna1[6] , &dna2[0] );

    std::cout << dna2 << std::endl;
}
```

`std::copy`, to copy from **source** array to **target** array, it takes:

1. Address of first element of **source** array.
2. Address of last element of **source** array.
3. Address of first element of **target** array.

## Arrays ∩ `struct`

In first week, we have walked through different primitive data types (PDTs). However, we can make our own types, that consists of multiple members, using `struct` feature. *Members* in `struct` can either be primitive data types (PDT) or other `struct`s. Let's recall our example of `rectangle::area` function.

```c++
namespace rectangle
{
    double area( double w , double h )
    {
        return w * h;
    }
}
```

We could have made a *custom* type using `struct`, using the following syntax.

```c++
struct Rectangle
{
    double w;
    double h;
};
```

`Rectangle` is now a custom type, consists of two `double`s. Think of it as a package.
We can now make our `rectangle::area` function more simpler, or much readable using the following implementation.

```c++
#include <iostream>
namespace rectangle
{
    struct Rectangle
    {
        double w; // First member
        double h; // Second member
    }; // Don't forget a semicolon here!

    // Now this function is more readable. The input type explains itself.
    double area( Rectangle rectangle )
    {
        return rectangle.w * rectangle.h;
    }

    // If we have a pointer to Rectangle instead of a name for Rectangle
    // then we will access its members using the "->" arrow operator
    double area2( Rectangle *pRect )
    {
        return pRect->w * pRect->h;
    }
}

int main()
{
    rectangle::Rectangle rect{ 3 , 5 }; // declaration+initialization of Rectangle type!
    
    std::cout << rectangle::area( rect ) << std::endl;
    std::cout << rectangle::area2( &rect ) << std::endl;
    return 0;
}
```

We may also package an array (either static or dynamic) with its size, using `struct`

```c++
#include <iostream>

struct IntegerArray
{
    int *base;
    int size;
};


int sumArray1( int *base , int size )
{
    int sum = 0;
    for( int i = 0 ; i < size ; ++i )
    {
        sum += base[i];
    }
    return sum;
}

int sumArray2( IntegerArray array )
{
    int sum = 0;
    for( int i = 0; i < array.size ; ++i )
    {
        sum += array.base[ i ];
    }
    return sum;
}

int main()
{
    int *buffer = new int[10];
    IntegerArray array{ &buffer[0] , 10 }; // Initializes base and size members.
    
    std::cout << sumArray1( &buffer[0] , 10 ) << std::endl;
    
    std::cout << sumArray2( array ) << std::endl;
    
    // We still need to delete the array on the heap
    delete [] array.base;

    return 0;
}
```

We can also use `struct` to **return multiple values**, which is more safe and clean than using multiple references as input and modifying our interesting results into these input references.

```c++

struct ECGArray // We could name it also DoubleArray
{
    double *samples;
    int size;
}

struct Statistics
{
    // Members can have default values after declaration of Statistic type variable.
    // So you don't need to explicitly to initialize them from outside.
    double mean = 0 ;
    double variance = 0 ;
    double min = 0;
    double max = 0;
}

// Very self-explaining function header!
Statistics analyzeECG( ECGArray ecg )
{
    Statistics analysis; // Declaration, and no need for explicit initialization now

    analysis.mean = // Some logic here
    analysis.variance = // Some logic there
    // And so on.

    return analysis;
}
```
