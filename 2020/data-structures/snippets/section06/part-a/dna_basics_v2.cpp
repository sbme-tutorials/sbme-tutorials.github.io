#include <iostream>  // for std::cin, std::cout
#include <string>
#include <algorithm> // for std::count

class DNA
{
public:
    // Constructor
    DNA( std::string seq )
    {
        sequence = seq;
    }

    int count( char q ) const
    {
        return std::count( sequence.begin(), sequence.end(), q );
    }

    // Static method (called as DNA::fromStream)
    static DNA fromStream()
    {
        std::string line, seq;
        while (std::getline(std::cin, line))
            if (line.empty() || line.front() == '>')
                continue;
            else seq += line;
        // Construct and return an object of type 'DNA'
        // using the constructor at line #9
        return DNA(seq);
    }
private:
    std::string sequence;
};

int main()
{
    auto dna = DNA::fromStream();
    std::cout << "#A:" << dna.count('A') << "\n"
              << "#C:" << dna.count('C') << "\n"
              << "#G:" << dna.count('G') << "\n"
              << "#T:" << dna.count('T') << "\n";
    return 0;
}
