#include <iostream>
#include <random>
#include <cassert>
#include <vector>
#include "BST.hpp"

int main()
{

    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,100); // distribution
    BST< int > t;
    for( int i = 0; i < 36 ; ++i)
    {
        auto x = udist(sampler);
        t.insert( x );
        assert( t.size() == i + 1 );
        assert( t.isBST());
        assert( t.find( x ));
    }

    std :: cout << "\nInorder:\n";
    t.inorder();
    std::cout << "\nPostoder:\n";
    t.postorder();
    std::cout << "\nBreadth First:\n";
    t.breadthfirst();
    std::cout << "\nPreorder:\n";
    t.preorder();


    std::vector< int > toRemove;
    for( int i = 0; i < 36 ; ++i)
    {
        auto x = udist(sampler);
        t.insert( x );
        toRemove.push_back( x );
        assert( t.isBST());
    }

    for( auto x : toRemove )
    {
        std::cout << "\nRemoving " << x << "...\n";
        t.remove( x );
        assert( t.isBST());
        t.inorder();
    }

    assert( t.size() == 36 );

    return 0;
}
