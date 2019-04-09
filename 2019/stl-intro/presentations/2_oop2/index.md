---
layout: presentation
style: laminal
highlighter: github
course: "stl2019"
category: "presentation"
year: "2019"
title: "Introduction to OOP 2"
by: "Asem"
author: "Asem Alaa"
---

<textarea id="source">

---
## Constructors

```c++
struct Point
{
    double x;
    double y;
};
```

--
### Old ways to create `Point`

--

```c++
Point p1{ 1, 1}; // Uniform initialization (C++11)
```

--

```c++
Point p2 = {0 , 0}; // Initialization list
```

--

```c++
Point p3; // Random values for x and y members of p3
p3.x = 2.5;
p3.y = 3.5;
```

--
#### Limitations

--

* Not flexible, not clever.

---

#### Consider the following cases

--

```c++
// You need the two members initialized with `2`
// without explicitly repeating the value
Point p{2}; // Invalid.
```

--

```c++
// You need the members to automatically initialized
// with zeros when you declare `p` as following
Point p; // p.x and p.y have random values :(
```

---

#### Solution

--

##### Constructors

--

* Constructors are _special methods (members)_.
* have _special declaration syntax_:

--

1. They must have the **same name** of the `struct`/`class`.
--
1. They don't return and are exempted from using `void` as a return type.

---

### Declaration

```c++
struct Point
{
    double x;
    double y;
};
```

---

### Declaration (cont'd)

```c++
struct Point
{
    double x;
    double y;

    // Default constructor. Takes no argument.
    Point()
    {
    }

    // Constructor 2. Takes one argument.
    Point( double v )
    {
    }

    // Constructor 3. Takes two argument
    Point( double u, double v)
    {
    }
};
```

---

### Declaration (cont'd)

```c++
struct Point
{
    double x;
    double y;

    // Default constructor. Solves case 1
    Point()
    {
        x = 0;
        y = 0;
    }

    // Constructor 2. Solves case 2.
    Point( double v )
    {
        x = v;
        y = v;
    }

    // Constructor 3. Solved case 3.
    Point( double u, double v)
    {
        x = u;
        y = v;
    }
};
```

---

### Calling the constructor

--

#### Default constructor

```c++
Point p1; // Default constructor called. Now p1.x and p1.y equal zero.
```

--

#### Custom constructor 2 (one argument)

```c++
Point p2( 1.0 ); // Constructor 2 called. Now p2.x and p2.y equal 1.0.
```

--

#### Custom constructor 3 (two arguments)

```c++
Point p3( 0, 1 ); // Constructor 3 called. Now p3.x equals 0 and p3.y equal 1.
```

#### Other calling syntax

```c++
Point p4 = Point( 3.0 ); // Alternative way to call the constructor.
Point *p5 = new Point( 3 , 2 ); // Heap allocation.
```

---

## Default arguments

A default argument is a value assigned to input parameter, when the user doesn't provide a value corresponds to the parameter, then the parameter will get the default value.

Consider the function `printLL` that prints all the elements of a linked list:

```c++
void printLL( const IntLL &l )
{
    auto *current = l.head;
    while( current != nullptr )
    {
        std::cout << current->data << "->";
        current = current->next;
    }
}
```

If we need to control the seperator between elements we can write the function as following:

```c++
void printLL( const IntLL &l , const std::string &sep )
{
    auto *current = l.head;
    while( current != nullptr )
    {
        std::cout << current->data << sep;
        current = current->next;
    }
}
```

So `sep` can be any `std::string` like: "->", "*", "-", " ", ":", "".

We can have a more interesting version of `printLL` when we don't need to bother the user with the `sep` value. So when the user doesn't provide a `sep` of his/her choice, we use a **default** one.

```c++
void printLL( const IntLL &l , const std::string &sep = "->" )
{
    auto *current = l.head;
    while( current != nullptr )
    {
        std::cout << current->data << sep;
        current = current->next;
    }
}
```

We can also apply the default arguments to the constructors.


```c++
struct Point
{
    Point( double u = 0, double v = 0)
    {
        x = u;
        y = v;
    }

    double x;
    double y;
};
```

Now the user can:

1. provide no arguments: x and y will be initialized with the default `u` and `v` (i.e zeros).
1. provide a single argument: x will be initialized with `u` and `y` with the default `v` (i.e zero).
1. provide two arguments: both `x` and `y` get initialized with `u` and `v`, respectively.

## Const-correctness

We already know how to pass arguments by constant reference or address, and know why it is important to do so, don't we? :sun_with_face:

Recall the following functions that works on the `IntegerLL` from *Week 5* notes:

```c++
int front( const IntegerLL &list )
{
    // Logic
}

int back( const IntegerLL &list )
{
    // Logic
}

bool isEmpty( const IntegerLL &list )
{
    // Logic
}

void printAll( const IntegerLL &list )
{
    // Logic
}
```

What if we now have these functions as methods inside the `struct` of `IntegerLL`?

```c++
struct IntegerLL
{
    int front()
    {
        // Logic
    }

    int back()
    {
        // Logic
    }

    bool isEmpty()
    {
        // Logic
    }

    void printAll()
    {
        // Logic
    }

    // default constructor.
    IntegerLL()
    {
        front = nullptr;
    }

    IntegerNode *front;
};
```

We omitted the `const IntegerLL&` because now these methods have direct access to `front`, which is the front of the linked list. **But how to guarantee constness?!** Or how to make sure that these methods are not going to miss up with our data? 

Very simple, just add `const` after the function declaration line!

```c++
struct IntegerLL
{
    int front() const
    {
        // Logic
    }

    int back() const
    {
        // Logic
    }

    bool isEmpty() const
    {
        // Logic
    }

    void printAll() const
    {
        // Logic
    }

    // default constructor.
    IntegerLL()
    {
        front = nullptr;
    }

    IntegerNode *front;
};
```

## Introduction to Templates

We realized that we have extremely violated the **DRY** principle in the last assignment, when you are asked to provide a linked list implementation of the following types:

1. `char`.
2. `std::string`.
3. `Patient` (defined in `custom_types.hpp`)
4. `Point` (defined in `custom_types.hpp`).
5. `double`. 
6. `int`. 

So what we did is implementing it for `char`, then copying the implementation 5 times and replace each `char` with the new type!

**In C++, we could have made a single implementation for all types, where templates come to our aid!**

Consider what we did in `CharsLL`:

```c++
struct CharNode
{
    // default constructor.
    Node()
    {
        next = nullptr;
    }

    // when user provides a value for data member, or both.
    Node( char value, Node *nextPtr = nullptr )
    {
        next = nextPtr;
        data = value;
    }

    char data;
    CharNode *next;
};

struct CharsLL
{
    // The compiler will generate a default constructor that initialize head.
    CharNode *head = nullptr; 
};

void insertFront( CharsLL &list , char data )
{

}

void insertBack( CharsLL &list, char data )
{

}

void removeFront( CharsLL &list )
{

}

void removeBack( CharsLL &list )
{

}
```

How to kill the redundancy? We can let `T` to represent the variant type. So `T` can be `char`, `int`, `std::string` and so on. 


**First step**: templetize the `struct`s: data member of agnostic type (for example T).
```c++
struct Node
{
    // default constructor.
    Node()
    {
        next = nullptr;
    }

    // when user provides a value for data member, or both.
    Node( T value, Node *nextPtr = nullptr )
    {
        next = nextPtr;
        data = value;
    }


    T data;
    Node *next;
};

struct LL
{
    Node< T > *head = nullptr;
};
```

But the compiler doesn't know what `T` is. So now we will learn a new statement **to declare a template type** for the `struct` or the functions.

We will just add `template <typename T>` directly above the struct declaration.

```c++
template< typename T>
struct Node
{
    // default constructor.
    Node()
    {
        next = nullptr;
    }

    // when user provides a value for data member, or both.
    Node( T value, Node *nextPtr = nullptr )
    {
        next = nextPtr;
        data = value;
    }

    T data;
    Node *next;
};

template< typename T>
struct LL
{
    Node< T > *head = nullptr;
};
```

Now we can call a `Node` to be of `char` by calling `Node< char >`. Similarly, to get a `LL` of `char`, we call it now `LL< char >`.

So our functions that work on linked list of characters should now be:

```c++
void insertFront( LL<char> &list , char data )
{

}

void insertBack( LL<char> &list, char data )
{

}

void removeFront( LL<char> &list )
{

}

void removeBack( LL<char> &list )
{

}
```

We now killed the redundancy of the `struct`, but we still have to repeat the functions to work on:

1. `LL<std::string>`
1. `LL<Patient>`
1. `LL<Point>`
1. `LL<double>`
1. `LL<int>`

Fortunately, we can also templetize the functions!

2. **Step 2**: templetize the functions to work on input of type `LL<T>`, where `T` is a place holder that can be `char`, `int`, `double`... etc.

```c++
void insertFront( LL< T > &list , T data )
{

}

void insertBack( LL< T > &list, T data )
{

}

void removeFront( LL< T > &list )
{

}

void removeBack( LL< T > &list )
{

}
```

Again! the compiler doesn't know what `T` is! we already know that `LL` is a template `struct`, so we call it as `LL< char >`, `LL<std::string>, ...etc. So we need to declare that the above functions are also template functions that operates in terms of agnostic type (T).

```c++
template< typename T>
void insertFront( LL< T > &list , T data )
{

}

template< typename T>
void insertBack( LL< T > &list, T data )
{

}

template< typename T>
void removeFront( LL< T > &list )
{

}

template< typename T>
void removeBack( LL< T > &list )
{

}
```

Now the final template linked list file will look as following:


```c++
template< typename T>
struct Node
{
    // default constructor.
    Node()
    {
        next = nullptr;
    }

    // when user provides a value for data member, or both.
    Node( T value, Node *nextPtr = nullptr )
    {
        next = nextPtr;
        data = value;
    }

    T data;
    Node *next;
};

template< typename T>
struct LL
{
    Node< T > *head = nullptr;
};

template< typename T>
void insertFront( LL< T > &list , T data )
{

}

template< typename T>
void insertBack( LL< T > &list, T data )
{

}

template< typename T>
void removeFront( LL< T > &list )
{

}

template< typename T>
void removeBack( LL< T > &list )
{

}

template< typename T>
void removeNth(LL< T > &list, int index)
{

}

template< typename T>
void removeNext(LL< T > &list, Node<T> *node)
{

}

template< typename T>
char front(const LL< T > &list)
{

}

template< typename T>
char back(const LL< T > &list)
{

}

template< typename T>
char getNth(const LL< T > &list, int index)
{

}

template< typename T>
bool isEmpty(const LL< T > &list)
{

}

template< typename T>
int size(const LL< T > &list)
{

}

template< typename T>
void printAll(const LL< T > &list)
{

}

template< typename T>
void clear(LL< T > &list)
{

}
```

Now in the main function, or whatever function that depends on our template types, we are going to use the linked lists as following:

```c++
#include "member1.hpp"

int main()
{
    LL<int> lli;
    insertFront( lli, 2 );
    
    LL<char> llc;
    insertFront( llc, 'A');
}
```

If you don't like using much `<>` in the main function, you can use aliases instead.

```c++
#include "member1.hpp"

// perfect DRY solution!
using CharsLL = LL< char >;
using IntegersLL = LL< int >;
using StringsLL = LL<std::string>;
using PatientsLL = LL<Patient>;
using PointsLL = LL<Point>;
using DoublesLL = LL<double>;

int main()
{
    IntegersLL lli;
    insertFront( lli, 2 );
    
    CharsLL llc;
    insertFront( llc, 'A');
}
```


## Access modifiers


## Self-reading

1. Destructors
1. Enum types



</textarea>
