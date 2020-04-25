#include <iostream>
#include <string>

template< typename T , int MAX_SIZE = 1000 >
class Stack
{
public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top + 1 == MAX_SIZE;
    }

    T front() const
    {
        if( isEmpty())
        {
            std::cout << "Error: stack is empty!\n";
            exit( 1 ); // Crash.
        }
        return data[top];
    }

    void pop()
    {
        if( isEmpty())
        {
            std::cout << "Error: stack is empty!\n";
            exit( 1 ); // Crash.
        }
        --top;
    }

    void push( T value )
    {
        if( isFull())
        {
            std::cout << "Error: stack is full!\n";
            exit( 1 ); // Crash.
        }
        data[ ++top ] = value;
    }

private:
    T data[ MAX_SIZE ];
    int top;
};


std::string getDNAFromStream()
{
    std::string line, dna;
    while (std::getline(std::cin, line))
        if (line.empty() || line.front() == '>')
            continue;
        else dna += line;
    return dna;
}

char cBase( char base )
{
    switch(base)
    {
    case 'A': return 'T';
    case 'C': return 'G';
    case 'G': return 'C';
    default: return 'A';
    }
}

std::string cDNA1( const std::string &dna )
{
    std::string cdna = dna;
    for( int i = 0; i < dna.size(); ++i )
        cdna[ i ] = cBase(  dna[ dna.size() - 1 - i ]);
    return cdna;
}

std::string cDNA2( const std::string &dna )
{
    Stack<char, 10000> cdna_stack;
    for( auto base : dna )
        cdna_stack.push( cBase( base ));
    std::string cdna;
    while( !cdna_stack.isEmpty())
    {
        cdna.push_back( cdna_stack.front());
        cdna_stack.pop();
    }
    return cdna;
}

std::string cDNA3( const std::string &dna )
{
    std::string cdna;
    for( auto rit = dna.rbegin(); rit != dna.rend(); ++rit )
        cdna.push_back( cBase( *rit ));
    return cdna;
}

int main()
{
    auto dna = getDNAFromStream();
    auto cdna1 = cDNA1(dna);
    auto cdna2 = cDNA2(dna);
    auto cdna3 = cDNA3(dna);
    if( cdna1 != cdna2 || cdna2 != cdna3 )
    {
        std::cout << "Logical error in finding the complementary sequence!\n";
        exit( 1 );
    }
    else
    {
        std::cout << cdna1 << std::endl;
    }
}

