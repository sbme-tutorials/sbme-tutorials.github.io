#include <iostream>
#include <list>
#include <algorithm>
#include <random>

template< typename T , int MAX_SIZE = 1000 >
class Queue
{
public:
    Queue()
    {
        front_ = 0;
        rear_ = 0;
    }

    bool isEmpty() const
    {
        return front_ == rear_;
    }

    bool isFull() const
    {
        return (rear_ + 1) % MAX_SIZE == front_;
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
    T data_[ MAX_SIZE ];
    int front_;
    int rear_;
};


void selection_sort( std::list<int> &data )
{
    Queue< int , 1000 > q;
    while( !data.empty())
    {
       auto min_it = std::min_element( data.begin(), data.end());
       q.enqueue( *min_it );
       data.erase( min_it );
    }
    while( !q.isEmpty())
    {
        data.push_back( q.front());
        q.dequeue();
    }
}

int main()
{
    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,500); // distribution
    std::list<int> data;
    for( int i = 0; i < 500 ; ++i)
        data.push_back(udist(sampler));
    for( auto x : data )
        std::cout << x << "->";
    std::cout << "end\n";

    selection_sort( data );

    if( std::is_sorted( data.begin(), data.end()))
    {
        for( auto x : data )
            std::cout << x << "->";
        std::cout << "end\n";
    }
    else
    {
        std::cout << "Sorting failure!\n";
        exit( 1 );
    }
}

