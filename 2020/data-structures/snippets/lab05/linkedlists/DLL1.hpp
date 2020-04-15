#ifndef DLL1_HPP
#define DLL1_HPP
#include <iostream>

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

bool isEmpty( DLL &list )
{
    return list.front == nullptr;
}

void pushFront( DLL &list, int data )
{
    auto newNode = new Node{ data , list.front , nullptr };
    if( list.front ) list.front->prev = newNode;
    list.front = newNode;
}

void pushBack( DLL &list, int data )
{
    if( list.front == nullptr )
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

void popNode( DLL &list, Node *node )
{
    if( list.front == node ) list.front = list.front->next;
    if( node->prev ) node->prev->next = node->next;
    if( node->next ) node->next->prev = node->prev;
    delete node;
}

void popFront( DLL &list )
{
    popNode( list , list.front );
}

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

int getAt( DLL &list, int index ){}

void clear( DLL &list ){}

void print( DLL &l )
{
    for( auto p = l.front; p != nullptr ; p = p->next )
    {
        std::cout << p->data << "->";
    }
    std::cout << "null\n";
}

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

#endif // DLL1_HPP
