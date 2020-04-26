#ifndef QUEUEDLL_HPP
#define QUEUEDLL_HPP
#include <iostream>
#include <list>

template< typename T >
class QueueDLL
{
public:
    bool isEmpty() const
    {
        return data_.empty();
    }

    T front() const
    {
        if( data_.empty())
        {
            std::cout << "Error: queue is empty!\n";
            exit( 1 ); // Crash.
        }
        return data_.front();
    }

    void dequeue()
    {
        if( isEmpty())
        {
            std::cout << "Error: queue is empty!\n";
            exit( 1 ); // Crash.
        }
        data_.pop_front();
    }

    void enqueue( T value )
    {
        data_.push_back( value );
    }

private:
    std::list< T > data_;
};

#endif // QUEUEDLL_HPP
