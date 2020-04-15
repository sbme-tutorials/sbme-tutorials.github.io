#include <iostream>
#include <vector>
#include <list>

#include "tabulate/table.hpp"

struct CovidItem
{
    std::string country;
    int confirmed;
    int deaths;
    int recovered;
    int active;
};

// split("Cuba,669,18,92,559", ',') => { "Cuba", "669", "18", "92", "559" }
std::vector< std::string >  split( const std::string &s , char delim )
{
    // Inspired by: https://stackoverflow.com/a/35639462/5565296
    std::vector<std::string> tokens;
    auto start=s.cbegin(); // prepare to parse the line - start is position of begin of field
    bool instring = false;
    for (auto it = start; it != s.cend(); ++it) {  // iterate through the string
        if (*it=='"')  // toggle flag if we're btw double quote
            instring = !instring;
        else if (*it==delim && !instring) {    // if comma OUTSIDE double quote
            tokens.emplace_back(start,it);  // keep the field
            start=it+1; // and start parsing next one
        }
    }
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
        newItem.country = columns[3];
        newItem.confirmed = std::stoi( columns[7] );
        newItem.deaths = std::stoi( columns[8]);
        newItem.recovered = std::stoi( columns[9]);
        newItem.active = std::stoi( columns[10]);
        data.push_back( newItem );
    }
    return data;
}

void mergeByCountry( std::list<CovidItem> &items )
{

    for( auto it1 = items.begin(); it1 != items.end(); it1 = std::next( it1 ))
    {
        auto it2 = std::next( it1 );
        while( it2 != items.end() )
        {
            if( it1->country == it2->country )
            {
                it1->active += it2->active;
                it1->confirmed += it2->confirmed;
                it1->deaths += it2->deaths;
                it1->recovered += it2->recovered;
                it2 = items.erase( it2 );  // O(1)
            }
            else it2 = std::next( it2 );
        }
    }
}

void fancyPrint( std::list<CovidItem> &list );

int main()
{
    std::list<CovidItem> facts = getCovidFacts();
    mergeByCountry( facts );
    fancyPrint( facts );
}

void fancyPrint( std::list<CovidItem> &list )
{
    using tabulate::Table;
    using tabulate::FontStyle;
    using tabulate::FontAlign;
    using tabulate::Color;
    tabulate::Table covidfacts;
    covidfacts.add_row({"Country", "Confirmed", "Deaths", "Recovered", "Active"});
    for( auto item : list )
    {
        covidfacts.add_row( {item.country, std::to_string(item.confirmed),
                             std::to_string(item.deaths), std::to_string(item.recovered),
                             std::to_string(item.active) });
    }

    covidfacts.format().font_style({FontStyle::bold}).font_align(FontAlign::center);
    covidfacts.row(0).format().font_color(Color::white).font_style({FontStyle::underline});
    covidfacts[0][1].format().font_background_color(Color::yellow);
    covidfacts[0][2].format().font_background_color(Color::red);
    covidfacts[0][3].format().font_background_color(Color::green);
    covidfacts[0][4].format().font_background_color(Color::yellow);

    const auto nrows = list.size() + 1;
    for( size_t i = 1; i < nrows; ++i )
    {
        covidfacts[i][1].format().font_color(Color::yellow);
        covidfacts[i][2].format().font_color(Color::red);
        covidfacts[i][3].format().font_color(Color::green);
        covidfacts[i][4].format().font_color(Color::yellow);
    }

    std::cout << covidfacts << std::endl;
}
