#include <iostream>
#include <cmath>


template< typename T >
struct Point
{
    // Function members (methods)
    double distance( Point other )
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt( dx * dx + dy * dy );
    }
    // Default constructor.
    Point()
    {
        x = 0;
        y = 0;
    }

    // Data memebers
    T x;
    T y;
};

int main()
{
    Point<double> p, q; //all members initialized to zero.
    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> p.x >> p.y >> q.x >> q.y;
    std::cout << p.distance( q ) << "\n";

    // Note that: p.distance( q ) == q.distance( p )
}
