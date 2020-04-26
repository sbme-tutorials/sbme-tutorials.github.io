#ifndef STACKSLL_HPP
#define STACKSLL_HPP
#include <iostream>
#include <forward_list>

template< typename T >
class StackSLL
{
public:
    bool isEmpty() const
    {
        return data.empty();
    }

    T front() const
    {
        if( isEmpty())
        {
            std::cout << "Error: stack is empty!\n";
            exit( 1 ); // Crash.
        }
        return data.front();
    }

    void pop()
    {
        if( isEmpty())
        {
            std::cout << "Error: stack is empty!\n";
            exit( 1 ); // Crash.
        }
        data.pop_front();
    }

    void push( T value )
    {
        data.push_front( value );
    }

private:
    std::forward_list< T > data;
};

#endif // STACKSLL_HPP
