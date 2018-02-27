---
layout: page
course: "sbe201"
category: "assignment"
year: "2018"
title:  "Assignment 3 - Part 2: Structs and Function Overloading"
by: "Asem"
pdf: true
---

## Prerequisites

* **Required**: Read the **struct** and **function overloading** in \[[Part1: Struct, Stacks, Linked Lists, and Queues]({{ site.baseurl }}{% link 2018/data-structures/notes/4_week4a.md %}){:target="_blank"}\]

## Objectives

* Using `struct` to encapsulate objects.
* Use `struct` to return multiple values instead of **pass-by-reference**.
* Realize the readability gains by using `struct`.
* Understand *function overloading*.

## Deadline

**Friday 2/3/2018 10 AM**.

## Assignment: Part 2

Using **the same repository** of **Part 1**. It is required to make your own `struct`s to encapsulate multiple variables. Attempt the new requirements on the same files of **Part 1**.

### Example 1

* **E1.1** declare a `struct` (new type), with name `Triangle`, to encapsulate the **triangle sides**, three doubles.

**Solution: add the following `struct` inside `mathematics` namespace.**

```c++
struct Triangle
{
    double a;
    double b;
    double c;
};
```

* **E1.2** add another version of `double heron( double a , double b , double c )`, but with using `Triangle` type, as follows:

```c++
double heron( Triangle t )
{
    // Same logic here.
    // DRY solution is recommended
}
```

* **E1.3**  Edit the `main` function in `heron.cpp` to make it work with `Triangle` instead of `a`, `b`, `c`.

**Solution: in your `main` function in `heron.cpp` replace the commented lines in the following snippets**

```c++
// double a = 0;
// double b = 0;
// double c = 0;

// Replace the commented lines above with this line.
mathematics::Triangle t{ 0 , 0 , 0 };
```

```c++
// std::cin >> a >> b >> c;

// replace the commented line above with this line.
std::cin >> t.a >> t.b >> t.c;
```


```c++
// std::cout << mathematics::heron( a , b , c ) << std::endl;

// replace the commented line above with this line.
std::cout << mathematics::heron( t ) << std::endl;
```

### Requirement 1: in **arrays.hpp** file

* **R1.1** declare a `struct` (new type), with name `DoubleArray`, to encapsulate the **base pointer** and the **size** of **double array**.
* **R1.2** declare a `struct` (new type), with name `CharacterArray`, to encapsulate the **base pointer** and the **size** of **character array**.
* **R1.3** **add another version** of the functions you implemented in **Part 1** using the following declarations:

```c++
void printAll( DoubleArray array )
{
    // Logic here
}
```

```c++
double maxArray( DoubleArray array )
{
    // Logic here
}
```

```c++
double minArray( DoubleArray array )
{
    // Logic here
}
```

```c++
double meanArray( DoubleArray array )
{
    // Logic here
}
```

```c++
double varianceArray( DoubleArray array )
{
    // Logic here
}
```


### Requirement 2: in **ecg.hpp** file

* **R2.1** **ECG** array is actually a **double** array. Instead of making a new `struct` as follows:

```c++
struct ECGArray
{
    double *array;
    int size;
};
```

We can just make a new **type alias** of `DoubleArray` with using an interesting name, using the following syntax:

```c++
using ECGArray = DoubleArray;
```

This line declares a new type equivalent to `DoubleArray` but with another name (alias).

* **R2.2** declare a `struct` (new type), with name `Statistics`, to encapsulate the following `double` members:
  * `mean`
  * `variance`
  * `min`
  * `max`


* **R2.3** Make another version of `analyzeECG` that takes `ECGArray` as input and returns `Statistics`:

```c++
Statistics analyzeECG( ECGArray ecg )
{
    // Logic here (4 lines)
}
```

* **R2.4** Change `main` function in `analyzeECG.cpp` file to make it using the custom types you just made. Follow the comments below to change some lines of `analyzeECG.cpp`:

```c++
int main( int argc , char **argv )
{
    if( argc != 2 )
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    }
    else
    {
        int size = 0;
        double *ecgArray = helpers::getECG( argv[1] , size );

        // 1. declare `ecg::ECGArray` variable with name ecg, and initialize it with {ecgArray,size}
        

        // 2. declare `ecg::Statistics` variable with name stats, and initialize it with the results of `analyzeECG( ecg )`


        std::cout <<"ECG average : " << stats.mean << std::endl
                 << "ECG variance: " << stats.variance << std::endl
                 << "ECG range   : (" << stats.min << "," << stats.max << ")" << std::endl;

        delete [] ecgArray;
        return 0;
    }
}
```

### Requirement 3 (Bonus)

Feel free to add your own `struct`s in `dna.hpp`. The objective of using `struct` (or you custom type), is to make you code more readable, modular, and strongly-typed. Also, make use of your new types in the `main` function in `analyzeDNA.cpp`.

## Submission

* As usual, commit and push your changes.
* **Requirement 3** is completely counted as bonus.
* Also, you may obtain bonus with correct logic by consistent adoption of [KISS](https://en.wikipedia.org/wiki/KISS_principle) and [DRY](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself) principles. Also, make your code clean, well-aligned, and use descriptive variable names.

## Generating Executables and Testing Output

### Compiling and Testing calculator.cpp

```bash
$ g++ calculator.cpp -o Calculator
$ ./Calculator 24 / 7
3.42857
$ ./Calculator 24 \* 7
```

**Note: asterisk `*` is a special character for the terminal. You need to explicitly use `\*` to specify multiplication operation.**

### Compiling and Testing heron.cpp

```bash
$ g++ heron.cpp -o Heron
$ ./Heron 3 4 5
6
```

### Compiling and Testing heron.cpp

```bash
$ g++ heron.cpp -o Heron
$ ./Heron 3 4 5
6
```

### Compiling and Testing analyzeECG.cpp

We compile and test using an ECG dataset stored in `datasets/ecg_data.txt`.

Our application in the `main` function loads data from the file then use `ecg::analyzeECG`
function implemented in `ecg.hpp`.

```bash
$ g++ analyzeECG.cpp -o AnalyzeECG
$ ./AnalyzeECG datasets/ecg_data.txt
ECG average : 0.785639
ECG variance: 0.00780314
ECG range   : (0,1.288)
```

### Compiling and Testing analyzeDNA.cpp

We compile and test using a DNA dataset stored in `datasets/genetic_data.txt`.

Our application in the `main` function loads data from the file then use `dna::analyzeDNA`
function implemented in `dna.hpp`.

```bash
$ g++ analyzeDNA.cpp -o AnalyzeDNA
$ ./AnalyzeDNA datasets/genetic_data.txt
Adenine (A) content:75
Guanine (G) content:84
Cytocine(C) content:83
Thymine (T) content:76

Complementary Sequence:
CCAGTATTTGACAGGCTGGACTGAGCTACTTGCCGTTCCGGGATAAGTAGTTCAGACAGGCTGCCCACAACGTACAAAGACGGCCAGTTCTCCGCATATCGCGGCATTCGAGTCCGGCAAATAGCGAGTTAGCCTCTTCTTGCGCTGGACCTTTTCTAGCCGCATGACTAGTTGCCAAGGCTGAAGCCCAAGTTAGAGTGGCATGTAGTCCCTCAGTGAAGGGAATGGCTCGAGTCGAAGCAGCTTACAGCACAGCTCTCGACTCCTAATTGGGTCGAAGCCTATCAACTATCCACGTAGTGTCCAGTATTTGACAGT
```