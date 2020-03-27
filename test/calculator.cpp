#include <iostream>
#include <cstdlib>
// argv[0] = {'.','/','c','a',...., '\0'}
// argv[1] = {'1', '\0'}
// argv[2] = {'+', '\0'}
// argv[3] = {'4', '\0'}
double calculcator( double a , double b, char op )
{
    if( op == '+') return a+b;
    else return a-b;
}
int main( int argc , char **argv )
{
    double a = std::atof(argv[1]);
    double b = std::atof(argv[3]);
    char op = argv[2][0];
    std::cout << calculcator(a,b,op);
}