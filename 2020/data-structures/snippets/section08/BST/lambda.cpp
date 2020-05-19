#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>

struct Student
{
	std::string name;
	int grade;
	std::string toString() const {
		std::stringstream s;
		s << "(" << name << "," << grade << ")";
		return s.str();
	}
};



int main()
{
	// Example 1.
	std::cout << "Example 1:\n";
	auto sq = [](double a){ return a*a; };

	std::vector< double > u = { 1.0, -2.0, 3.0, -4.0 };
	for( auto &x : u )
		x = sq( x );

	for( auto x: u ) std::cout << x << " ";
	std::cout << "\n";


	// Example 2.
	std::cout << "Example 2:\n";
	// random number sampler
	std::mt19937 sampler;
	// distribution
	std::uniform_int_distribution<int> udist(0,100);
	std::vector< int > v;
	for( int i = 0; i < 10 ; ++i)
		v.push_back(udist(sampler));

	for( auto x: v ) std::cout << x << " ";
	std::cout << "\n";

	std::sort( v.begin(), v.end());

	for( auto x: v ) std::cout << x << " ";
	std::cout << "\n";

	std::sort( v.begin(), v.end(), []( int a, int b){
		return a > b;
	});
	for( auto x: v ) std::cout << x << " ";
	std::cout << "\n";


	// Example 3.
	std::cout << "Example 3:\n";

	std::vector< Student > students({ {"Mahdy", 86},
									  {"Ahmed", 70},
									  {"Samar", 86},
									  {"Zyad",  70}});

	std::sort( students.begin(), students.end(),
			   []( Student &a, Student &b ){
		return a.grade > b.grade;
	});

	for( auto &stud : students )
		std::cout << stud.toString() << " ";
	std::cout << "\n";

	std::sort( students.begin(), students.end(),
			   []( Student &a, Student &b ){
		return a.name < b.name;
	});

	for( auto &stud : students )
		std::cout << stud.toString() << " ";
	std::cout << "\n";
}

