#ifndef DLL3_HPP
#define DLL3_HPP

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

    bool isEmpty()
    {
        return front == nullptr;
    }

    void pushFront( int data )
    {
        auto newNode = new Node{ data , front , nullptr };
        if( front ) front->prev = newNode;
        front = newNode;
    }

    void pushBack( int data )
    {
        if( front == nullptr )
            pushFront( data );
        else
        {
            Node *temp = front;
            while( temp->next != nullptr )
                temp = temp->next;
            auto newNode = new Node{ data , nullptr , temp };
            temp->next = newNode;
        }
    }

    void popNode( Node *node )
    {
        if( front == node ) front = front->next;
        if( node->prev ) node->prev->next = node->next;
        if( node->next ) node->next->prev = node->prev;
        delete node;
    }

    void popFront( )
    {
        popNode( front );
    }

    void popBack()
    {
        if( isEmpty( ))
            return;
        else if( front->next == nullptr )
            popFront();
        else
        {
            Node *temp = front;
            while( temp->next != nullptr )
                temp = temp->next;
            temp->prev->next = nullptr;
            delete temp;
        }
    }

    int getAt( int index ){}

    void clear( ){}

    void print()
    {
        for( auto p = front; p != nullptr ; p = p->next )
        {
            std::cout << p->data << "->";
        }
        std::cout << "null\n";
    }

    int size()
    {
        int counter = 0;
        auto temp = front;
        while( temp != nullptr )
        {
            ++counter;
            temp = temp->next;
        }
        return counter;
    }
};



#endif // DLL3_HPP
