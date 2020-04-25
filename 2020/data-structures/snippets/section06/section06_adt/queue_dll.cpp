#include <iostream>
#include <list>
#include <algorithm>
#include <random>

template< typename T >
class Queue
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


void selection_sort( std::list<int> &data )
{
    Queue< int > q;
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

