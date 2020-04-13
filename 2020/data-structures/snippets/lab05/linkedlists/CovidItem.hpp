#ifndef COVIDITEM_HPP
#define COVIDITEM_HPP

#include <string>

struct CovidItem
{
    std::string country;
    int confirmed;
    int deaths;
    int recovered;
    int active;
};


#endif // COVIDITEM_HPP
