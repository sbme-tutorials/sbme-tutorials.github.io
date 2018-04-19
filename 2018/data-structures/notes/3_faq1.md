---
layout: page
course: "sbe201"
category: "faq"
year: "2018"
title:  "FAQ #1: Why exposing namespaces is a bad practice"
by: "Asem"
---

## FAQ #1. Why `using namespace arbitrary_name;` is a bad practice

`namespace` is a great feature introduced in C++. It allows us to:

* Make modular projects.
* Put your functions in categories.
* Write more readable and self-explaining code.
* Write more trustable code by means of specifying which function belongs to what library.

It becomes more critical when it comes to the Standard Library of C++ that is enclosed in the namspace `std`. By writing `using namespace std;` in your global scope, this exposes huge amount of functions from the library to be used without the namespace. So What?!

* What if you have created a function having the same name of one of the thousands functions from `std`?

  * Names collision,
  * Compiler get confused,
  * Your team members get angry.

* You will never know every function inside the `std` so you avoid using a reserved name, and it is pointless to know every function and name inside the `std`.

### Possible Solution

If you are using (for example) `std::cout` extensively inside a function. What you can do is specifying a particular member (or members) that you are going to use:

```c++
// Some function that prints a lot of text in the terminal
void printArrayStatistics( int *array , int size )
{
    using std::cout;

    for( int i = 0 ; i < size ; ++i )
    {
        cout << array[0];
    }

    cout << mean( arr , size ) << std::endl;

    // More and more printing
    // And more.
}
```

**Again**, if you insist to expose some name-space:

* Specify particular members from the name-space, For example:

  * **DO** `using std::cout;`.
  * **DO NOT** `using namespace std;`.

* Do it inside a local scope, not in the global scope.