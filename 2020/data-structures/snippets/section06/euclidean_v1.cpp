#include <iostream>
#include <cmath>

double distance( double x1, double y1, double x2, double y2 )
{
    // Self practicing: try to implement this yourself
    double xp2 = (x1 - x2) * (x1 - x2);
    double yp2 = (y1 - y2) * (y1 - y2);
    return std::sqrt( xp2 + yp2 );
}

int main()
{
    double px = 0;
    double py = 0;
    double qx = 0;
    double qy = 0;

    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> px >> py >> qx >> qy;
    std::cout << distance( px , py, qx , qy) << "\n";
}
