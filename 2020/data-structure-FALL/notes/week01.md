---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: page
category: "notes"
course: "CMP2241"
year: "2020"
---
* TOC
{:toc}

## Introduction: JAVA Basics

### Simple Program
```java
public classMain{
    public static void main{
        system.out.printline("hello world");
    }

}
```

### Variables and Data Structures
#### Variables

| Variable | Desc. | 
|---------|-----|
|   boolean     | a boolean value: true or false |
|   char     | 16-bit Unicode character |
|   byte     | 8-bit signed two’s complement integer |
|   short     | 16-bit signed two’s complement integer |
|   int     | 32-bit signed two’s complement integer |
|   long     | 64-bit signed two’s complement integer |
|   float     | 32-bit floating-point number (IEEE 754-1985) |
|   double     | 64-bit floating-point number (IEEE 754-1985) |

#### Construction of Variables
A variable basically has:

1. **Data Type**: int, char, bool, …, etc.
2. **Name**: name of the variable to be used throughout your code.
3. **Value**: the content of the variable.

Example
```java
boolean flag = true;
boolean verbose, debug;
char grade = 'A';
byte b = 12;
short s = 24;
int i, j, k = 257;
long l = 890L;
float pi = 3.1416F;
double e = 2.71828, a = 6.022e23;
```

### Classes and Objects

### classes
In more complex Java programs, the primary “actors” are objects. Every object is an instance of a class, which serves as the type of the object and as a blueprint,defining the data which the object stores and the methods for accessing and modifying that data. The critical members of a class in Java are the following:
* **Instance variables,**:which are also called fields, represent the data associated
with an object of a class. Instance variables must have a type, which can
either be a base type (such as int, float, or double) or any class type (also
known as a reference type for reasons we soon explain).

* **Methods** in Java are blocks of code that can be called to perform actions
(similar to functions and procedures in other high-level languages). Methods
can accept parameters as arguments, and their behavior may depend on the
object upon which they are invoked and the values of any parameters that are
passed. A method that returns information to the caller without changing any
instance variables is known as an accessor method, while an update method
is one that may change one or more instance variables when called.

```java
public class Counter {
private int count; // a simple integer instance variable
public Counter( ) { } // default constructor (count is 0)
public Counter(int initial) { count = initial; } // an alternate constructor
public int getCount( ) { return count; } // an accessor method
public void increment( ) { count++; } // an update method
public void increment(int delta) { count += delta; } // an update method
public void reset( ) { count = 0; } // an update method
}
```
### modifiers

Immediately before the definition of a class, instance variable, or method in Java,
keywords known as modifiers can be placed to convey additional stipulations about
that definition.

#### Access Control Modifiers
They control the level of access (also known as visibility) that the defining class grants
to other classes in the context of a larger Java program.

* The **public** class modifier designates that all classes may access it and the public class  must be written in a separate file
* The **protected** class modifier designates that access to the defined aspect is only granted to the following groups of other classes:
    * Classes that are designated as subclasses of the given class through inheritance.
    * Classes that belong to the same package.
* The **private** class modifier designates that access to a defined member of a
class be granted only to code within that class. Neither subclasses nor any
other classes have access to such members.

#### The static Modifier
The static modifier in Java can be declared for any variable or method of a class.
* When a variable of a class is declared as static, its value is associated with
the class as a whole, rather than with each individual instance of that class. Static
variables are used to store “global” information about a class. (For example, a static
variable could be used to maintain the total number of instances of that class that
have been created.) Static variables exist even if no instance of their class exists.
* When a method of a class is declared as static, it too is associated with the
class itself, and not with a particular instance of the class. That means that the
method is not invoked on a particular instance of the class using the traditional dot
notation. Instead, it is typically invoked using the name of the class as a qualifier.

#### The abstract Modifier
A method of a class may be declared as abstract, in which case its signature is pro-
vided but without an implementation of the method body. Abstract methods are an
advanced feature of object-oriented programming to be combined with inheritance.

#### The final Modifier
A variable that is declared with the final modifier can be initialized as part of that
declaration, but can never again be assigned a new value. If it is a base type, then
it is a constant. If a reference variable is final, then it will always refer to the same
object

### Instance declaration

```
[modifiers] type identifier=initialValue;
```
### Method declaration

```
[modifiers] returnType methodName(type 1 param 1 , . . . , type n param n ) {
// method body
}
```

### Defining Constructors
A constructor is a special kind of method that is used to initialize a newly created
instance of the class so that it will be in a consistent and stable initial state. This
is typically achieved by initializing each instance variable of the object (unless
the default value will suffice), although a constructor can perform more complex
computation. The general syntax for declaring a constructor in Java is as follows:
```
modifiers name(type 0 parameter 0 , . . . , type n−1 parameter n−1 ) {
// constructor body . . .
}
```
Constructors are defined in a very similar way as other methods of a class, but there
are a few important distinctions:
1. Constructors cannot be static, abstract, or final, so the only modifiers that
are allowed are those that affect visibility (i.e., public, protected, private,
or the default package-level visibility).
2. The name of the constructor must be identical to the name of the class it
constructs. For example, when defining the Counter class, a constructor must
be named Counter as well.
3. We don’t specify a return type for a constructor (not even void). Nor does
the body of a constructor explicitly return anything.

### The main Method
Some Java classes, such as our Counter class, are meant to be used by other classes,
but are not intended to serve as a self-standing program. The primary control for an
application in Java must begin in some class with the execution of a special method
named main. This method must be declared as follows:
```
public static void main(String[ ] args) {
// main method body...
}
```

### Arrays Declaration
Declaring and Constructing Arrays
Arrays in Java are somewhat unusual, in that they are not technically a base type
nor are they instances of a particular class. With that said, an instance of an array is
treated as an object by Java, and variables of an array type are reference variables.
To declare a variable (or parameter) to have an array type, we use an empty
pair of square brackets just after the type of element that the array will store. For
example, we might declare:
```java
int[ ] primes;
int[ ] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
double[ ] measurements = new double[1000];
```

### Enum Types
In olden times, programmers would often define a series of constant integer values
to be used for representing a finite set of choices. For example, in representing a
day of the week, they might declare variable today as an int and then set it with
value 0 for Monday, 1 for Tuesday, and so on.
A slightly better programming style is to define static constants (with the final
keyword), to make the associations, such as:
```java
static final int MON = 0;
static final int TUE = 1;
static final int WED = 2;
static final int THU = 3;
static final int FRI = 4;
static final int SAT = 5;
static final int SUN = 6;
public enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
Day today;
today = Day.TUE;
```

### Control Flow
In Java, conditionals work similarly to the way they work in other languages. They
provide a way to make a decision and then execute one or more different statement
blocks based on the outcome of that decision.

#### The If Statement

```
if (booleanExpression)
  trueBody
else
  falseBody
```

```
if (firstBooleanExpression)
  firstBody
else if (secondBooleanExpression)
  secondBody
else
  thirdBody
```

#### Switch Statements
Java provides for multiple-value control flow using the switch statement, which is
especially useful with enum types. 
```
switch (d) {
case MON:
  System.out.println("This is tough.");
  break;
case TUE:
  System.out.println("This is getting better.");
  break;
case WED:
  System.out.println("Half way there.");
  break;
case THU:
  System.out.println("I can see the light.");
  break;
case FRI:
  System.out.println("Now we are talking.");
  break;
default:
  System.out.println("Day off!");
}
```

#### while Loop
The simplest kind of loop in Java is a while loop. Such a loop tests that a certain
condition is satisfied and will perform the body of the loop each time this condition
is evaluated to be true. The syntax for such a conditional test before a loop body
is executed is as follows:
```
while (booleanExpression){}
  loopBody
}
```

#### Do while loop
Java has another form of the while loop that allows the boolean condition to be
checked at the end of each pass of the loop rather than before each pass. This form
is known as a do-while loop, and has syntax shown below:
```
do
  loopBody
while (booleanExpression)
```

#### For loop
for (initialization; booleanCondition; increment)
loopBody
For example, the most common use of a for loop provides repetition based on an
integer index, such as the following:
```
for (int j=0; j < n; j++)
// do something
```

### Software Development
Traditional software development involves several phases. Three major steps are:
1. Design
2. Coding
3. Testing and Debugging

For object-oriented programming, the design step is perhaps the most important
phase in the process of developing software. It is in the design step that we decide
how to divide the workings of our program into classes, when we decide how these
classes will interact, what data each will store, and what actions each will perform.
Indeed, one of the main challenges that beginning programmers face is deciding
what classes to define to do the work of their program.

## Example Program

CreditCard class defines
credit card objects that model a simplified version of traditional credit cards. They
store information about the customer, issuing bank, account identifier, credit limit,
and current balance. They do not charge interest or late payments, but they do
restrict charges that would cause a card’s balance to go over its credit limit. We
also provide a static main method as part of this class to demonstrate its use.

```java
public class CreditCard {
	private String customer;
	private String bank;
	private String account;
	private int limit;
	protected double balance;

	public CreditCard(String cust, String bk, String acnt, int lim, double initialBal) {
		customer = cust;
		bank = bk;
		account = acnt;
		limit = lim;
		balance = initialBal;
	}

	public CreditCard(String cust, String bk, String acnt, int lim) {
		this(cust, bk, acnt, lim, 0.0);
	}

	public String getCustomer() {
		return customer;
	}

	public String getBank() {
		return bank;
	}

	public String getAccount() {
		return account;
	}

	public int getLimit() {
		return limit;
	}

	public double getBalance() {
		return balance;
	}

	public boolean charge(double price) {
		if (price + balance > limit)
			return false;
		balance += price;
		return true;
	}

	public void makePayment(double amount) {
	    balance -= amount;
	  }

	public static void printSummary(CreditCard card) {
		System.out.println("Customer = " + card.customer);
		System.out.println("Bank = " + card.bank);
		System.out.println("Account = " + card.account);
		System.out.println("Balance = " + card.balance);
		System.out.println("Limit = " + card.limit);
	}

	public static void main(String[ ] args) {
	      CreditCard[ ] wallet = new CreditCard[3];
	      
	      wallet[0] = new CreditCard("John Bowman", "California Savings",
	      "5391 0375 9387 5309", 5000);
	      
	      wallet[1] = new CreditCard("John Bowman", "California Federal",
	      "3485 0399 3395 1954", 3500);
	      
	      wallet[2] = new CreditCard("John Bowman", "California Finance",
	      "5391 0375 9387 5309", 2500, 300);
	      
	      for (int val = 1; val <= 16; val++) {
	      wallet[0].charge(3*val);
	      wallet[1].charge(2*val);
	      wallet[2].charge(val);
	      }
	      CreditCard.printSummary(wallet[0]);
	      CreditCard.printSummary(wallet[1]);
	      CreditCard.printSummary(wallet[2]);
	  }
}
```


