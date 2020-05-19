#include <iostream>
#include <random>
#include <cassert>
#include <string>
#include <map>
#include "Map.hpp"

std::string readStream()
{
    std::string line, seq;
    while (std::getline(std::cin, line))
        if (line.empty() || line.front() == '>')
            continue;
        else seq += line;
    return seq;
}

int main()
{
    Map< char , int > counter;
    std::map< char , int > counter2;
    auto dna = readStream();
    for( auto b : dna )
        counter[b]++;

    for( auto b : dna )
        counter2[b]++;

    std::cout << "\nMy Map content:\n";
	counter.forEach( []( char key, int val ){
		std::cout << key << ":" << val << "\n";
    });

	int sum = 0;
	counter.forEach( [&]( char base, int count ){
		sum += count;
	});

    std::cout << "\nSTL Map content:\n";
    for( auto [base,count] : counter2 )
        std::cout << base << ":" << count << "\n";


    return 0;
}
