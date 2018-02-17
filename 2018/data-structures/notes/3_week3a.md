---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 3 - Part1: Static Arrays, Dynamic Arrays, and Command Line Arguments"
by: "Asem"
---

* TOC
{:toc}

## Faq

### 1. Why `using namespace [name];` is a bad practice

### 2. Why `int *p = &x` != `*p = &x`

#### A Declaration+Initialization vs. Dereferencing

```c++
int x = 1;
// Declaring a pointer-to-integer and initializing it to address of x.
int *px = &x; // Compiles!

// Dereferencing px and assignment by address of integer
*px = &x; // Compiler Error!
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
*px = &x; // Compiler Error!
```

## Introduction to Arrays

The main features that characterize arrays structure:

* Arrays are the simplest data structure.
* The array elements are placed contiguously in memory.
* We refer to arrays by the address of the first element.
* Iteration over arrays are very straight forward.

Arrays can be constructed on stack (Static Arrays) and can also constructed on heap (Dynamic Arrays).

## Static Arrays

* Static Arrays are fixed in size.
* Size of static arrays should be determined at compilation (before run-time).
* No need to delete static arrays, they are deleted automatically after going out of scope.

### Constructing Static Array

![](/gallery/dna_array.svg)

### Constructing Static `char` Array (String)

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

```c++
// Construction + Initialization of array-of-characters of size 6
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

```c++
double mean( double *array , int size )
{
    int sum = 0;
    for( int i = 0 ; i < size ; ++i )
    {
        sum = sum + i;
    }
    return sum / size;
}

int main()
{
    double ecg_samples[] = { 9.1 , 12.9, 12.4, 15.2, 19.0, 23.3 };
    double ecg_mean = mean( ecg_samples , 6 );
    return 0;
}
```

## Dynamic Arrays

* Dynamic Arrays are allocated on heap.
* Size of dynamic arrays can be determined either at compilation or at run-time.
* You can construct very large dynamic arrays on heap, unlike static arrays.
* You need to manually delete dynamic arrays after you no longer need them.

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

char dna_chromosome11 = new char[ 150000 ];

// Some logic .....
// Some logic .....


// After we no longer need array1,
delete [] array1; // Note the square brackets!
delete [] dna_chromosome;
```

## Command Line Arguments

### Examples: Why Command Line Arguments

* `apt-get install vlc`
* `git commit -a -m "kill me please!"`
* `cp [file] [target path]`

| Application | Argument 1 | Argument 2 | Argument 3 | Argument 4 |
|-------------|------------|------------|------------|------------|
| `apt-get` | `install` | `vlc` | `null` | `null` |
| `git`  | `commit` | `-a` | `-m` | `"kill me please!"` |
| `cp` | `[file]` | `[target path]` | `null` | `null` |

### Command Line Arguments in C and C++

```c++
int main( int argc, char **argv )
{
    std::cout << "Arguments count:" << argc << std::endl;

    for( int i = 0 ; i < argc ; ++i )
    {
        std::cout << "Argument:" << argv[ i ] << std::endl;
    }
}
```

## Coding in Multiple Files

## Compilation of Multiple Files of Multiple Applications

## Compilation of 100 Files