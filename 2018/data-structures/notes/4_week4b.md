---
layout: page
course: "sbe201"
category: "notes"
year: "2018"
title:  "Week 4 - Part2: More on Structs, Linked Lists, Naming Conventions, Const-correctness, Build Systems, and Git for Teams"
by: "Asem"
---

* TOC
{:toc}

## Stacks using Linked Lists

<img src="/gallery/dna_array.svg" style="width:400">

<img src="/gallery/dna_ll.svg" style="width:400">

### Node type

```c++
struct Node
{
    char data;
    Node* next;
};
```

TODO: add a figure for each operation

### Stack-LL

In case of LL-based stack, we can represent a stack using only **a single pointer**, i.e the front of the stack.


```c++
struct CharacterStackLL
{
    Node *front = nullptr;
};
```

Initially, when stack is empty, the front pointer points to nothing, i.e `nullptr`.


### Push operation

When we push a new element, we add that element to the front. We make sure that we link the new node correctly.

```c++
void push( CharacterStackLL &stack , char data )
{
    Node *newNode = new Node;

    newNode->data = data;
    newNode->next = stack.front;

    stack.front = newNode;
}
```

or, equivalently

```c++
void push( CharacterStackLL &stack , char data )
{
    Node *newNode = new Node{ data , stack.front };
    stack.front = newNode;
}
```


### Pop operation

When popping an element from the front,



TODO: decompose into 6 steps in the presentation.

```c++
char pop( CharacterStackLL &stack )
{
    if( stack.front )
    {
        // Save the value of the front->data, before we delete it from the stack
        char lifo = stack.front->data;
        
        // Save the pointer of the front, so we delete it later
        Node *oldFront = stack.front;

        // Update the front of the stack
        stack.front = stack.front->front;

        // Now delete the old pointer
        delete oldFront;

        // Return the lifo
        return lifo;
    }
    else
    {
        // If the stack is empty, make the program to terminate (crash)!
        // The user of this function should have checked if the stack is not empty.
        exit( 1 );
    }
}
```

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

Again, could be done that way:

```c++
bool isEmpty( CharacterStackLL &stack )
{
    return stack.front == nullptr;
}
```

### Home Demo

Open [StackLL](https://www.cs.usfca.edu/~galles/visualization/StackLL.html) and play with the stack to realize its behaviour. This demo shows a **Stack** implemented with **linked list**.

## LL-Based Queues


The same node `struct`.

```c++
struct NumberNode
{
    double data;
    NumberNode *next;    
};
```

And the whole **Queue** is represented by two elements: **Front** (or **Head**) and **Back** (or **Rear**). We can wrap these element in the following `struct`:

```c++
struct NumbersQueueLL
{
    NumberNode *front = nullptr;
    NumberNode *back = nullptr;
};
```

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

Or equivalently,

```c++
bool isEmpty( NumbersQueueLL queue )
{
    return queue.back == nullptr;
}
```

### Enqueuing a New Element

As you guessed, new elements will be added to the **back**.

```c++
void enqueue( NumbersQueueLL &queue , double newSample )
{
    if( isEmpty( queue ))
    {
        queue.back = new NumberNode{ newSample , nullptr };
        queue.front = queue.back;
    }
    else
    {
        NumbersNode *oldBack = queue.back;
        NumbersNode *newBack = new NumbersNode{ newSample , oldBack };
        queue.back = newBack;

        // Short solution: queue.back = new NumbersNode{ newSample , queue.back };
    }
}
```

### Dequeueing an Element

Left for the assignment.


## Methods

## This Pointer

## Preprocessing

### Library Includes

### Circular Dependencies

### Defines

### Functions as Defines

## Naming Conventions

## Const Correctness

## Intro to Build Systems

## Git for Teams


https://upbeat-pie.surge.sh/

https://www.coursera.org/learn/data-structures


https://www.coursera.org/learn/algorithms-part1


https://github.com/no-stack-dub-sack/algos-and-data-structures

https://www.codewars.com/?language=cpp

http://www.pythontutor.com/