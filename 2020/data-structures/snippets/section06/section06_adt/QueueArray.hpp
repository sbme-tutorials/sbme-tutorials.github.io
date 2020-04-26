#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP
#include <iostream>

template< typename T , int MAX_SIZE = 1000 >
class QueueArray
{
public:
    QueueArray()
    {
        front_ = 0;
        rear_ = 0;
    }

    bool isEmpty() const
    {
        return front_ == rear_;
    }

    T front() const
    {
        if( isEmpty())
        {
            std::cout << "Error: queue is empty!\n";
            exit( 1 ); // Crash.
        }
        return data_[front_];
    }

    void dequeue()
    {
        if( isEmpty())
        {
            std::cout << "Error: queue is empty!\n";
            exit( 1 ); // Crash.
        }
        front_ = (front_ + 1) % MAX_SIZE;
    }

    void enqueue( T value )
    {
        if( isFull())
        {
            std::cout << "Error: queue is full!\n";
            exit( 1 ); // Crash.
        }
        data_[ rear_ ] = value;
        rear_ = (rear_+1) % MAX_SIZE;
    }

private:
    bool isFull() const
    {
        return (rear_ + 1) % MAX_SIZE == front_;
    }


    T data_[ MAX_SIZE ];
    int front_;
    int rear_;
};

#endif // QUEUEARRAY_HPP
