---
layout: presentation
style: laminal
highlighter: ir-black
code: "SBE201"
course: "SBE201 Data Structures and Algorithms"
category: "presentation"
semester: "Spring"
year: "2020"
title: "Lab 5: Doubly linked lists, classes, templates"
by: "Asem"
author: "Asem Alaa"
---

<textarea id="source" markdown="1">

# Lab 5

## Doubly linked lists, classes, templates

##### Presentation by *{{ page.author }}*

{% include presentation-margins.html %}

---
## Doubly linked list

<img src="Doubly-linked-list.svg">

```c++
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct DLL
{
    Node *front;
};

int main()
{
    DLL l{nullptr}; // l is empty linked list.
}
```

---
## Doubly linked list

### isEmpty?

```c++
bool isEmpty( DLL &list )
{
    return list.front == nullptr;
}
```

---
## Doubly linked list

### pushFront

```c++
void pushFront( DLL &list, int data )
{
    auto newNode = new Node{ data , list.front , nullptr };
    if( list.front ) list.front->prev = newNode;
    list.front = newNode;
}
```

---
## Doubly linked list

### pushBack

```c++
void pushBack( DLL &list, int data )
{
    if( isEmpty( list ))
        pushFront( list, data );
    else
    {
        Node *temp = list.front;
        while( temp->next != nullptr )
            temp = temp->next;
        auto newNode = new Node{ data , nullptr , temp };
        temp->next = newNode;
    }
}
```

---
## Doubly linked list

### pushBack

```c++
void pushBack( DLL &list, int data )
{
    if( isEmpty( list ))
        pushFront( list, data );
    else
    {
        Node *temp = list.front;
        while( temp->next != nullptr )
            temp = temp->next;
        auto newNode = new Node{ data , nullptr , temp };
        temp->next = newNode;
    }
}
```

---
## Doubly linked list

### popNode

```c++
void popNode( DLL &list, Node *node )
{
    if( list.front == node ) list.front = list.front->next;
    if( node->prev ) node->prev->next = node->next;
    if( node->next ) node->next->prev = node->prev;
    delete node;
}
```


---
## Doubly linked list

### popFront

```c++
void popFront( DLL &list )
{
    popNode( list , list.front );
}
```


---
## Doubly linked list

### popBack

```c++
void popBack( DLL &list )
{
    if( isEmpty( list ))
        return;
    else if( list.front->next == nullptr )
        popFront( list );
    else
    {
        Node *temp = list.front;
        while( temp->next != nullptr )
            temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }
}
```

---
## Doubly linked list

### print

```c++
void print( DLL &l )
{
    for( auto p = l.front; p != nullptr ; p = p->next )
    {
        std::cout << p->data << "->";
    }
    std::cout << "null\n";
}
```

---
## Doubly linked list

### size

```c++
int size( DLL &list )
{
    int counter = 0;
    auto temp = list.front;
    while( temp != nullptr )
    {
        ++counter;
        temp = temp->next;
    }
    return counter;
}
```

---
## Doubly linked list

### size

Or..

```c++
int size( DLL &list )
{
    int counter = 0;
    for( auto temp = list.front; temp != nullptr; temp = temp->next )
        ++counter;
    return counter;
}
```

---
## Doubly linked list

### size (recursive)

```c++
int size( Node *front )
{
    if( front == nullptr ) return 0;
    else return 1 + size( front->next );
}
```