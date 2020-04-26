#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include "QueueArray.hpp"

void selection_sort( std::list<int> &data )
{
    QueueArray< int , 1000 > q;
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

