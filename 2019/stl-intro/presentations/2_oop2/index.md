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
## Output of this tutorial

1. Constructors
1. Default arguments
1. Const-correctness in OOP
1. Template classes and template functions
1. Access modifiers
1. Enum types

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
Point p3( 0, 1 ); // Constructor 3 called. p3.x equals 0 and p3.y equals 1.
```

--

#### Other calling syntax

```c++
Point p4 = Point( 3.0 ); // Alternative way to call the constructor.
Point *p5 = new Point( 3 , 2 ); // Heap allocation.
```

---

## Default arguments

--

### Example

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

--

```c++
//prints
element1->element2->element3->....
```

---

## Default arguments (cont'd)

--

### Example (cont'd)

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

`sep` might be any `std::string` e.g: (`"->"`), (`"*"`), (`"-"`), (`" "`), (`":"`), (`""`).

---

#### Results

--
* .green[we added more control on the function]
--
* .red[more control sometimes complicates (bad usability)]

---

### Solution: default arguments

--
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

--

```c++
// assume primes is `IntLL` and contains 2, 3, 5, 7

printLL( primes , "->"); // prints: 2->3->5->7
printLL( primes ); // prints: 2->3->5->7
printLL( primes , " -> "); // prints: 2 -> 3 -> 5 -> 7
printLL( primes , ":"); // prints: 2:3:5:7
printLL( primes , "\n"); // prints: ???
```

---

### Constructor default arguments

Remember

--
* constructors special member methods.
--
* but they are methods.

--
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

--
1. provide no arguments:
--
  * `x` and `y` will be initialized with zeros.
--
1. provide a single argument:
--
  * `x` will be initialized with `u` and `y` with zero.
--
1. provide two arguments: 
--
  * both `x` and `y` get initialized with `u` and `v`.

---

## Const-correctness

### Example

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

---

## Const-correctness (cont'd)

### Example (cont'd)

What if we them as methods?

---
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

---
* **But how to guarantee constness?!** 
* Or how to make sure that these methods are not going to miss up with our linked list?

---

## Const-correctness (cont'd)

### Example (cont'd)

--
#### Solution

--
Very simple, just add `const` after the function declaration line!

---
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

---

## Introduction to Templates

--

### Problem

--

* We extremely violated the **DRY** principle in the last assignment
* You were asked to provide a linked list implementation of the following types:

1. `char`.
2. `std::string`.
3. `Patient` (defined in `custom_types.hpp`)
4. `Point` (defined in `custom_types.hpp`).
5. `double`.
6. `int`.

---
So what we did is:

* implementing linked list for `char`.
--
* Copy the implementation 5 times and replace each `char` with the new type!

--

#### Results

1. Hard to fix bugs.
1. Lengthy code!
1. Redundant (+80% redundancy).

---

## Introduction to Templates

--

### Solution: template classes

--

* Single implementation for all types.

---

Consider what we did in `CharsLL`:

```c++
struct CharNode
{
    char data;
    CharNode *next;

    // default constructor.
    CharNode()
    {
        next = nullptr;
    }

    // when user provides a value for data member, or both.
    CharNode( char value, CharNode *nextPtr = nullptr )
    {
        next = nextPtr;
        data = value;
    }
};

struct CharsLL
{
    // The compiler will generate a default constructor that initialize head.
    CharNode *head = nullptr;
};
```

---

Consider what we did in `CharsLL`:


```c++
void insertFront( CharsLL &list , char data )
{
// Logic
}

void insertBack( CharsLL &list, char data )
{
// Logic
}

void removeFront( CharsLL &list )
{
// Logic
}

void removeBack( CharsLL &list )
{
// Logic
}
```

--
* And the their counterparts in other types: `int`, `std::string`,... etc.

---
#### Question

--
* How to kill the redundancy?

--
#### Idea

* let `T` represents the type of interest.
* So `T` can be `char`, `int`, `std::string` and so on.

---

## Introduction to Templates

### Solution: template classes

#### First step: templetize the `struct`

---

##### Before

```c++
struct CharNode
{
    char data;
    CharNode *next;

    // default constructor.
    CharNode()
    {
        next = nullptr;
    }

    // when user provides a value for data member, or both.
    CharNode( char value, CharNode *nextPtr = nullptr )
    {
        next = nextPtr;
        data = value;
    }
};

struct CharsLL
{
    // The compiler will generate a default constructor that initialize head.
    CharNode *head = nullptr;
};
```

---

##### Now

```c++
struct Node
{
    T data;
    Node *next;

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
};

struct LL
{
    Node< T > *head = nullptr;
};
```

--
* .red[But the compiler doesn't know what `T` is].
--
* **How to declare a template type T**.

---

##### Now

We will just add (`template < typename T >`)

```c++
template< typename T> // HERE
struct Node
{
    Node() // default constructor.
    {
        next = nullptr;
    }

    Node( T value, Node *nextPtr = nullptr )
    {
        next = nextPtr;
        data = value;
    }

    T data;
    Node *next;
};

template< typename T> // HERE
struct LL
{
    Node< T > *head = nullptr;
};
```

---

## Introduction to Templates

### Solution: template classes

--
* `Node` and `LL` are template types (not complete types).
--
* To get them complete:
--
  * `Node<char>`, `Node<int>`, `Node<std::string>`.
  * `LL<char>`, `LL<int>`, `LL<std::string>`.

---

## Introduction to Templates

### Solution: template classes

---
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

--
* We now .green[killed the redundancy of the `struct`]
--
* .red[but functions still redundant for other types]: `LL<std::string>`, `LL<Patient>`, `LL<Point>`, `LL<double>`, `LL<int>`.
--
* Fortunately, we can also templetize the functions!

---

## Introduction to Templates

### Solution: template classes

#### Second step: templetize the functions

--
templetize the functions: let `T` be type of interest.

--
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

---

* Again! the compiler doesn't know what `T` is!
--
* Compiler already know that `LL` is a template `struct`,
--
* But what particular `T` to use.
--
* We either:
--
  1. .red[Redundant solution]: call it as `LL< char >`, `LL<std::string>`, ...etc.
--
  1. .red[DRY solution]: declare that `T` is template type, i.e functions are now type agnostic.

---

## Introduction to Templates

### Solution: template classes

#### Second step: templetize the functions


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

---

#### Final template solution


```c++
template< typename T>
struct Node
{
    Node() // default constructor.
    { /* Logic */ }

    Node( T value, Node *nextPtr = nullptr )
    { /* Logic */ }

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
{ /* Logic */ }

template< typename T>
void insertBack( LL< T > &list, T data )
{ /* Logic */ }
...
```

---

## Introduction to Templates

### Solution: template classes

#### Client part (add to your glossary)

```c++
LL<int> lli;
insertFront( lli, 2 );

LL<char> llc;
insertFront( llc, 'A');
```

---

#### Client part (add to your glossary)

If you don't like using much `<>` in the main function, you can use aliases instead.

--
```c++
#include "member1.hpp"

// perfect DRY solution!
using CharsLL = LL< char >; // Done 16% of the assignment
using IntegersLL = LL< int >; // Done 32% of the assignment
using StringsLL = LL<std::string>; // Done 50% of the assignment
using PatientsLL = LL<Patient>; // Done 66% of the assignment
using PointsLL = LL<Point>; // Done 83% of the assignment
using DoublesLL = LL<double>; // Done 100% of the assignment

int main()
{
    IntegersLL lli;
    insertFront( lli, 2 );

    CharsLL llc;
    insertFront( llc, 'A');
}
```

---

#### Template + OOP

Instead of:

--
```c++
template< typename T>
struct Node
{
    Node() // default constructor.
    { /* Logic */ }

    Node( T value, Node *nextPtr = nullptr )
    { /* Logic */ }

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
{ /* Logic */ }

template< typename T>
void insertBack( LL< T > &list, T data )
{ /* Logic */ }
...
```

---
#### Template + OOP

Now (realize the .green[benign side-effect]):

--
```c++
template< typename T>
struct Node
{
    Node() // default constructor.
    { /* Logic */ }

    Node( T value, Node *nextPtr = nullptr )
    { /* Logic */ }

    T data;
    Node *next;
};

template< typename T>
struct LL
{
    Node< T > *head = nullptr;

    void insertFront( T data )
    { /* Logic */ }

    void insertBack( T data )
    { /* Logic */}
    // No need to declare T as template parameter for each method.
};
```

---

#### Template + OOP: Client part

--
```c++
#include "member1.hpp"

// perfect DRY solution!
using CharsLL = LL< char >; // Done 16% of the assignment
using IntegersLL = LL< int >; // Done 32% of the assignment
using StringsLL = LL<std::string>; // Done 50% of the assignment
using PatientsLL = LL<Patient>; // Done 66% of the assignment
using PointsLL = LL<Point>; // Done 83% of the assignment
using DoublesLL = LL<double>; // Done 100% of the assignment

int main()
{
    IntegersLL lli;
    lli.insertFront( 2 );

    CharsLL llc;
    llc.insertFront('A');
}
```

---
## Access modifiers

### The problem

--
* .red[We are not yet completely safe with **const-correctness**.]
--
* Imagine the following **client code**:

--
```c++
#include "member1.hpp"

// perfect DRY solution!
using CharsLL = LL< char >; // Done 16% of the assignment
using IntegersLL = LL< int >; // Done 32% of the assignment

int main()
{
    IntegersLL lli;
    lli.insertFront( 2 );
    lli.head = nullptr; // Ruined the linked list.

    CharsLL llc;
    llc.insertFront('A');
    llc.head = 20; // Much worse!
}
```

--
* How to protect sensitive members like `head`?

---
## Access modifiers

--
### Solution

--
We need to use at least two access modifiers to avoid such problem:

--
1. `public`: to make the members accessible outside.
--
1. `private`: to make the members only accessible by **internal members**.

---

```c++
template< typename T>
struct LL
{
    // Public or private?
    Node< T > *head = nullptr;

    // Public or private?
    void insertFront( T data )
    { /* Logic */ }

    // Public or private?
    void insertBack( T data )
    { /* Logic */}
    // No need to declare T as template parameter for each method.
};
```

---

```c++
template< typename T>
struct LL
{
private:
    Node< T > *head = nullptr;

public:
    void insertFront( T data )
    { /* Logic */ }


    void insertBack( T data )
    { /* Logic */}
    // No need to declare T as template parameter for each method.
};
```

---
#### Now we are safe!

--
```c++
#include "member1.hpp"

// perfect DRY solution!
using CharsLL = LL< char >; // Done 16% of the assignment
using IntegersLL = LL< int >; // Done 32% of the assignment

int main()
{
    IntegersLL lli;
    lli.insertFront( 2 );
    lli.head = nullptr; // Compiler error!

    CharsLL llc;
    llc.insertFront('A');
    llc.head = 20; // Compiler error!
}
```

---
### `struct` vs `class`

--
```c++
template< typename T>
class LL
{
private:
    Node< T > *head = nullptr;

public:
    void insertFront( T data )
    { /* Logic */ }


    void insertBack( T data )
    { /* Logic */}
    // No need to declare T as template parameter for each method.
};
```

---
### `struct` vs `class`

The only difference is:

* `class` members are private by default.
* `struct` members are public by default.

---
## Enum class

### The problem

--
```c++
struct Patient
{
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    char sex; // 'm' or 'f'
};
```

--
Let's first make constructor for this class.

---
## Enum class

### The problem


```c++
struct Patient
{
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    char sex; // 'm' or 'f'

    Patient( int vId, 
             const std::string &fname, 
             const std::string &lname, 
             int vAge,
             char vSex )
    {
        id = vId;
        firstName = fname;
        lastName = lastName;
        age = vAge;
        sex = vSex;
    }
};
```

---
## Enum class

### The problem


```c++
struct Patient
{
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    char sex; // 'm' or 'f'

    Patient( int vId, 
             const std::string &fname, 
             const std::string &lname, 
             int vAge,
             char vSex )
    { /* Initialization */ }
};
```

--
* `sex` can have any of the 256 possible value.
--
* we made heuristic assumption that `'f'` represents female and `'m'` represents male.
--
* vulnerable to bugs.

---
## Enum class

### The solution

--
* New tailored class for `sex`.

```c++
enum class Sex
{
    Male,
    Female
};
```

---
## Enum class

### The solution

```c++
struct Patient
{
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    char sex; // 'm' or 'f'

    Patient( int vId, 
             const std::string &fname, 
             const std::string &lname, 
             int vAge,
             char vSex )
    { /* Initialization */ }
};
```

---
## Enum class

### The solution

```c++
struct Patient
{
    int id;
    std::string firstName;
    std::string lastName;
    int age;
    Sex sex; // `Sex::Male` or `Sex::Female`

    Patient( int vId, 
             const std::string &fname, 
             const std::string &lname, 
             int vAge,
             Sex vSex )
    { /* Initialization */ }
};
```

---
## Enum class

### The solution


```c++
Patient p( 2, "Mostafa", "Mohamed", 60, Sex::Male );
```


---
## Self-reading

* Destructors
* [Learn C++](https://www.learncpp.com/)

</textarea>
