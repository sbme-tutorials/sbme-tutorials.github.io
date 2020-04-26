#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP
#include <iostream>

template< typename T , int MAX_SIZE = 1000 >
class StackArray
{
public:
    StackArray()
    {
        top = -1;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    T front() const
    {
        if( isEmpty())
        {
            std::cout << "Error: stack is empty!\n";
            exit( 1 ); // Crash.
        }
        return data[top];
    }

    void pop()
    {
        if( isEmpty())
        {
            std::cout << "Error: stack is empty!\n";
            exit( 1 ); // Crash.
        }
        --top;
    }

    void push( T value )
    {
        if( isFull())
        {
            std::cout << "Error: stack is full!\n";
            exit( 1 ); // Crash.
        }
        data[ ++top ] = value;
    }

private:
    bool isFull() const
    {
        return top + 1 == MAX_SIZE;
    }

    T data[ MAX_SIZE ];
    int top;
};

#endif // STACKARRAY_HPP
