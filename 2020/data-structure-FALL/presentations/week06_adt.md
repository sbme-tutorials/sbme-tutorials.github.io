---
layout: presentation
style: laminal
highlighter: ir-black
code: "SBE201"
course: "SBE201 Data Structures and Algorithms"
category: "presentation"
semester: "Spring"
year: "2020"
title: "Section 6: Abstract Data Types (Stack and Queue)"
by: "Asem Alaa"
author: "Asem Alaa"
---

<textarea id="source" markdown="1">

# Section 6

## Abstract Data Types: Stacks and Queues

##### Presentation by *{{ page.author }}*

{% include presentation-margins.html %}

---
## Stack

<img src="/gallery/Lifo_stack.png" style="width:400px">

- Abstract data type 
- **LIFO** (last in, first out)
- Defines a set of supported operations
- Many implementation options (e.g Array or Linked List)

???
**Stack** is an abstract data type which doesn't define the underlying structure itself. **Stack** only defines a set supported operations that we can we implement by different concrete data structures (such as arrays or linked lists). For either implementations, the following requirements should be satisfied in order to hava an ADT **Stack** (from [wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)))

---
## Stack

##### Essential Operations

- **push**
- **pop**

##### Non-Essential Operations

- **front**
- **empty**


???
- **push**: which adds an element to the collection 
- **pop**: which removes the most recently added element that was not yet removed 
- **front**: which returns the most recent element added to the stack that was not yet removed, without removing it from the stack.
- **empty**: returns whether the stack is empty, sometimes needed to check to avoid popping from empty stack.
---
### Stack Demo

[{StackArray}](https://www.cs.usfca.edu/~galles/visualization/StackArray.html)


### Stack Applications


* Algorithms
* Call stack (stack frame). See [{demo}](http://www.pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%0Astruct%20node%0A%7B%0A%20%20int%20data%3B%0A%20%20node%20*next%3B%0A%7D%3B%0A%0Anode%20*pushFront%28%20node%20*front,%20int%20data%20%29%0A%7B%0A%20%20%20%20return%20new%20node%7B%20data%20,%20front%20%7D%3B%0A%7D%0A%0Aint%20list_size%28%20node%20*front%20%29%0A%7B%0A%20%20if%28%20front%20%3D%3D%20nullptr%20%29%20return%200%3B%0A%20%20else%20return%201%20%2B%20list_size%28%20front-%3Enext%20%29%3B%0A%7D%0A%0Anode*%20make_some_list%28%29%0A%7B%0A%20%20node%20*front%20%3D%20nullptr%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%202%20%29%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%203%20%29%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%205%20%29%3B%0A%20%20front%20%3D%20pushFront%28%20front%20,%207%20%29%3B%0A%20%20return%20front%3B%0A%7D%0A%0A%0Avoid%20fun1%28node*%20front%29%0A%7B%0A%20%20if%28front%20%3D%3D%20nullptr%29%20return%3B%0A%20%20%0A%20%20fun1%28front-%3Enext%29%3B%0A%20%20std%3A%3Acout%20%3C%3C%20front-%3Edata%20%3C%3C%20%22%20%22%3B%0A%7D%0A%0Avoid%20fun2%28node*%20front%29%0A%7B%0A%20%20if%28front%20%3D%3D%20nullptr%29%20return%3B%0A%20%20%0A%20%20std%3A%3Acout%20%3C%3C%20front-%3Edata%20%3C%3C%20%22%20%22%3B%0A%20%20fun2%28front-%3Enext%29%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20auto%20list%20%3D%20make_some_list%28%29%3B%0A%20%20int%20size%20%3D%20list_size%28%20list%20%29%3B%0A%20%20std%3A%3Acout%20%3C%3C%20size%20%3C%3C%20%22%5Cn%22%3B%0A%20%0A%0A%20%20fun1%28%20list%20%29%3B%0A%20%20std%3A%3Acout%20%3C%3C%20%22%5Cn%22%3B%0A%20%20fun2%28%20list%20%29%3B%0A%20%0A%7D&cumulative=false&curInstr=90&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp&rawInputLstJSON=%5B%5D&textReferences=false).


### Providing a Stack implementation

```c++
template< typename T >
class Stack
{
public:
    bool isEmpty() const  { /** logic **/}
    T front() const  { /** logic **/}
    void pop()  { /** logic **/}
    void push( T value ) { /** logic **/}
private:
// Implementation specifics go here.
};
```

---
### Hide Implementation Details From Client


.center[<img src="/2020/data-structures/media/interface.png" style="width:600px">]

- To comply with the definition.
- To avoid client abusing the ADT.

<div class="my-footer"><span>Image credits: <a href="https://www.robotmissions.org/learn/operatorinterface/part11/">robotmissions.org</a></span></div>

---
### Stack Implamentation (using Array)

- Problem: static array size must be know for the compiler.

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
2. Cannot make stacks with different capacities (**in the same program**)

---
### Stack Implamentation (using Array)

#### Solution 1 (C style)

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

1. .green[Solved magic numbers]
2. .red[Still inflexible]
3. .red[+++Compiler variables in the global scope]

---
### Stack Implamentation (using Array)

#### Solution 2 (C++ style)

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

* .green[`MAX_SIZE` constant is only seen inside the `Stack` template class.]
* .green[You can make different stacks with different capacities]

```c++
Stack< int , 2000 > s1; // stack of integers with maximum capacity 2000
Stack< double, 500> s2; // stack of doubles with maximum capacity of 500
```

---
### Stack Implamentation (using Array)

#### Solution 2 (C++ style) + Default Values

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

```c++
// stack of chars with maximum capacity 1024
Stack< char > s1; 
// stack of std::string with maximum capacity of 500
Stack< std::string, 500> s2; 
```

---
class: small
#### Final Implementation for Stack Array

```c++
template< typename T , int MAX_SIZE = 1000 >
class StackArray
{
public:
    bool isEmpty() const { return top == -1; }

    T front() const {
        if( isEmpty()) exit( 1 ); // Crash.
        return data[top];
    }

    void pop() {
        if( isEmpty()) exit( 1 ); // Crash.
        --top;
    }
    
    void push( T value ){
        if( isFull()) exit( 1 ); // Crash.
        data[ ++top ] = value;
    }
private:
    bool isFull() const { return top + 1 == MAX_SIZE; }
    T data[ MAX_SIZE ];
    int top = -1;
};
```

---
### Stack Implamentation (using Singly-LL)


#### Singly-linked list vs. doubly-linked list

* Stack pushes and pops **from the same side**
* **Option 1**: push and pop from the back side.
  * .green[$O(1)$ for doubly-ll], .red[while $O(n)$ for singly-ll]
* **Option 2**: push and pop from the front side.
  *  .green[$O(1)$ for both doubly-ll & singly-ll.]
* Singly-ll is more space efficient.
* Can provid $O(1)$ time for the stack operations.
* C++ STL has singly-ll via `std::forward_list`.


???

* **stack pushes and pops from the same side**: so if we need to implement stacks using a linked list:
  * **Option 1**: push and pop from the back side (both $O(1)$ for doubly-linked list, while $O(n)$ for the singly-linked list)
  * **Option 2**: push and pop from the front side (both $O(1)$ for both the doubly-linked list and the singly-linked list)
* So we would go for using singly-linked list since it is more space efficient, and can provid $O(1)$ time for the stack operations.
* C++ STL has an implementation for the singly-linked via `std::forward_list`.
---
class: small
#### Final Implementation for Stack SLL

```c++
#include <forward_list>
template< typename T >
class StackSLL
{
public:
    bool isEmpty() const{
        return data.empty();
    }

    T front() const{
        if( isEmpty()) exit( 1 ); // Crash.
        return data.front();
    }

    void pop(){
        if( isEmpty()) exit( 1 ); // Crash.
        data.pop_front();
    }
    void push( T value ){
        data.push_front( value );
    }
private:
    std::forward_list< T > data;
};
```

---
## Queue

<img src="/gallery/Data_Queue.svg" style="width:400">

- Abstract Data Type (ADT), 
- Many implementations (e.g arrays and linked lists)
- **Queue** behaviour == **FIFO** (first in, first out).

---
## Queue

### Essential Operations 

- **enqueue**: which adds an element to the collection end (back)
- **dequeue**: which removes the first element added (front) that was not yet removed.

### Non-Essential Operations

- **front**: which returns the earliest element added to the queue that was not yet removed.
- **empty**: returns whether the queue is empty or not, to avoid dequeueing from empty queue.

---
## Queue

### Queue Demo

- [{QueueArray}](https://www.cs.usfca.edu/~galles/visualization/QueueArray.html): implementation by **circular arrays**.

### Queue Applications

* Algorithms
* For network multiplayer games
* Realtime signal processing
* Multithreaded/Parallel Processing applications.

---
## Queue

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

---
class: small
### Queue Implementation (using circular Array)

```c++
template< typename T , int MAX_SIZE = 1000 >
class QueueArray
{
public:
    bool isEmpty() const{ return front_ == rear_; }
    T front() const{
        if( isEmpty()) exit( 1 ); // Crash.
        return data_[front_];
    }
    void dequeue(){
        if( isEmpty()) exit( 1 ); // Crash.
        front_ = (front_ + 1) % MAX_SIZE;
    }
    void enqueue( T value ){
        if( isFull()) exit( 1 ); // Crash.
        data_[ rear_ ] = value;
        rear_ = (rear_+1) % MAX_SIZE;
    }
private:
    bool isFull() const{ return (rear_ + 1) % MAX_SIZE == front_; }

    T data_[ MAX_SIZE ];
    int front_ = 0;
    int rear_ = 0;
};
```

---
## Queue


### Queue Implementation (using Doubly-LL)

#### singly-linked list vs. doubly-linked list

* Queues enqueues and dequeues element **from different sides**.
* We either:
  * **push front and pop back** for the enq. & deq.
  * **push back and remove front** for the enq. and deq.
* Only doubly-ll list can afford fast modification from both sides.

---
class: small
### Queue Implementation (using Doubly-LL)

```c++
#include <list>
template< typename T >
class QueueDLL
{
public:
    bool isEmpty() const {
        return data_.empty();
    }
    T front() const
    {
        if( data_.empty()) exit( 1 ); // Crash.
        return data_.front();
    }
    void dequeue()
    {
        if( isEmpty()) exit( 1 ); // Crash.
        data_.pop_front();
    }
    void enqueue( T value ){
        data_.push_back( value );
    }
private:
    std::list< T > data_;
};
```

---
class: center, middle
## Read the Notes

Read the notes for more details and to download the source files.

.small.blue[[{sbme-tutorials.github.io/2020/data-structures/notes/week06_adt.html}](https://sbme-tutorials.github.io/2020/data-structures/notes/week06_adt.html)]

---
# Thank you

{% include presentation-margins.html %}


</textarea>