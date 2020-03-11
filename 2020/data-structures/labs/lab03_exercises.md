---
layout: page
course: "sbe201"
category: "lab"
year: "2020"
title:  "Lab 3: Recursion and Arrays"
by: "Asem"
pdf: true
---

* TOC
{:toc}

## Application 1: Power Function


Using recursion function, write a program to compute $b^e$ while the base $b$ is double and the exponent $e$ is positive integer.

Start from the following code (name the file as `power.cpp`):


```c++
double power( double base, int exponent )
{

}

int main(int argc, char **argv)
{


}
```

Finally compile your file:

```bash
g++ power.cpp -o power
```

Test your program:

```bash
./power 3.14 2
```


## Application 2: Signal Analysis 

Write two programs that receive a signal, store the signal in a dynamic array, then apply analysis function to compute the **min**, **max**, **sum**, **mean**, and **variance**.


1. First program receives the signal from the input stream via `std::cin`: first your receive the size to construct a dynamic array, then you start storing values afterwards.
2. Second program receives the signal from the command line arguments via `argc` and `argv`.

You can start from the following files:


1- `analysis.hpp`: the header file that includes the analyses functions

```c++
double min( double *arr, int size )
{
    

}

double max( double *arr, int size )
{
    
    
}

double sum( double *arr, int size )
{

}

double mean( double *arr, int size )
{
    
}

double variance( double *arr, int size )
{
    
}
```

2- `analyze_cin.cpp`: the program file that will process the signal from the input stream.

```c++
#include "analysis.hpp"

int main()
{



}
```

3- `analyze_args.cpp`: the program file that will process the signal from the `argc` and `argv`.

```c++
#include "analysis.hpp"

int main(int argc, char **argv)
{



}
```