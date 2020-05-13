#include <iostream>
#include <random>
#include <cassert>
#include <vector>
#include <set>
#include "Set.hpp"

int main()
{

    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,100); // distribution
    Set< int > s;
    std::set< int > s2;
    for( int i = 0; i < 100 ; ++i)
    {
        auto x = udist(sampler);
        s.insert( x );
        s2.insert( x );
        assert( s.find( x ));
    }

    std::cout << "\nMy Set content:\n";
    s.forEach( []( int x ){
       std::cout << x << " ";
    });

    std::cout << "\nSTL Set content:\n";
    for( auto x : s2 )
        std::cout << x << " ";


    int sum = 0;
    s.forEach( [&]( int x ){
       sum += x;
    });

    std::cout << "\nSum:" << sum << "\n";
    return 0;
}
