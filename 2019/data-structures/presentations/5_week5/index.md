---
layout: presentation
style: laminal
highlighter: monokai
course: "sbe201"
category: "presentation"
year: "2019"
title: "Week 5: More on Structs, Linked Lists, Const-correctness"
by: "Asem"
author: "Asem Alaa"
---

<textarea id="source">

---
### Type Aliasing

```c++
struct Position
{
    double x;
    double y;
};

using Coordinates = Position;
```

---
## C++ Milestones

--
<img src="/gallery/c++milestones.jpg" style="width:100%">

---
<img src="/gallery/c++milestones2.png" style="width:100%">

---
### Compiling C++ of 2003

--
```terminal
g++ -std=c++03 source_code.cpp -o output_name
```

---
### Compiling C++ of 2011

add flag `-std=c++11`

--
```terminal
g++ -std=c++11 source_code.cpp -o output_name
```

---
### Other Important g++ Compiler Flag

--
#### `-Wall` flag


--
* Let `g++` not just reports you errors.
--
* Let him report you all the **warnings**.
--
* Fixing **warning** avoids many run-time issues.


--
##### Compiling C++ of 2011 plus enable all warnings

```terminal
g++ -Wall -std=c++11 source_code.cpp -o output_name
```

---
## Assignment of Week 4

### General Linked List (LL): 11 operations


--
<iframe allowfullscreen src="http://www.algomation.com/embeddedplayer?embedded=true&algorithm=593432766bee1c0400365b82" width="600" height="371" seamless="seamless" frameborder="0" style="border:1px solid lightgray" scrolling="no"></iframe>

---
### LL operations:

--
* insertion at front.
--
* insertion at back.
--
* remove from front.
--
* remove from back.
--
* remove nth element.
--
* return front.
--
* return back.
--
* return nth element.
--
* remove a node **next to** a given node.
--
* remove nodes with given data (filtration).
--
* is empty?
--
* printAll.
--
* delete the whole list from the heap.

---
#### A: LL of Integers

--
##### Define Your New Types

--
```c++
struct IntegerNode
{
    int data;
    IntegerNode *next = nullptr;
};

struct IntegerLL
{
    IntegerNode *front;
};
```

---
##### Insertions

--
```c++
void insertBack( IntegerLL &list, int newElement )
{
    // Logic
}

void insertFront( IntegerLL &list, int newElement )
{
    // Logic
}
```

---
##### Access

--
```c++
int getFront( IntegerLL &list )
{
    // Logic
}

int getBack( IntegerLL &list )
{
    // Logic
}

int getNth( IntegerLL &list )
{
    // Logic
}
```

---
##### Removal

--
```c++
void removeBack( IntegerLL &list )
{
    // Logic
}

void removeFront( IntegerLL &list )
{
    // Logic
}

void removeNth( IntegerLL &list )
{
    // Logic
}

void removeNext( IntegerLL &list, IntegerNode* node )
{
    // Logic
}
```

---
##### Remove an Arbitrary Point

--
```c++
void removeNode( IntegerLL &list , IntegerNode *node )
{
    // Logic
}

void removeData( IntegerLL &list , int data )
{
    // Logic
}
```

---
##### Are you empty?

--
```c++
bool isEmpty( IntegerLL &list )
{
    // Logic
}
```

---
##### Display, clear

```c++
void printAll( IntegerLL &list )
{
    // Logic
}

void clear( IntegerLL &list )
{
    // Logic
    // Memory Management
}
```

---
#### B: LL of Characters

```c++
struct CharNode
{
    char data;
    CharNode *next = nullptr;
};

struct CharLL
{
    CharNode *front = nullptr;
};
```

---
#### Copy your logic

Copy-paste the same logic of the Integers Linked List, but change each:

--
* `int` to `char`,
* `IntegerLL` to `CharLL`, and
* `IntegerNode` to `CharNode`.


---
<img src="/gallery/dna_array.svg" style="width:80%">

<img src="/gallery/dna_ll.svg" style="width:80%">

---
### Stacks using LL

--
### Node type

```c++
struct CharNode
{
    char data;
    CharNode* next = nullptr;
};
```

--
### Stack-LL

```c++
struct CharStackLL
{
    CharNode *front = nullptr;
};
```

--
* And we need: push, pop, and front.


---
### Stack-LL: access front operation

```c++
char front( CharStackLL &stack )
{
    return stack.front->data;
}
```

---
### Stack-LL: Push-to-front operation

<iframe allowfullscreen src="http://www.algomation.com/embeddedplayer?embedded=true&algorithm=58a0caa54833c1040095d574" width="600" height="371" seamless="seamless" frameborder="0" style="border:1px solid lightgray" scrolling="no"></iframe>

---
### Stack-LL: Push-to-front operation

```c++
void push( CharStackLL &stack , char data )
{
    CharNode *newNode = new CharNode;

    newNode->data = data;
    newNode->next = stack.front;

    stack.front = newNode;
}
```

or, equivalently

```c++
void push( CharStackLL &stack , char data )
{
    CharNode *newNode = new CharNode{ data , stack.front };
    stack.front = newNode;
}
```

---
#### DRY solution: (optional):

```c++
void push( CharStackLL &stack , char data )
{
    // 1. Make a LL interface
    CharLL list{ stack.front };

    // 2. DRY
    lists::pushFront( list , data );

    // 3. Update Stack front
    stack.front = list.front;
}
```

---
### Pop operation

When popping an element from the front,

<iframe allowfullscreen src="http://www.algomation.com/embeddedplayer?embedded=true&algorithm=58a0d1144833c1040095d586" width="600" height="371" seamless="seamless" frameborder="0" style="border:1px solid lightgray" scrolling="no"></iframe>


---
```c++
void pop( CharStackLL &stack )
{
    if( stack.front )
    {
        // Save the pointer of the front, so we delete it later
        CharNode *oldFront = stack.front;

        // Update the front of the stack
        stack.front = stack.front->next;

        // Now delete the old pointer
        delete oldFront;
    }
    else
    {
        // If the stack is empty, make the program to terminate (crash)!
        // The user of this function should have checked if the stack is not empty.
        exit( 1 );
    }
}
```

---
or DRY solution,

```c++
void pop( CharStack &stack )
{
    // 1. Make a Linked List Interface.
    CharLL list{ stack.front };

    // 2. DRY
    lists::removeFront( list );

    // 3. Update the Stack front now.
    stack.front = list.front;
}
```

---
### Asking a Stack if it is Empty

```c++
bool isEmpty( CharacterStackLL &stack )
{
    if( stack.front == nullptr )
    {
        return true;
    }
    else
    {
        return false;
    }
}
```

--
Again, could be done that way:

```c++
bool isEmpty( CharacterStackLL &stack )
{
    return stack.front == nullptr;
}
```

---
### Home Demo

Open [{StackLL}](https://www.cs.usfca.edu/~galles/visualization/StackLL.html) and play with the stack to realize its behaviour. This demo shows a **Stack** implemented with **linked list**.

---
## LL-Based Queues

```c++
struct DoubleNode
{
    double data;
    DoubleNode *next;
};

struct DoublesQueueLL
{
    DoubleNode *front = nullptr;
    DoubleNode *back = nullptr;
};
```

---
### Asking if the LL is Empty

```c++
bool isEmpty( NumbersQueueLL queue )
{
    if( queue.back == nullptr )
    {
        return true;
    }
    else
    {
        return false;
    }
}
```

---
Or equivalently,

```c++
bool isEmpty( NumbersQueueLL queue )
{
    return queue.back == nullptr;
}
```


---
### Enqueuing a New Element

New elements can be added to the **back**.


```c++
void enqueue( NumbersQueueLL &queue , double newSample )
{
    if( isEmpty( queue ))
    {
        queue.back = new DoubleNode{ newSample , nullptr };
        queue.front = queue.back;
    }
    else
    {
        queue.back->next = new DoubleNode{ newSample , nullptr };
        queue.back = queue.back->next;
    }
}
```

.red[*The above snippet is updated at Thursday 22 March 2019.*]

---
### Dequeueing an Element

Left for the assignment.

---
## Free Functions vs. Methods

```c++
CharStackLL cstack;
```

--
#### Which is more elegant?

--
```c++
push( cstack , 'A' );
```

--
What if we can do

```c++
cstack.push('A');
```

--
* First version => free function.
* Second version => method.


---
#### Procedural Paradigm

--
```c++
struct CharStackLL
{
    CharNode *front = nullptr;
};

void push( CharStackLL &stack , char data )
{
    CharNode *newNode = new CharNode{ data , stack.front };
    stack.front = newNode;
}
```

---
#### Object Oriented Paradigm (OOP)

--
```c++
struct CharStackLL
{
    CharNode *front = nullptr;
    
    void push( char newElement )
    {
        CharNode *newNode = new CharNode{ data , this->front };
        this->front = newNode;
    }
};
```

--
* A method inside a `struct` has an access to a very special pointer called `this`.
* `this` pointer gives a method access to all the `struct` members.

---
## Const Correctness

When passing a *pointer* or *reference* that **should not be modified**. It is very recommended to add `const` qualifier, so you guarantee the function **won't modify its contents**.

```c++
struct IntegerNode
{
    int data;
    IntegerNode *next = nullptr;
};

struct IntegerLL
{
    IntegerNode *front;
};
```

---
```c++
void insertBack( IntegerLL &list, int data )
{
    // Logic
}
```

---
```c++
void insertFront( IntegerLL &list, int data )
{
    // Logic
}
```

---

```c++
int front( IntegerLL &list )
{
    list.front = nullptr; // !!!
    // Logic
}
```

--
```c++
int front( const IntegerLL &list )
{
    // Logic
}
```

---
```c++
int back( IntegerLL &list )
{
    // What if your frind missed up with the list!
    
    nuke( list );
    // Logic
}
```

--
```c++
int back( const IntegerLL &list )
{
    // Logic
}
```


---
```c++
void removeBack( IntegerLL &list )
{
    // Logic
}
```

```c++
void removeFront( IntegerLL &list )
{
    // Logic
}
```


---
```c++
void removeNode( IntegerLL &list , IntegerNode *node )
{
    // Logic
}
```

```c++
void removeData( IntegerLL &list , int data )
{
    // Logic
}
```


---
```c++
bool isEmpty( IntegerLL &list )
{
    // Logic
}
```

--

```c++
bool isEmpty( const IntegerLL &list )
{
    // Logic
}
```

---
```c++
void printAll( IntegerLL &list )
{
    // Logic
}
```

--
```c++
void printAll( const IntegerLL &list )
{
    // Logic
}
```

---
```c++
void clear( IntegerLL &list )
{
    // Logic
}
```

</textarea>
