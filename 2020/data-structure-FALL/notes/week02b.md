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

# Interfaces and Abstract Classes

In order for two objects to interact, they must “know” about the various messages
that each will accept, that is, the methods each object supports. To enforce this
“knowledge,” the object-oriented design paradigm asks that classes specify the
application programming interface (API), or simply interface, that their objects
present to other objects.

## Interfaces in Java

The main structural element in Java that enforces an API is an interface. An in-
terface is a collection of method declarations with no data and no bodies. That is,
the methods of an interface are always empty; they are simply method signatures.
Interfaces do not have constructors and they cannot be directly instantiated.

When a class implements an interface, it must implement all of the methods
declared in the interface. In this way, interfaces enforce requirements that an im-
plementing class has methods with certain specified signatures.

**For Example:**

* Interface for objects that can be sold

```java
/** 
 * Interface for objects that can be sold. 
 * */

public interface Sellable {
	// return description of object
	public String description();
	
	// return the price
	public int listPrice();

	//return the lowest price
	public int lowestPrice();
}

```

* Interface for objects that can be transported

```java
/**
 * Interface for objects that can be transported.
 */

public interface Transportable {
	//return weight 
	public int weight();
	// return whether the object is hazrdous
	public boolean isHazardous();

}

```

* Photograph class that implements sellable interface

```java
public class Photograph implements Sellable {
	private String descript;
	private int price;
	private boolean color;

	public Photograph(String desc, int p, boolean c) {
		descript = desc;
		price = p;
		color = c;
	}

	@Override
	public String description() {
		return descript;
	}

	@Override
	public int listPrice() {
		return price;
	}

	@Override
	public int lowestPrice() {
		return price / 2;
	}

	public boolean isColor() {
		return color;
	}

}
```

* Boxed item class that implements both sellable and transportable class

```java
public class BoxedItem implements Sellable, Transportable {

	private String descript;
	private int price;
	private int weight;
	private boolean haz;
	private int height = 0;
	private int depth = 0;
	private int width = 0;

	public BoxedItem(String desc, int p, int w, boolean h) {
		descript = desc;
		price = p;
		weight = w;
		haz = h;
	}

	@Override
	public int weight() {
		return weight;
	}

	@Override
	public boolean isHazardous() {
		return haz;
	}

	@Override
	public String description() {
		return descript;
	}

	@Override
	public int listPrice() {
		return price;
	}

	@Override
	public int lowestPrice() {
		return price / 2;
	}

	public int insuredValue() {
		return price * 2;
	}

	public void setBox(int h, int w, int d) {
		height = h;
		width = w;
		depth = d;
	}
}
```

## Abstract Classes in java

In Java, an abstract class serves a role somewhat between that of a traditional class
and that of an interface. Like an interface, an abstract class may define signatures
for one or more methods without providing an implementation of those method
bodies; such methods are known as abstract methods. However, unlike an inter-
face, an abstract class may define one or more fields and any number of methods
with implementation (so-called concrete methods). An abstract class may also ex-
tend another class and be extended by further subclasses.

As is the case with interfaces, an abstract class may not be instantiated, that is,
no object can be created directly from an abstract class. In a sense, it remains an
incomplete class. A subclass of an abstract class must provide an implementation
for the abstract methods of its superclass, or else remain abstract. T

To distinguish from abstract classes, we will refer to nonabstract classes as concrete classes.
In comparing the use of interfaces and abstract classes, it is clear that abstract
classes are more powerful, as they can provide some concrete functionality. How-
ever, the use of abstract classes in Java is limited to single inheritance.

**Lets re-write the progressing class as a Abstract Class**

```java
package progression;

public abstract class AbstractProgression {
	protected long current;

	public AbstractProgression() {
		this(0);
	}

	public AbstractProgression(long start) {
		current = start;
	}

	public long nextValue() {
		long answer = current;
		advance();
		return answer;
	}

	public void printProgression(int n) {
		System.out.print(nextValue());
		for (int j = 1; j < n; j++)
			System.out.print(" " + nextValue()); // print leading space before others
		System.out.println();
	}

	protected abstract void advance();
}
```

## Casting and Generics

casting among reference variables, as well as a technique,
called generics, that allows us to define methods and classes that work with a variety
of data types without the need for explicit casting.

### Casting

**Widening Conversions** occurs when a type T is converted into a “wider” type U .
The following are common cases of widening conversions:
* T and U are class types and U is a superclass of T .
* T and U are interface types and U is a superinterface of T .
* T is a class that implements interface U .

we gave the following example of an implicit widening cast, assigning
an instance of the narrower PredatoryCreditCard class to a variable of the wider
CreditCard type:
```java
CreditCard card = new PredatoryCreditCard(...);
```

**Narrowing Conversions** occurs when a type T is converted into a “narrower”
type S. The following are common cases of narrowing conversions:
* T and S are class types and S is a subclass of T .
* T and S are interface types and S is a subinterface of T .
* T is an interface implemented by class S.

In general, a narrowing conversion of reference types requires an explicit cast.
Also, the correctness of a narrowing conversion may not be verifiable by the com-
piler. Thus, its validity should be tested by the Java runtime environment during
program execution.

```java
CreditCard card = new PredatoryCreditCard(...);        // widening
PredatoryCreditCard pc = (PredatoryCreditCard) card;  // narrowing
```

### Generics

Java includes support for writing generic classes and methods that can operate on a
variety of data types while often avoiding the need for explicit casts. The generics
framework allows us to define a class in terms of a set of formal type parameters,
which can then be used as the declared type for variables, parameters, and return
values within the class definition. Those formal type parameters are later specified
when using the generic class as a type elsewhere in a program.

```java
public class ObjectPair {
	Object first;
	Object second;

	public ObjectPair(Object a, Object b) {
		first = a;
		second = b;
	}

	public Object getFirst() {
		return first;
	}

	public Object getSecond() {
		return second;
	}
	public static void main(String[] args) {
		ObjectPair bid = new ObjectPair("ORCL", 32.07);
		String stock = (String) bid.getFirst( ); // narrowing cast: Object to String: needes casting from object to string
	}
}
```

### Java’s Generics Framework

With Java’s generics framework, we can implement a pair class using formal type
parameters to represent the two relevant types in our composition.

```java
public class Pair<A, B> {

	A first;
	B second;
	public Pair(A a, B b) {
		first = a;
		second = b;
	}
	public A getFirst() {
		return first;
	}
	public B getSecond() {
		return second;
	}
	public static void main(String[] args) {
		Pair<String,Double> bid;
		bid = new Pair<>("ORCL", 32.07); 
		bid = new Pair<String,Double>("ORCL", 32.07);
		bid = new Pair("ORCL", 32.07);
	}
}
```

### Generic Methods

The generics framework allows us to define generic versions of individual methods
(as opposed to generic versions of entire classes). To do so, we include a generic
formal type declaration among the method modifiers.

```java
public class GenericDemo {
	public static <T> void reverse(T[ ] data) {
		int low = 0, high = data.length − 1;
		while (low < high) {
			// swap data[low] and data[high]
			T temp = data[low];
			data[low++] = data[high];
			// post-increment of low
			data[high−−] = temp;
			// post-decrement of high
		}
	}
}
```