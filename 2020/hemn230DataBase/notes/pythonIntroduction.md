---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: page
category: "notes"
course: "sbe306a"
year: "2019"
---
* TOC
{:toc}

## Introduction: Python Basics
Python is easy to use, powerful, and versatile, making it a great choice for beginners and experts alike. Python’s readability makes it a great first programming language — it allows you to think like a programmer and not waste time with confusing syntax. For instance, look at the following code to print “hello world” in Java and Python.

```java
public classMain{
    public static void main{
        system.out.printline("hello world");
    }

}
```

```python
print("hello world")
```

[why python](https://www.makeuseof.com/tag/python-language-future/)

### Variables

Variables in python are very flexible, unlike C++:

* Interpreted language.
* No need to declare the variable type.
* The same variable can be assigned to different types.


```python
x = 5
y = 'Hello SBME'
z = 5
z = "Hello SBME"
```

### Lists

```python
# List construction
subjects = ['Technical Writing','Computer Vision']

# Append an element
subjects.append('Biochemistry')

# Append another list
subjects.extend(['Bioelectronics','Stochastic'])

print( subjects ) # ??
print( subjects[0] ) # ??
print( subjects[1] ) # ??
```


### Arithmetic Operations

```python

x = 19
y = 18 

z = x / y
z = x * y
z = x + y
z = x - y

```

### Logical Opertations

```python
x = 17 % 2 == 1

y = 9 / 3 < 1 

b = x or y ## True

b = x and y ## False
```

- `and` => `&&` in C++ 

- `or` => `||` in C++

### If, elif, else

```python 

x = 23 
y = 22 

if x < y:
  z = 13 # Local scope

elif x % 2 == 1 and x > y :
  h = 17 # Local scope

else:
  v = 80 # Local scope

print( z ) # Error: z is out of scope
print( h ) # Error: h is out of scope
```

### Loops

```python

for i in range(10):
  print( i )

i = 0
while i < 10 :
  print( i )
  i += 1
```



### Functions

```python
def mean( list ):
  sum = 0
  for element in list:
    sum += element
  return sum / len( sum )

m = mean([1,12,42,1,23,12])
print( m )
```