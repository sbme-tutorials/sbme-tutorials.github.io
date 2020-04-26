---
layout: page
course: "sbe201"
category: "notes"
year: "2020"
title:  "Week 6 - Part B: Abstract Data Types (Stack & Queue)"
by: "Asem"
---

* TOC
{:toc}

## Stack

- In fact, **Stack** is an abstract data type, which doesn't define the underlying structure itself. 
- **Stack** only defines a set supported operations that we can we implement by different concrete data structures (such as arrays or linked lists).

For either implementations, the following requirements should be satisfied in order to hava an ADT **Stack** (from [wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))):

| Essential Operations |
|---|
| **push**: which adds an element to the collection |
| **pop**: which removes the most recently added element that was not yet removed |

| Non-Essential Operations |
|--|
| **front**: which returns the most recent element added to the stack that was not yet removed, without removing it from the stack. |
| **empty**: returns whether the stack is empty, sometimes needed to check to avoid popping from empty stack. |


*The order in which elements come off a stack gives rise to its alternative name, **LIFO** (last in, first out). Additionally, a **peek** operation may give access to the top without modifying the stack.* -- [Stack (Abstract Data Type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)).


<img src="/gallery/Lifo_stack.png" style="width:400">

### Stack Demo

Realize the behaviour of the stack from this demo: [StackArray](https://www.cs.usfca.edu/~galles/visualization/StackArray.html).

### Stack Applications

* Algorithms: stacks play an essential role in many algorithms.
* Stacks are used to store the function calls, so your execution can return to the last caller function after returning from the current function. See [this demo](http://www.pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%0Astruct%20node%0A%7B%0A%20%20int%20data%3B%0A%20%20node%20*next%3B%0A%7D%3B%0A%0Anode%20*pushFront%28%20node%20*front,%20int%20data%20%29%0A%7B%0A%20%20%20%20return%20new%20node%7B%20data%20,%20front%20%7D%3B%0A%7D%0A%0Aint%20list_size%28%20node%20*front%20%29%0A%7B%0A%20%20if%28%20front%20%3D%3D%20nullptr%20%29%20return%200%3B%0A%20%20else%20return%201%20%2B%20list_size%28%20front-%3Enext%20%29%3B%0A%7D%0A%0Anode*%20make_some_list%28%29%0A%7B%0A%20%20node%20*front%20%3D%20nullptr%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%202%20%29%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%203%20%29%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%205%20%29%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%207%20%29%3B%0A%20%20return%20front%3B%0A%7D%0A%0A%0Avoid%20fun1%28node*%20front%29%0A%7B%0A%20%20if%28front%20%3D%3D%20nullptr%29%20return%3B%0A%20%20%0A%20%20fun1%28front-%3Enext%29%3B%0A%20%20std%3A%3Acout%20%3C%3C%20front-%3Edata%20%3C%3C%20%22%20%22%3B%0A%7D%0A%0Avoid%20fun2%28node*%20front%29%0A%7B%0A%20%20if%28front%20%3D%3D%20nullptr%29%20return%3B%0A%20%20%0A%20%20std%3A%3Acout%20%3C%3C%20front-%3Edata%20%3C%3C%20%22%20%22%3B%0A%20%20fun2%28front-%3Enext%29%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20auto%20list%20%3D%20make_some_list%28%29%3B%0A%20%20int%20size%20%3D%20list_size%28%20list%20%29%3B%0A%20%20std%3A%3Acout%20%3C%3C%20size%20%3C%3C%20%22%5Cn%22%3B%0A%20%0A%0A%20%20fun1%28%20list%20%29%3B%0A%20%20std%3A%3Acout%20%3C%3C%20%22%5Cn%22%3B%0A%20%20fun2%28%20list%20%29%3B%0A%20%0A%7D&cumulative=false&curInstr=90&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D&textReferences=false) the demonstrate the use of the **Call stack**.

### Providing a Stack implementation

```c++
template< typename T >
class Stack
{
public:
    bool isEmpty() const 
    { /** logic **/}
    T front() const 
    { /** logic **/}
    void pop() 
    { /** logic **/}
    void push( T value )
    { /** logic **/}
private:
// Implementation specifics go here.
};
```

<div class="alert alert-warning" markdown="1" role="alert">


### <i class="fas fa-info-circle"></i> Important: Private Implementation Details

Don't expose the implementation details outside the class, for example:

- The client code (where we use the stack objects like in the `main` function), should not access the underlying container, for either array based implementation or linked list implementation of the stack.
- The user cannot retrieve the size of the stack from the stack object.
- If the client really needs the size of the stack in the application, then a variable outside the class can be made to trace the size (so the user increment and decrement this variable folloing push and pop operations).

Reasons:

- To comply with the standard definition of the stack.
- To guarantee that the stack will not be abused outside the class, almost the same reason why we cover the electronic details from the user:

<img src="/2020/data-structures/media/interface.png" style=" margin-left: 100px;width:400px">


<hr>
<div class="small"><span>Image credits: <a class="alert-link" href="https://www.robotmissions.org/learn/operatorinterface/part11/">robotmissions.org</a></span></div>
</div>

### Stack Implamentation (using Array)

Stacks can be built upon a static array to store the elements of the stack. One issue is that static array size must be know for the compiler, not via runtime.

For example, the compiler needs to see the static array declared as following:

```c++
template< typename T >
class Stack
{
public:
    bool isEmpty() const  {}
    T front() const  {}
    void pop() {}
    void push( T value ) {}
private:
    T data[1000];  // Like this
};
```

Issues:

1. Magic numbers need to be avoided.
2. What if we need to change that constant value from a stack to another (**in the same program**)

To avoid using magic numbers, we may explore two ways:

One way to define constant values for the compiler is using the <br>`#define CONST_NAME CONST_VAL`:

```c++
#define MAX_SIZE 1000
template< typename T >
class Stack
{
public:
    bool isEmpty() const  {}
    T front() const  {}
    void pop() {}
    void push( T value ) {}
private:
    T data[MAX_SIZE]; 
};
```

Now this has solved one of the two issues, and in this program we cannot make two stacks with different capacities. Another issue that `#define` makes is that when any source file includes the header file of the stack will also brings this `MAX_SIZE` to be seen by the other source file, which might be irrelevant name or even worse if `#define MAX_SIZE` is used also in that source file.

The recommended way to solve this in C++, is to harness the templates power. Template can be used to express agnostic types or compile-time constants.

```c++
template< typename T , int MAX_SIZE>
class Stack
{
public:
    bool isEmpty() const  {}
    T front() const  {}
    void pop() {}
    void push( T value ) {}
private:
    T data[MAX_SIZE]; 
};
```

* Now the `MAX_SIZE` constant is only seen inside the `Stack` template class.
* Now you can make different stacks with different capacities:

```c++
Stack< int , 2000 > s1; // stack of integers with maximum capacity 2000
Stack< double, 500> s2; // stack of doubles with maximum capacity of 500
```

* We can make also the template use a default value for the `MAX_SIZE`

```c++
template< typename T , int MAX_SIZE = 1024>
class Stack
{
public:
    bool isEmpty() const  {}
    T front() const  {}
    void pop() {}
    void push( T value ) {}
private:
    T data[MAX_SIZE]; 
};
```

* Now the user can just specify the stack element type only, in which the default value is used, or omit the default value by providing one.

```c++
Stack< char > s1; // stack of chars with maximum capacity 1024
Stack< std::string, 500> s2; // stack of std::string with maximum capacity of 500
```


#### Final Implementation for Stack Array

<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fsection06_adt%2FStackArray.hpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>

### Stack Implamentation (using Singly-Linked List)

This time we will provide an implementation for the stack using linked list. But which is better? singly-linked list or doubly-linked list.
* Note that **stacks pushs and pops from the same side**, so if we need to implement stacks using a linked list:
  * **Option 1**: push and pop from the back side (both $$O(1)$$ for doubly-linked list, while $$O(n)$$ for the singly-linked list)
  * **Option 2**: push and pop from the front side (both $$O(1)$$ for both the doubly-linked list and the singly-linked list)
* So we would go for using singly-linked list since it is more space efficient, and can provid $$O(1)$$ time for the stack operations.
* C++ STL has an implementation for the singly-linked via `std::forward_list`.


#### Final Implementation for Stack SLL

<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fsection06_adt%2FStackSLL.hpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>


## Queue


**Queues** are another Abstract Data Type (ADT), that might be implemented using concrete structures like arrays and linked lists. We refer to **Queue** behaviour by **FIFO** (first in, first out).

The ADT **Queue** should satisfy the following requirements (from [wikipedia](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))):

| Essential Operations |
|----|
| **enqueue**: which adds an element to the collection end (back) |
| **dequeue**: which removes the first element added (front) that was not yet removed |

| Non-Essential Operations |
|--|
| **front**: which returns the earliest element added to the queue that was not yet removed. |
| **empty**: returns whether the queue is empty or not, to avoid dequeueing from empty queue. |

*This makes the queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed. Additionally, a **peek** operation may give access to the front element without dequeuing it.* -- [Queue (Abstract Data Type)](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))

<img src="/gallery/Data_Queue.svg" style="width:400">

### Queue Demo

Open [QueueArray](https://www.cs.usfca.edu/~galles/visualization/QueueArray.html) and play with the queue to realize its behaviour. That demo shows a **Queue** implemented with **circular arrays**.

### Queue Applications

* Algorithms: queues play an essential role in many algorithms.
* For network multiplayer games: queue buffers are used to receive the stream of events in the game, so they can be processed in the ordered they were received.
* Realtime signal processing: such as in biomedical signals, where **queues** as a data structure can be used to represent a time window (interval) of biological signal being recorded from the patient and accessed in the ordered they arrived to the queue.
* Queues are used in multithreaded applications to communicate between threads.


### Providing a Queue implementation

```c++
template< typename T >
class Queue
{
public:
    bool isEmpty() const;
    T front() const;
    void dequeue();
    void enqueue( T value );
};
```

### Queue Implementation (using circular Array)

<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fsection06_adt%2FQueueArray.hpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>

### Queue Implementation (using Doubly-linked list)

The same question, which is better? a singly-linked list or a doubly-linked list?

* Queues inserts (enqueues) and removes (dequeues) element from different sides.
* We either **push front and pop back** for the enqueue and dequeue or **push back and remove front** for the enqueue and dequeue.
* Singly-linked list can afford fast modification from one side only, so we go for doubly-linked list. 

<script src="https://emgithub.com/embed.js?target=https%3A%2F%2Fgithub.com%2Fsbme-tutorials%2Fsbme-tutorials.github.io%2Fblob%2Fmaster%2F2020%2Fdata-structures%2Fsnippets%2Fsection06%2Fsection06_adt%2FQueueDLL.hpp&style=github&showBorder=on&showLineNumbers=on&showFileMeta=on"></script>


## Download the source files

```
mkdir -p section06/part-b
cd section06/part-b
wget -i https://raw.githubusercontent.com/sbme-tutorials/sbme-tutorials.github.io/master/2020/data-structures/snippets/section06/section06_adt/download.txt
```


<!-- 
## Advanced: Intro to Build Systems

[An introduction to build systems by *Marwan Abdellah, Ph.D, Blue Brain Project, EPFL*](http://bme-ws.yolasite.com/resources/Software%20Build%20Systems.pdf)

To access the workshop pages and materials: [The Second Biomedical Engineering Workshop](http://bme-workshop.weebly.com/material.html).

In depth:

<iframe src="https://player.vimeo.com/video/32212195" width="640" height="360" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
<p><a href="https://vimeo.com/32212195">Introduction to CMake</a> from <a href="https://vimeo.com/kitware">Kitware</a> on <a href="https://vimeo.com">Vimeo</a>.</p> -->
