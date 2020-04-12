#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector< double > v;
    // append elements with values 1^2 to 10^2
    for (int i=1; i<=10; ++i) {
        v.push_back(i*i);
    }

    // print all elements followed by a space
    for (int i=0; i< v.size(); ++i) {
        std::cout << v[i] << ' ';
    }

    // print all elements followed by a space
    for( auto x : v )
        std::cout << x << ' ';

    std::list< double > l;
    // append elements with values 1^2 to 10^2
    for (int i=1; i<=10; ++i) {
        l.push_back(i*i);
    }

    // print all elements followed by a space
    for (int i=0; i< l.size(); ++i) {
        // operator[] is undefined for list.
        // std::cout << l[i] << ' '; // Compiler error
    }

    // print all elements followed by a space
    for (int i=0; i< l.size(); ++i) {
        auto it = std::next( l.begin(), i );
        std::cout << *it << ' ';
    }

    // print all elements followed by a space
    for (auto it =l.begin(); it != l.end(); ++it) {
        std::cout << *it << ' ';
    }

    // print all elements followed by a space
    for (auto x : l) {
        std::cout << x << ' ';
    }
}
