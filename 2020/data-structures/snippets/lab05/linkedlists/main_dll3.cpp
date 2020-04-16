#include <iostream>
#include <random>
#include "DLL3.hpp"

void removeDuplicates( DLL &l )
{

}

int main()
{
    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,500); // distribution

    DLL l{nullptr};

    for( int i = 0; i < 500 ; ++i)
        l.pushBack( udist(sampler));


    std::cout << "size:" << l.size() << "\n";
    l.print();

    removeDuplicates( l );
    std::cout << "====\nAfter duplicates removal:\n";
    std::cout << "size:" << l.size() << "\n";
    l.print();
}
