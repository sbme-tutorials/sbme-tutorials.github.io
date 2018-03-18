---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 7 - Part1: Revision"
by: "Asem"
---

* TOC
{:toc}

## Practices and Common Issues

### Names and Scopes

#### Common Mistake: type != variable name

```c++
struct IntegerNode
{
    int data;
    IntegerNode *next;
};

struct IntegersLL
{
    IntegerNode *head;
};

int size( IntegersLL &lst )
{
    // Find mistakes
    front = IntegersLL.head; // Error

    // Who is front?

    // Who is IntegersLL?

    // Who is IntegersLL.head?
}
```

* Don't use any name unless it is **declared**. `front` is undeclared.
* `IntegersLL` is a **type** not a **name** of a variable.

### Common Mistake: when passing by reference don't mess with input data

```c++
int size( IntegersLL &lst )
{
    // Find mistakes
    int count = 0;
    while( lst.head != nullptr )
    {
        count++;
        lst.head = lst.head->next;
    }
    return count;
}
```

### Common Mistake: Pointer to struct != Reference to a struct != Name to a struct

```c++
struct IntegerNode
{
    int data;
    IntegerNode *next;
};

struct IntegersLL
{
    IntegerNode *head;
};


int size( IntegersLL &lst )
{
    // Find two mistakes
    int count = 0;
    IntegersNode *current = lst->head; // Error

    while( current != nullptr )
    {
        count++;
        current = current.next; // Error
    }
    return count;
}
```

### Functions

#### Bad Practice: Global Variables

**As a rule of thumb**, inside a function, all what you have got is the function input.

```c++
struct IntegerNode
{
    int data;
    IntegerNode *next;
};

struct IntegersLL
{
    IntegerNode *head;
};

// Never do this. You are breaking the concept of a function!
IntegersLL myList; // A global variable

int size( IntegersLL &lst ) // unused input lst!
{
    int count = 0;

    // This function will only work with the global variable `myList`
    // We cannot apply this function to any other Linked List of integers!
    IntegersNode *current = myList.head;

    while( current != nullptr )
    {
        count++;
        current = current->next;
    }
    return count;
}
```

The **correct** solution

```c++
struct IntegerNode
{
    int data;
    IntegerNode *next;
};

struct IntegersLL
{
    IntegerNode *head;
};

int size( IntegersLL &lst )
{
    int count = 0;
    IntegersNode *current = lst.head;

    while( current != nullptr )
    {
        count++;
        current = current->next;
    }
    return count;
}
```

#### Common mistakes in calling functions

```c++
#include "linkedlist.hpp"
#include <iostream>

int main()
{
    list::IntegersLL samples;

    // Why you do this?
    std::cout << "size:" << list::size( IntegersLL &lst ); // error

    // Or this?
    std::cout << "size:" << list::size( IntegersLL &samples ); // error

    // We already declared samples of type list::IntegersLL
    std::cout << "size:" << list::size( samples ); // good
}
```

### Main Function

#### Useful Application

The `main` function is the program entry point. In practice, developers build libraries over libraries, in order to be finally used in the `main` function. Recall the diagrams of **week 3**.

![multiple](/gallery/multiplefiles.svg)

![dependencies](../assignments/task3.svg)

#### Testing Application

It is always useful to make a file with a `main` function to test the functions and structures you have just developed so:

1. You feel satisfied about what you have developed.
2. Detecting any unexpected behavior, and accordingly helps you debug your code.


Each member in a group assignment is required to make a file with a `main` function to test his/her developed functions. **Due discussion date**.

##### Advanced: Unit Testing

In practice, testing libraries is carried out in a more formal and standardized methodologies. Although it is currently an advanced topic, you can read about [Test-Driven Development (TDD)](https://en.wikipedia.org/wiki/Test-driven_development) in the summer. In C++, there are famous unit testing frameworks, for example:

* [Google Test](https://github.com/google/googletest).
* [Catch2](https://github.com/catchorg/Catch2).
* [{Boost.Test}](http://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html)

## Data Structures: Big Picture

<img src="/gallery/ds1.svg" style="width:90%;">

### Complexity Analysis: Big-Oh Notation

## Segmentation Fault (Core Dumped)

**Fact** Although your application did compile without errors, doesn't mean it is logically correct or should run as expected.
So far, errors in C++ development can be classified into:

1. Compilation errors.
2. Run-time errors (bugs), and can be classified into:
  * Logical error: you don't get the expected output.
  * Critical error: you are abusing the memory access. This will result in a **crash** with an ambiguous message emitted `Segmentation fault (Code Dumped)`.

The **Segmentation fault** error typically results after:

* Dereferencing a `nullptr`.
* Dereferencing an un-initialized pointer, as a side-effect of undefined behavior.
* Dereferencing a pointer of a de-allocated place:
  * De-allocated place in stack memory after going out of scope.
  * De-allocated place in heap memory after `delete`ing that place using its pointer.
* Exceeding array boundaries.

### Memory Management and Memory Leakage

### Valgrind

#### Installing Valgrind

```terminal
sudo apt-get install valgrind
```

#### Running Valgrind

In order to trace your code to the point of the crash you need to compile your code with an additional flag `-g`. The flag `-g` tells your compiler to compiler your program in *Debugging* mode.

```bash
g++ -g -std=c++11 -Wall test.cpp -o test
```

* `-g` for debugging mode.
* `-std=c++11` to use the C++ standards of 2011.
* `-Wall` to emit any compilation warnings, very useful flag.
* `test.cpp` the source file that has a `main` function.
* `-o test` a flag for the compiler output followed by the output name of the executable.

```bash
valgrind -v --leak-check=full --show-leak-kinds=all ./test
```

### How to interpret a commit at github

As you already know, **git** commits are line-oriented, i.e documents changes in lines.
**green** lines represents added lines in that commit, while **red** lines represents removed lines from that commit.

<img src="/gallery/commit.png" style="width:90%;">


Each team member at github can be visualized his/her contribution in the repository.

<img src="/gallery/team.png" style="width:90%;">

> If we wish to count lines of code, we should not regard them as "lines produced" but as "lines spent". --- Edsger Dijkstra

## Where are we now

| Week | Data Structures & C++ | Ecosystem & Miscellaneous |
|------|----------------------|-----------|
| 1 | **Introduction**: Brief intro to DS; C++ Basics  | Briefly: Unix, compilation, git, github |
| 2 | C++ Memory Model, C++ Pointers and References | Your Code Readability |
| 3 | Static and Dynamic Arrays; Categorize your logic with `namespace` scopes;  | Processing command line arguments (`argc` & `argv`); Compilation of multiple files; Basic Unix commands; bitbucket |
| 4 | Stacks (ADT); Queues (ADT); Linked Lists; Array-Based Stack; LL-Based Stack; Array-Based Queue; LL-Based Queue; Functions Overloading;  Naming conventions; Const correctness; C++ classes and objects | Brief intro to  git for teams;  Brief intro to build systems |
| 5 | Recursion;   | Briefly: CMake; Git on large scale |
| 6 | Bubble sort; Selection sort; Binary Trees  | Open source vs. proprietary software  |
| 7 | C++ template structs and template functions; `std::string`; `std::vector`; `std::array`; `std::list`; `std::stack` | ... |

## Data Structures and Algorithms: What you must know for this semester until week 7

C++ is just a powerful tool to prove our computation theories!

### Focus on concepts

#### **Week 1**: C++ Basics

* **Essential**: Primitive data types (PDT)
* **Essential**: Variables, declaration, and initialization
* **Essential**: Functions, namespaces, and scopes
* **Essential**: `main` function and basic compilation
* **Extra**: git, github, bitbucket, and Linux.

#### **Week 2**: C++ Memory Model

* **Essential**: Pointers and references
* **Essential**: Static allocations (static)
* **Essential**: Heap allocations (dynamic)
* **Extra**: Code styling and best practices

#### **Week 3**: Arrays

* **Essential**: Static arrays
* **Essential**: Dynamic arrays
* **Extra**: Processing command line arguments
* **Extra**: Compilation of multiple files
* **Extra**: Separating libraries and application files

#### **Week 4**: Linked Lists, Stacks, and Queues

* **Essential**: Stack (ADT)
* **Essential**: Queue (ADT)
* **Essential**: Linked list
* **Essential**: Array implementation of stack
* **Essential**: Linked list implementation of stack
* **Essential**: Linked list implementation of queue
* **Essential**: Custom types using `struct`
* **Extra**: Function overloading
* **Extra**: Naming conventions
* **Extra**: Const-correctness
* **Extra**: Basic OOP at glance
* **Extra**: Build Systems (CMake)
* **Extra**: Git for teams

#### **Week 5**: Recursion and Big-Oh Notation

* **Essential**: Big-Oh notation
* **Essential**: Recursion
* **Extra**: Markdown

#### **Week 6**: Recursion and Big-Oh Notation

* **Essential**: Sorting
* **Essential**: Bubble sort and Selection Sort

#### **Week 7**: Revision, Common Mistakes, and Best Practices

* **Essential**: List using array
* **Extra**: Type normalization: C++ templates
* **Extra**: `std::string`, `std::vector`, `std::array`, `std::list`, `std::stack`.

## C++ Templates: Towards Polymorphism and DRY Solutions

As some of you have realized the latest assignment you have implemented a **linked list**, **stack**, or a **queue** for a certain data type, then you **repeated** your logic for the other data types. In C++, there are many polymorphism techniques can be employed to achieve more DRY solutions for such situations.

## Type Normalization in C++

```c++
// mylist.hpp
#include <cstdlib>
namespace list
{

template< typename T >
struct Node
{
    T data;
    Node *next;
};

template< typename T >
struct LL
{
    Node< T > *head = nullptr;
};

template< typename T >
void insertFront( LL< T > &lst ,  T data )
{
    auto newNode = new Node< T >{ data , lst.head };
    lst.head = newNode;
}

template< typename T >
void removeFront( LL< T > &lst )
{
    auto discard = lst.head;
    lst.head = lst.head->next;
    delete discard;
}

template< typename T >
T front( LL< T > &lst )
{
    if( lst.head )
        return lst.head->data;
    else exit( 1 );
}

template< typename T >
bool isEmpty( LL< T > &lst )
{
    return lst.head == nullptr;
}

}
```

In the `main` function you just need to **specialize** your template `struct` at the point of usage. See the following example of the DNA complementary sequence solved using **templates**.

```c++
// main.cpp
#include "mylist.hpp"
#include "helpers.hpp"
#include <iostream>
#include <string>

char complementaryBase( char base )
{
    if( base == 'A' ) return 'T';
    else if( base == 'T' ) return 'A';
    else if( base == 'G' ) return 'C';
    else return 'G';
}

int main( int argc , char **argv )
{
    std::string dna = helpers::getLines( argv[1] )[0];

    list::LL< char > ls; // Declaration + Instantiation of template LL

    std::string cdna;

    for( char base : dna )
    {
        list::insertFront( ls , complementaryBase( base ));
    }

    while( ! list::isEmpty( ls ))
    {
        cdna.push_back( list::front( ls ));
        list::removeFront( ls );
    }

    std::cout << cdna;
}
```

## Basic OOP: Revisited

```c++
template< typename T >
struct Node
{
    T data;
    Node *next;
};

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
struct LL
{
    Node<T> *head = nullptr;

    void insertFront( T data)
    {
        auto newNode = new Node<T>{data, head};
        head = newNode;
    }

    void removeFront( )
    {
        auto discard = head;
        head = head->next;
        delete discard;
};
```


Now we can use our template structure as:

```c++
int main( int argc , char **argv )
{
    std::string dna = helpers::getLines( argv[1] )[0];

    list::LL< char > ls;

    std::string cdna;

    for( char base : dna )
    {
        ls.insertFront( complementaryBase( base ));
    }

    while( ! ls.isEmpty())
    {
        cdna.push_back( ls.front());
        ls.removeFront();
    }

    std::cout << cdna;
}
```

To clone the whole demo:

```bash
git clone https://github.com/sbme-tutorials/sbe201-week7-demo.git
```

## std::string

To be completed

## std::vector

To be completed

## std::array

To be completed

## More Exercises

To be completed

### Central Dogma (Transcription and Translation)

To be completed

#### Queues

### Pangrams

To be completed

http://exercism.io/exercises/cpp/pangram/readme