#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

struct Student
{
	std::string name;
	int grade;
	friend std::ostream &operator<<( std::ostream &output, const Student &v ) {
		output << "(" << v.name << "," << v.grade << ")";
		return output;
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

	std::mt19937 sampler; // random number sampler
	std::uniform_int_distribution<int> udist(0,100); // distribution
	std::vector< int > v;
	for( int i = 0; i < 10 ; ++i)
		v.push_back(udist(sampler));

	for( auto x: v ) std::cout << x << " ";
	std::cout << "\n";

	std::sort( v.begin(), v.end());

	for( auto x: v ) std::cout << x << " ";
	std::cout << "\n";

	v.clear();
	for( int i = 0; i < 10 ; ++i)
		v.push_back(udist(sampler));
	std::sort( v.begin(), v.end(), []( int a, int b){
		return a > b;
	});
	for( auto x: v ) std::cout << x << " ";
	std::cout << "\n";


	// Example 3.
	std::cout << "Example 3:\n";

	std::vector< Student > students;
	students.push_back({"Mahdy", 86});
	students.push_back({"Ahmed",  70});
	students.push_back({"Samar", 86});
	students.push_back({"Zyad",  70});

	std::sort( students.begin(), students.end(),
			   []( Student &a, Student &b ){
		return a.grade > b.grade;
	});

	for( auto stud : students ) std::cout << stud << " ";
	std::cout << "\n";

	std::sort( students.begin(), students.end(),
			   []( Student &a, Student &b ){
		return a.name < b.name;
	});

	for( auto stud : students ) std::cout << stud << " ";
	std::cout << "\n";
}

