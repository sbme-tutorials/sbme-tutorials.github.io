#include <iostream>
#include <random>
#include "DLL1.hpp"

void removeDuplicates( DLL &l )
{

}

int main()
{
    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,500); // distribution

    DLL l{nullptr};

    for( int i = 0; i < 500 ; ++i)
        pushBack( l , udist(sampler));


    std::cout << "size:" << size( l ) << "\n";
    print( l );

    removeDuplicates( l );
    std::cout << "====\nAfter duplicates removal:\n";
    std::cout << "size:" << size( l ) << "\n";
    print( l );
}
