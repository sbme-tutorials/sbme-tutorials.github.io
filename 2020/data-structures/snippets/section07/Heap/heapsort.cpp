#include <iostream>
#include <random>
#include <cassert>
#include <algorithm>
#include "Heap.hpp"

std::vector< int > heapSort( std::vector< int > a )
{
    auto h = Heap<int>::make( a );
    a.clear();
    while( h.size() > 0 )
        a.push_back( h.extract());
    return a;
}

int main()
{

    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,1000); // distribution
    std::vector< int > v;
    for( int i = 0; i < 800 ; ++i)
    {
        auto x = udist(sampler);
        v.push_back( x );
    }

    for( auto x : v ) std::cout << x << " ";
    std::cout << "(end)\n";

    auto sorted = heapSort( v );

    for( auto x : v ) std::cout << x << " ";
    std::cout << "(end)\n";
    return 0;
}
