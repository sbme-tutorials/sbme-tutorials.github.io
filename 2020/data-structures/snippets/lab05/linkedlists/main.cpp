#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include "CovidItem.hpp"
#include "tabulate/table.hpp"

// split("Cuba,669,18,92,559", ',') => { "Cuba", "669", "18", "92", "559" }
std::vector< std::string >  split( const std::string &s , char delim )
{
    std::stringstream ss( s );
    std::vector< std::string > tokens;
    std::string token;
    while( std::getline( ss , token , delim ))
        tokens.push_back( token );
    return tokens;
}

std::vector< std::string > readInputStream()
{
    std::string line;
    std::vector< std::string > lines;
    while( std::getline( std::cin , line ))
        lines.push_back( line );
    return lines;
}

// Columns: FIPS,Admin2,Province_State,Country_Region,Last_Update,Lat,Long_,Confirmed,Deaths,Recovered,Active,Combined_Key
std::list<CovidItem> getCovidFacts()
{
    std::list<CovidItem> data;
    std::vector< std::string > lines = readInputStream();
    for( int i = 1; i < lines.size(); ++i )
    {
        CovidItem newItem;
        std::vector< std::string > columns = split(lines[i], ',');
        newItem.country = lines[3];
        newItem.confirmed = std::stoi( lines[7] );
        newItem.deaths = std::stoi( lines[8]);
        newItem.recovered = std::stoi( lines[9]);
        newItem.active = std::stoi( lines[10]);
        data.push_back( newItem );
    }
    return data;
}

int main()
{
    std::list<CovidItem> facts = getCovidFacts();


}
