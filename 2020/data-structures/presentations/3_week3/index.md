---
layout: presentation
style: laminal
highlighter: monokai
course: "sbe201"
category: "presentation"
year: "2019"
title: "Week 3: Arrays, Command Line Arguments, and Libraries"
by: "Asem"
author: "Asem Alaa"
---

<textarea id="source">

---
class: left, top
## Introduction to Arrays

--
#### Arrays structures, are:

--
* The .green[**simplest**] data structure.
--
* Placed .blue[**contiguously**] in memory.
--
* Referred by the .blue[**address of the first element**].
--
* .green[**Simple**] iterations using for-loops.



--
#### Arrays can be constructed on:

--
* Stack Memory => **Static Arrays**
--
* Heap Memory => **Dynamic Arrays**

---
class: left, top
## Static Arrays

--
* .red[**Limited** in size].
--
* .red[**Size** determined at **compile-time**].
--
* .green[Automatic memory management.]

---
class: left, top
### Constructing Static Array

--
![](/gallery/dna_array.svg)


--
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
---
class: left, top
### Accessing Elements of Array

--
`double a[10]; // Declaration`



--
To access array elements,

--
* First element => `a[0]`.
--
* Base pointer => the address of first element => `&a[0]`.
--
* Second element => `a[1]`.
--
* index = offset = distance from `a[0]`.


---
class: left, top
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


---
class: left, top
#### Example: DNA Sequence

![dna](/gallery/dna-rna-double-helix-rotating-animation-13.gif)

---
class: left, top
Let `dna` a sequence of some genetic region.

--
```c++
// Alternative way of Construction + Initialization of array-of-characters of size 6
char dna[] = { 'A' , 'A' , 'C' , 'T' , 'G' , 'C' };

std::cout << dna[0] << std::endl; // Prints: A

dna[1] = 'T'; // Modifies the second element to 'T'.

std::cout << dna[1] << std::endl; // Prints: T
```

---
class: left, top
### Iterating Over Static Array

--
```c++
for( int i = 0; i < 6 ; ++i )
{
    std::cout << dna[i] << ", ";
}

std::cout << "\n";
```

---
class: left, top
#### Application: Calculating the mean (average) of array elements

--
Implement the following mean function (logic), to calculate the average of array elements.

--
$$ \bar{x} = \frac{1}{n}\left (\sum_{i=1}^n{x_i}\right ) = \frac{x_1+x_2+\cdots +x_n}{n} $$


--
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
---
class: left, top
## Dynamic Arrays

--
* Lives on .blue[**Heap Memory**].
--
* .green[**Flexibility**]: **Size** determined at compilation or run-time .
--
* You can construct .green[**very large**].
--
* You .red[**need to manually delete dynamic arrays**].

---
class: left, top
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

--
Any typo? :suspect:

---
class: left, top
### Constructing Dynamic Array

```c++
// Construction of array-of-integers with arbitrary.
int size = 0;
std::cin >> size; // size determined at run-time.

// You cannot construct static arrays with an arbitrary size like in dynamic array.
int *array1 = new int[ size ];

// Construction of array-of-characters with size 150000 (around 150 Mega Bytes in memory).
char *dna_chromosome11 = new char[ 150000 ];
```

Any typo? :feelsgood:

---
class: left, top
### Memory Management

```c++
int *array1 = new int[ 900 ];

char *dna_chromosome11 = new char[ 150000 ];

// Load some DNA from external file to the constructed array
loadDNA( dna_chromosome11 , 150000 , "/home/user/chromosomes/some-dna.txt");

// Do some interesting analysis on your genome.
someInterestingFunction( &dna_chromosome11[0] , 150000 );

// Another operations on array1
anotherInterestingFunction( &array1[0] , 900 );

// After we no longer need array1,
delete [] array1; // Note the square brackets!
delete [] dna_chromosome11;
```

---
class: left, top
## Special Case: Array of Characters (String)

```c++
// Alternative way of Construction + Initialization of array-of-characters of size 6
char dna[] = { 'A' , 'A' , 'C' , 'T' , 'G' , 'C' , '\0'};

std::cout << dna << std::endl; // Prints: AACTGC
```

---
class: left, top
## Basic Operations on Static and Dynamic Arrays

### Copying between arrays

--
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


---
class: left, top
## `std::copy`

--
```c++
std::copy( &dna1[0] , &dna1[6] , &dna2[0] );
```

--
To copy from **source** array to **target** array:


--
1. Address of first element of **source** array.
--
2. Address of last element of **source** array.
--
3. Address of first element of **target** array.


--
Equivalent to:

```c++
for( int i = 0 ; i < 7 ; ++i )
{
    dna2[i] = dna1[i];
}
```


---
class: left, top
## Command Line Arguments

--
### Examples: Why Command Line Arguments


--
* `apt-get install vlc`
* `git commit -a -m "correction of problem 3!"`
* `cp [file] [target path]`



---
class: left, top
### Command Line Arguments in C and C++

--
```c++
#include <iostream>
// argc is counter for the arguments, including the application-name.
// argv is array of strings representing the arguments.
int main( int argc, char *argv[] )
{
    std::cout << "Arguments count:" << argc << std::endl;

    for( int i = 0 ; i < argc ; ++i )
    {
        std::cout << "Argument:" << argv[ i ] << std::endl;
    }
}
```

---
class: left, top
#### Example: Simple calculater from command line arguments

--
What if we have a simple calculator like this.

--
```terminal
$ ./myCalculator 12.4 + 3.2
20
```

--
![](/gallery/argv2.svg)


---
class: left, top

#### Convert from string form to integer form?

--
```c++
int x = "40"; // Compiler Error (Type Mismatch)

int y = std::atoi("40"); // Now this works, and y = 40.

double z = std::atof("13.9"); // z = 13.9
```

--
* `std::atoi` converts string representation => integer representation.
--
* `std::atof` converts a string representation => double representation.
--
* `#include <cstdlib>`.

---
class: left, top

```c++
#include <iostream>
#include <cstdlib>

// Our logic
double calculation( double a , double b , char operation );

int main( int argc , char *argv[] )
{
    double a = std::atof( argv[1] );
    double b = std::atof( argv[3] );

    char *op_string = argv[2];
    char op = op_string[0];

    std::cout << calculcation( a , b , op ) << std::endl;
    return 0;
}

```

---
class: left, top

```c++
double calculation( double a , double b , char operation )
{
  switch( operation )
  {
    case '+' :
    {
      return a + b;
    } break;

    case '-':
    {
      return a - b;
    } break;

    case '*':
    {
      return a * b;
    } break;

    case '/':
    {
      return a / b;
    } break;

    default:
    {
      return 0;
    }
  }
}
```

---
class: left, top
![](/gallery/argv2.svg)


---
class: left, top
## Making Your Own Header Libraries

### [{DRY}](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself)
#### i.e Don't repeat your self

* Don't copy codes.
* If you need to fix a mistake, fix it from one place.

---
class: left, top

<img style="width:95%" src="/gallery/multiplefiles.svg">


---
class: left, top
# Thank you

* Please Read the notes 
  * <a href="/2019/data-structures/notes/3_week3a" target="_blank">{Part 1: Static Arrays and Dynamic Arrays}</a>
  * <a href="/2019/data-structures/notes/3_week3b" target="_blank">{Part 2: Command Line Arguments and Compilation of Multiple Files}</a>

</textarea>

