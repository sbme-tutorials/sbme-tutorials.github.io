#include <iostream>

// argv[0] = {'.','/','c','a',...., '\0'} (char *)
// argv[1] = {'1', '\0'} (char *)
// argv[2] = {'+', '\0'}
// argv[3] = {'4', '\0'}

// argv = { ... , , , , }  (char **)
int main( int x, char **y )
{
    for( int i =0; i < x; ++i )
    {
        std::cout << y[i] << std::endl;
    }
    std::cout << std::endl;
}