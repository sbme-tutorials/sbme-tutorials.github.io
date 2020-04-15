#include <iostream>
#include <random>
#include "DLL1.hpp"

void removeDuplicates( DLL &l )
{
    for( auto p1 = l.front; p1 != nullptr; p1 = p1->next )
    {
        for( auto p2 = p1->next ; p2 != nullptr;  )
        {
            if( p1->data == p2->data )
            {
                auto temp = p2;
                p2 = p2->next;
                popNode( l , temp );
            }
            else p2 = p2->next;
        }
    }
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
