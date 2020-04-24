#include <iostream>  // for std::cin, std::cout
#include <string>
#include <algorithm> // for std::count

std::string getDNAFromStream()
{
    std::string line, dna;
    while (std::getline(std::cin, line))
        if (line.empty() || line.front() == '>')
            continue;
        else dna += line;
    return dna;
}

// This works
int count1( const std::string &sequence , char q )
{
    int counter = 0;
    for( size_t i = 0; i < sequence.size(); ++i )
        if( sequence[i] == q )
            ++counter;
    return counter;
}

// This works
int count2( const std::string &sequence , char q )
{
    int counter = 0;
    for( auto it = sequence.begin(); it != sequence.end(); ++it )
        if( *it == q )
            ++counter;
    return counter;
}

// This works
int count3( const std::string &sequence , char q )
{
    int counter = 0;
    for( auto c : sequence )
        if( c == q )
            ++counter;
    return counter;
}

// Or..
int count4( const std::string &sequence , char q )
{
    return std::count( sequence.cbegin(), sequence.cend(), q );
}

int main()
{
    auto dna = getDNAFromStream();
    std::cout << "#A:" << count3(dna, 'A') << "\n"
              << "#C:" << count3(dna, 'C') << "\n"
              << "#G:" << count3(dna, 'G') << "\n"
              << "#T:" << count3(dna, 'T') << "\n";
    return 0;
}
