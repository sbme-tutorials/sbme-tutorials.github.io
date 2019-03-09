---
layout: page
course: "sbe201"
category: "assignment"
year: "2019"
title:  "Assignment 3 - Part 2: Struct and Functions Overloading"
by: "Asem"
pdf: true
---

## Prerequisites

* **Required**: Read the **struct** and **function overloading** in \[[Struct, Stacks, Linked Lists, and Queues]({{ site.baseurl }}{% link 2019/data-structures/notes/4_week4a.md %}){:target="_blank"}\]

## Objectives

* Functions Overloading: make functions with **same name**, **but different parameters types/count**.
* Make your own types by using `struct` feature of C++.
* Make another version of your functions implemented in **Part 1** but with using your own types (`struct`s).
* Realize importance of `struct` to encapsulate objects.
* Realize the importance of `struct` to return multiple values instead of **pass-by-reference**.
* Realize the readability gains by using `struct`.
* Understand *function overloading*.

## Deadline

**Sunday 14/3/2019 11:59 PM (PST)**.

## Assignment: Part 2

In this task, we will work on **the same repository** of previous task (part 1). It is required to make your own `struct`s to encapsulate multiple variables. After you finish the requirements of the previous task and validate the results, you will ask the *git repository* to give a special name to the current state of your task. This will allow you to easily get back to the old version of your code regardless the amount of modifications you have made after that point of time.


**Don't proceed to assignment 2 before tagging your last commit on part1, so we can easily switch between the last version and part1 version.** 

### Tagging your work on Part 1

Take your terminal to your repository folder, then issue the following command:

```
git tag part1
```

Now transfer this tagging to the GitHub, so anyone using your repository can use this tag as well to see your part 1 version:

```
git push origin --tags
```

No if you made any modifications and additional commits, you can get back to the old state by the following command:

```
git checkout part1
```

Now you will see that all your files in their old version of part1. To return back to the newest state so you proceed your work:

```
git checkout master
```



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
using ECGArray = arrays::DoubleArray;
```

To use the above feature in C++, the feature of `using TypeAlias = SomeType`, is supported in C++ standard of 2011. When you compile make sure to inform the compiler what standard you are using. So you will need to add an additional flag to the compiler `-std=c++11`.


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
$ g++ -std=c++11 calculator.cpp -o Calculator
$ ./Calculator 24 / 7
3.42857
```

### Compiling and Testing heron.cpp

```bash
$ g++ -std=c++11 heron.cpp -o Heron
$ ./Heron 3 4 5
6
```

### Compiling and Testing analyzeECG.cpp

We compile and test using an ECG dataset stored in `datasets/ecg_data.txt`.

Our application in the `main` function loads data from the file then use `ecg::analyzeECG`
function implemented in `ecg.hpp`.

```bash
$ g++ -std=c++11 analyzeECG.cpp -o AnalyzeECG
$ ./AnalyzeECG datasets/ecg_data.txt
ECG average : 0.82964
ECG variance: 0.00865574
ECG range   : (0.592,1.408)
```

### Compiling and Testing analyzeDNA.cpp

We compile and test using a DNA dataset stored in `datasets/hepatitis_c_virus_genome.txt`.

Our application in the `main` function loads data from the file then use `dna::analyzeDNA`
function implemented in `dna.hpp`.

```bash
$ g++ -std=c++11 analyzeDNA.cpp -o AnalyzeDNA
$ ./AnalyzeDNA datasets/hepatitis_c_virus_genome.txt
Adenine (A) content:??
Guanine (G) content:??
Cytocine(C) content:??
Thymine (T) content:??

Complementary Sequence:
???
```
