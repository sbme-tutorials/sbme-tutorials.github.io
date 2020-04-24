---
layout: presentation
style: laminal
highlighter: github
course: "stl2019"
category: "presentation"
year: "2019"
title: "Introduction to OOP 1"
by: "Asem"
author: "Asem Alaa"
---

<textarea id="source">

---
class: left, middle
# Introduction to OOP by Examples 

1. **Example 1**: Euclidean distance between two points.
1. **Example 2**: DNA Analysis.

## For each example three versions

1. Free functions and sparse variables.
--
1. Free functions and bundled variables (struct for grouping data).
--
1. Bundled data with bundled functions (struct for grouping data and logic)

---
## Example: Euclidean Distance (V1)


Consider an application that computes the euclidean distance between two points as following:

$$\begin{equation}
 \bar{ || p_1p_2 ||}  = \sqrt{ (x_1-x_2)^2 + (y_1-y_2)^2 }  
\end{equation}
$$

---
### Example: Euclidean Distance
#### Biolerplate code

--
### Typical program source

```c++
#include <iostream> 

int main()
{

    return 0;
}
```

---
### Example: Euclidean Distance (V1)
#### Euclidean function

1. **Input**: 4 doubles (x1, y1, x2, y2)
--
1. **Output**: Euclidead distance (double)
--
1. **Name**: `euclideanDistance`

```c++
#include <iostream> 
#include <cmath> // We need this library to use the std::sqrt function

double euclideanDistance( double x1, double y1, double x2, double y2)
{
    // Self practicing: try to implement this yourself

}

int main()
{

    return 0;
}
```

---
### Example: Euclidean Distance (V1)
#### Input from user

--
Now we need to take the input from the user:

```c++
#include <iostream>
#include <cmath>

double euclideanDistance( double x1, double y1, double x2, double y2 )
{
    // Self practicing: try to implement this yourself
}

int main()
{
    double px = 0;
    double py = 0;
    double qx = 0;
    double qy = 0;

    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> px >> py >> qx >> qy;
    std::cout << euclideanDistance( px , py, qx , qy) << "\n";
}
```

---
### Example: Euclidean Distance (V1)
#### Compile and run:


--
```c++
g++ euclidean.cpp -o distance
./distance
Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]
```

Now the application waits us to enter the values of the coordinates. Let's try the following:

```
1.5 1 4.5 5
5
```

---
### Example: Euclidean Distance (V2)

--
#### Let's bundle x and y

--
```c++
struct Point
{
  double x;
  double y;
}
```

--
1. More concise
--
1. Mode descriptive

---
### Example: Euclidean Distance (V2)
#### Apply our logic on two Points

--
##### Old version
```c++
double euclideanDistance( double x1, double y1, double x2, double y2 )
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return std::sqrt( dx * dx + dy * dy );
}
```

--
##### Second version
```c++
double euclideanDistance( Point p1, Point p2 )
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt( dx * dx + dy * dy );
}
```

---
### Example: Euclidean Distance (V2)
#### Apply our logic on two Points

--
##### Old version
```c++
double euclideanDistance( double x1, double y1, double x2, double y2 )
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return std::sqrt( dx * dx + dy * dy );
}
```
--
##### Second version (DRY Solution)
```c++
double euclideanDistance( Point p1, Point p2 )
{
  return euclideanDistance( p1.x, p1.y, p2.x, p2.y );
}
```
---
### Example: Euclidean Distance (V2)
#### Our main function 

--
##### In the past
```c++
int main()
{
    double px = 0, py = 0, qx = 0, qy = 0;
    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> px >> py >> qx >> qy;
    std::cout << euclideanDistance( px , py, qx , qy) << "\n";
}
```
--
##### Now
```c++
int main()
{
    Point p1,p2;
    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    std::cout << euclideanDistance( p1 , p2) << "\n";
}
```

---
### Example: Euclidean Distance (V3)

--
#### Let's bundle x and y .green[(and logic)]

--
```c++
struct Point
{
  double x;
  double y;
}
```

--
```c++
double euclideanDistance( Point p1, Point p2 )
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt( dx * dx + dy * dy );
}
```

--
We wish to be able to use this syntax:

```c++
p1.euclideanDistance( p2 );
```

---
### Example: Euclidean Distance (V3)
#### Bundle!

--
```c++
struct Point
{
  double euclideanDistance( Point p1, Point p2 )
  {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt( dx * dx + dy * dy );
  }
  double x;
  double y;
}
```

--
##### Done? 
--
##### .red[Not yet?!]

---
### Example: Euclidean Distance (V3)
#### Bundle!

--
```c++
struct Point
{
  double euclideanDistance( Point p )
  {
    double dx = x - p.x;
    double dy = y - p.y;
    return std::sqrt( dx * dx + dy * dy );
  }
  double x;
  double y;
}
```

--
#### Done? 
--
#### .green[Yes!]

---
### Example: Euclidean Distance (V3)
#### Our main function 

--
#### In the past

```c++
int main()
{
    Point p1,p2;
    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    std::cout << euclideanDistance( p1 , p2) << "\n";
}
```
--
#### Now
```c++
int main()
{
    Point p1,p2;
    std::cout << "Enter the two points coordinates as following: x1 y1 x2 y2 [ENTER]\n";
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    std::cout << p1.euclideanDistance( p2 ) << "\n";
}
```

---
### Example: DNA Analysis (V1)


Consider an application that counts the different bases in the DNA.


---
### Example: DNA Analysis (V1)
#### complementary base function

--
```c++
char complementaryBase(char base) {
  switch (base) {
      case 'A':
          return 'T';
      case 'T':
          return 'A';
      case 'C':
          return 'G';
      default:
          return 'C';
  }
}
```

---
### Example: DNA Analysis (V1)
#### complementary sequence

--
```c++
char *complementarySequence(char *base, int size) {
  char *compl = new char[size];
  for (int i = 0; i < size; ++i) {
    compl[size-i-1] = complementaryBase(base[i]);
  }
  return compl;
}
```

---
### Example: DNA Analysis (V1)
#### count character

--
```c++
int countCharacter(char *basePointer, int size, char query) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
      if (basePointer[i] == query) 
      {
        count += 1;
      }
  }
  return count;
}
```
 
---
### Example: DNA Analysis (V1)
#### Input from file

--
```c++
int main( int argc, char **argv)
{
  int counterA = 0, counterC = 0, counterG = 0 , counterT = 0;
  int size = 0;
  char *dnaArray1 = helpers::getFastaDNA(argv[1], size);
  
  char *complementarySeq = dna::analyzeDNA( &dnaArray1[0] , size , counterA , counterC , counterG , counterT );
  // We may need to make a new character array, but with a null terminated character to be able to print on screen.
  char *complementarySeqTerminated = new char[ size + 1 ];
  std::copy( &complementarySeq[0] , &complementarySeq[size] , &complementarySeqTerminated[0] );
  complementarySeqTerminated[ size ] = '\0';
  std::cout << "Adenine (A) content:" << counterA << std::endl
              << "Guanine (G) content:" << counterG << std::endl
              << "Cytocine(C) content:" << counterC << std::endl
              << "Thymine (T) content:" << counterT << std::endl
              << std::endl
              << "Complementary Sequence:" << std::endl
              << complementarySeqTerminated << std::endl;
}
```

---
### Example: DNA Analysis (V1)
#### Compile and run:



---
##### Example: DNA Analysis (V2)

--
##### Let's bundle the array and its size

--
```c++
struct DNA
{
  char *base;
  int size;
}
```

--
1. More concise
--
1. Mode descriptive

---
### Example: DNA Analysis (V2)
#### Our new functions

--
##### Old version
```c++
char *complementarySequence(char *base, int size) {
  char *complementarySequence = new char[size];
  for (int i = 0; i < size; ++i) {
      complementarySequence[size-i-1] = complementaryBase(base[i]);
  }
  return complementarySequence;
}
```
--
##### Second version
```c++
char *complementarySequence( DNA &dna )
{
    //
}
```

---
### Example: DNA Analysis (V2)
#### Our new complementary base function


###### Old version
```c++
char *complementarySequence(char *base, int size) {
  char *compl = new char[size];
  for (int i = 0; i < size; ++i) {
    compl[size-i-1] = complementaryBase(base[i]);
  }
  return compl;
}
```

###### Second version (bundle + DRY overloading)
```c++
char * complementarySequence( DNA &dna )
{
    complementarySequence( dna.base , dna.size );
}
```

--
###### Any typos?!

---
### Example: DNA Analysis (V2)
#### Our new complementary base function


###### Old version
```c++
char *complementarySequence(char *base, int size) {
  char *compl = new char[size];
  for (int i = 0; i < size; ++i) {
    compl[size-i-1] = complementaryBase(base[i]);
  }
  return compl;
}
```

##### Second version (bundle + DRY overloading)
```c++
char * complementarySequence( DNA &dna )
{
    return complementarySequence( dna.base , dna.size );
}
```

---
### Example: DNA Analysis (V2)
#### Our new count character function

--
##### In the past

```c++
int countCharacter(char *basePointer, int size, char query) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
      if (basePointer[i] == query) 
        count += 1;
  }
  return count;
}
```

--
##### Now
```c++
int countCharacter( DNA &dna, char query) {
  int count = 0;
  for (int i = 0; i < dna.size; ++i) {
      if (dna.base[i] == query) 
        count += 1;
  }
  return count;
}
```

--
###### Any enhancements?

---
### Example: DNA Analysis (V2)
#### Our new count character function


##### In the past

```c++
int countCharacter(char *basePointer, int size, char query) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
      if (basePointer[i] == query) 
      {
        count += 1;
      }
  }
  return count;
}
```


##### Now
```c++
int countCharacter( DNA &dna, char query) {
  return countCharacter( dna.base, dna.size, query );
}
```

---
### Example: DNA Analysis (V2)
#### The main function

##### In the past
--
```c++
int main( int argc, char **argv)
{
  int counterA = 0, counterC = 0, counterG = 0 , counterT = 0;
  int size = 0;
  char *dnaArray1 = helpers::getFastaDNA(argv[1], size);
  
  char *complementarySeq = dna::analyzeDNA( &dnaArray1[0] , size , counterA , counterC , counterG , counterT );
  // We may need to make a new character array, but with a null terminated character to be able to print on screen.
  char *complementarySeqTerminated = new char[ size + 1 ];
  std::copy( &complementarySeq[0] , &complementarySeq[size] , &complementarySeqTerminated[0] );
  complementarySeqTerminated[ size ] = '\0';
  std::cout << "Adenine (A) content:" << counterA << std::endl
              << "Guanine (G) content:" << counterG << std::endl
              << "Cytocine(C) content:" << counterC << std::endl
              << "Thymine (T) content:" << counterT << std::endl
              << std::endl
              << "Complementary Sequence:" << std::endl
              << complementarySeqTerminated << std::endl;
}
```

---
### Example: DNA Analysis (V2)
#### The main function

##### In the present

```c++
int main( int argc, char **argv)
{
  int counterA = 0, counterC = 0, counterG = 0 , counterT = 0;
  int size = 0;
  char *dnaArray1 = helpers::getFastaDNA(argv[1], size);
  dna::DNA dnaSequence { dnaArray, size };

  char *complementarySeq = dna::analyzeDNA( dnaSequence , counterA , counterC , counterG , counterT );
  // We may need to make a new character array, but with a null terminated character to be able to print on screen.
  char *complementarySeqTerminated = new char[ size + 1 ];
  std::copy( &complementarySeq[0] , &complementarySeq[size] , &complementarySeqTerminated[0] );
  complementarySeqTerminated[ size ] = '\0';
  std::cout << "Adenine (A) content:" << counterA << std::endl
              << "Guanine (G) content:" << counterG << std::endl
              << "Cytocine(C) content:" << counterC << std::endl
              << "Thymine (T) content:" << counterT << std::endl
              << std::endl
              << "Complementary Sequence:" << std::endl
              << complementarySeqTerminated << std::endl;
}
```


---
### Example: DNA Analysis (V3)
#### Let's bundle the array and its size (.green[and logic!])

```c++
struct DNA
{
  char *base;
  int size;
}
```

---
### Example: DNA Analysis (V3)
#### Let's bundle the array and its size (.green[and logic!])

```c++
int countCharacter( DNA &dna, char query) {
  int count = 0;
  for (int i = 0; i < dna.size; ++i) {
      if (dna.base[i] == query) 
      {
        count += 1;
      }
  }
  return count;
}
```

---
### Example: DNA Analysis (V3)
#### Let's bundle the array and its size (.green[and logic!])


```c++
char *complementarySequence( DNA &dna ) {
  char *compl = new char[dna.size];
  for (int i = 0; i < dna.size; ++i) {
    compl[dna.size-i-1] = complementaryBase(dna.base[i]);
  }
  return compl;
}
```

---
### Example: DNA Analysis (V3)
###### Let's bundle the array and its size (.green[and logic!])

```c++
struct DNA
{
  int countCharacter( DNA &dna, char query) {
    int count = 0;
    for (int i = 0; i < dna.size; ++i) {
        if (dna.base[i] == query) 
        {
          count += 1;
        }
    }
    return count;
  }

  char *complementarySequence( DNA &dna ) {
    char *compl = new char[dna.size];
    for (int i = 0; i < dna.size; ++i) {
      compl[dna.size-i-1] = complementaryBase(dna.base[i]);
    }
    return compl;
  }

  char *base;
  int size;
}
```

---
### Example: DNA Analysis (V3)
###### Let's bundle the array and its size (.green[and logic!])

```c++
struct DNA
{
  int countCharacter( char query) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (base[i] == query) 
        {
          count += 1;
        }
    }
    return count;
  }

  char *complementarySequence() {
    char *compl = new char[size];
    for (int i = 0; i < size; ++i) {
      compl[size-i-1] = complementaryBase(base[i]);
    }
    return compl;
  }
  
  char *base;
  int size;
}
```

---
### Example: DNA Analysis (V3)
###### Let's bundle the array and its size (.green[and logic!])
###### Let's use `std::string`

```c++
struct DNA
{
  int countCharacter( char query ) {
    int count = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        if (sequence[i] == query) 
        {
          count += 1;
        }
    }
    return count;
  }

  std::string complementarySequence() {
    std::string complementary = sequence;
    for (int i = 0; i < sequence.size(); ++i) {
      complementary[suquence.size() - i - 1] = complementaryBase(sequence[i]);
    }
    return complementary;
  }
  
  std::string sequence;
}
```

---
### Example: DNA Analysis (V2)
#### The main function

##### In the far past
--
```c++
int main( int argc, char **argv)
{
  int counterA = 0, counterC = 0, counterG = 0 , counterT = 0;
  int size = 0;
  char *dnaArray1 = helpers::getFastaDNA(argv[1], size);
  
  char *complementarySeq = dna::analyzeDNA( &dnaArray1[0] , size , counterA , counterC , counterG , counterT );
  // We may need to make a new character array, but with a null terminated character to be able to print on screen.
  char *complementarySeqTerminated = new char[ size + 1 ];
  std::copy( &complementarySeq[0] , &complementarySeq[size] , &complementarySeqTerminated[0] );
  complementarySeqTerminated[ size ] = '\0';
  std::cout << "Adenine (A) content:" << counterA << std::endl
              << "Guanine (G) content:" << counterG << std::endl
              << "Cytocine(C) content:" << counterC << std::endl
              << "Thymine (T) content:" << counterT << std::endl
              << std::endl
              << "Complementary Sequence:" << std::endl
              << complementarySeqTerminated << std::endl;
}
```

---
### Example: DNA Analysis (V2)
#### The main function

##### In the near past

```c++
int main( int argc, char **argv)
{
  int counterA = 0, counterC = 0, counterG = 0 , counterT = 0;
  int size = 0;
  char *dnaArray1 = helpers::getFastaDNA(argv[1], size);
  dna::DNA dnaSequence { dnaArray, size };

  char *complementarySeq = dna::analyzeDNA( dnaSequence , counterA , counterC , counterG , counterT );
  // We may need to make a new character array, but with a null terminated character to be able to print on screen.
  char *complementarySeqTerminated = new char[ size + 1 ];
  std::copy( &complementarySeq[0] , &complementarySeq[size] , &complementarySeqTerminated[0] );
  complementarySeqTerminated[ size ] = '\0';
  std::cout << "Adenine (A) content:" << counterA << std::endl
              << "Guanine (G) content:" << counterG << std::endl
              << "Cytocine(C) content:" << counterC << std::endl
              << "Thymine (T) content:" << counterT << std::endl
              << std::endl
              << "Complementary Sequence:" << std::endl
              << complementarySeqTerminated << std::endl;
}
```

---
### Example: DNA Analysis (V2)
#### The main function

##### In the present

```c++
int main( int argc, char **argv)
{
  int counterA = 0, counterC = 0, counterG = 0 , counterT = 0;
  int size = 0;
  char *dnaArray1 = helpers::getFastaDNA(argv[1], size);
  dna::DNA dnaSequence { dnaArray, size };

  std::cout << "Adenine (A) content:" << dna.countCharacter('A') << std::endl
              << "Guanine (G) content:" << dna.countCharacter('G') << std::endl
              << "Cytocine(C) content:" << dna.countCharacter('C') << std::endl
              << "Thymine (T) content:" << dna.countCharacter('T') << std::endl
              << std::endl
              << "Complementary Sequence:" << std::endl
              << dna.complementarySequence() << std::endl;
}
```





</textarea>