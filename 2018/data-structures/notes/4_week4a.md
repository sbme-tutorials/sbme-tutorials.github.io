---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 4 - Part1: Struct, Stacks, Queues, and Linked Lists"
by: "Asem"
---

## General

* classroom rules.
* ما حك جلدك مثل ظفرك

## Before starting: Stack as Data Structure != Stack Memory

Stack as a data structure is not related to the **stack memory** area we learned about last weeks, and they are completely different things. So just refer to *stack as a data structure* by **Stack**, and the stack memory area by **Stack memory**. Make yourself a glossary on your notebook.

## Struct

In first week, we have walked through different primitive data types (PDTs), or the first-class citizens in the C++. However, we can make our own types, that consists of multiple members, using `struct` feature. *Members* in `struct` can either be primitive data types (PDT) or other `struct`s. Let's recall our example of `rectangle::area` function.

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
}
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
}

int main()
{
    rectangle::Rectangle rect{ 3 , 5 }; // declaration+initialization of Rectangle type!
    
    std::cout << rectangle::area( rect ) << std::endl;

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
}


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

    // DRY solution ==> return sumArray1( array.base , array.size );
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

We can also use `struct` to **return multiple values**, which is more safe and clean than using multiple references as input and mofifying our interesting results into these input references.

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

## Stacks

In fact, **Stack** is more of *behaviour* of structure than being a structure itself. We can turn a regular array (either static or dynamic) into a **stack** with simple modification.




## Queues

## Array-Based Stacks

## Array-Based Queues

## Linked Lists

## List-Based Stacks

## List-Based Queues
