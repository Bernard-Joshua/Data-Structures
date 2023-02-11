# Data-Structures
This directory contains my University Assignments for COS30008. <br/>

# List of Assignments


# Problem Set 1 – Solution Design in C++

## Problem 1
Write a program using array for the following problem statement:

PTR Company has three different branches selling various car dash cam. The manager would like
to calculate monthly sales figure for four different dash cam models for all the branches. Create a
program that could store all sales figures (unit sold) by each branch and selling price for each
model of dash cam. Refer to the following tables:

Example of Unit Sold (monthly) (UnitSold array):

| Dash Cam model | SJ Branch | PJ Branch | KL Branch |
| --- | --- | --- | --- |
| RS Pro with GPS | 5 | 4 | 3 |
| Transcend Drive Pro | 2 | 2 | 3 |
| H203 1080P | 3 | 2 | 5 |
| Pioneer | 4 | 5 | 3 |

Dash Cam selling price (Price array):

| Dash Cam model Price| (RM) |
| --- | --- |
|RS Pro with GPS| 730 |
|Transcend Drive Pro|850|
|H203 1080P| 150|
| Pioneer | 350 |

The program stores the unit sold into a two-dimensional array named UnitSold. Every month, the
user will enter all sales figures (unit sold) while the price of each model is fixed (refer to the Price
array above).

After all the input process completed, the program will display the following output (based on the
table above):

Total gross sales for Branch SJ is: RM ...
Total gross sales for Branch PJ is: RM ...
Total gross sales for Branch KL is: RM ...

The highest sales figure is RM ... by Branch ..
The most popular dash cam model is ......... with unit sold of .. units.

## Problem 2

The class Combination has two instance variables representing n and k. The constructor

initializes those instance variables and the getters provide read-only access to their values.

The call operator() returns the value of a combination. We use the method described on

Wikipedia: https://en.wikipedia.org/wiki/Combination rather than calculating the factorials,

which can become very big numbers. You need to use the type unsigned long for

calculation in order to work with 64-bit values.

# Problem Set 2 - Indexers, Iterators, and Inheritance

## Problem 1

 In this problem set, we define a simple integer vector class, called IntVector, that provides us with
 a container type for integer arrays. The class IntVector shares some similarities with the standard
 vector class std::vector, but we only define those features here that would allow us to practice indexers, iterators, and inheritance (the latter is being used to define sorter objects).

 The classes that we define in this problem set are largely mutual dependent, that is, we need to
 manually resolve class dependencies and use forward declarations to break cycles.

The class IntVector depends on class IntSorter and IntVectorIterator. The former defines an
 interface for callable sorter objects, whereas the latter defines a standard forward iterator for
 IntVector objects. The constructor for IntVector takes an integer array and its size as parameters.

The destructor has to free the allocated memory and the member function size() has to return the
 number of elements in the array.

 The member function swap() takes two indices and, if they are within range, swaps the
 corresponding array elements in an IntVector object. We need swap() for sorting.

 The member function sort() takes a callable sorter object of type IntSorter (or a subtype thereof)
 and performs an in-place sorting based on the algorithm defined by the callable sorter object.

 This indexer operator[] returns the value that corresponds to aIndex if this is possible. Please note
 that the indexer returns a read-only value copy by design. This has not impact on performance, but
 requires us to use member function swap() when we wish to exchange array elements.

 The member functions begin() and end() return a corresponding forward iterator positioned at the
 first and after the last element, respectively, in the usual way. You will need to implement class IntVectorIterator before you can test class IntVector.

## Question 2

Implement Cocktail Shaker Sort, that is, implement class CocktailShakerSort which is a public
 subclass of IntSorter.

Cocktail Shaker Sort is bidirectional Bubble Sort. There is no need for a flag "is-sorted" even
 though some sources suggest one. There is limited if any improvement on the performance of the
 algorithm. Worse, it may even slow it down due to the extra tests necessary. See D.E. Knuth's
 comments on this matter. The implementation of Cocktail Shaker Sort can be achieved solely in
 the call operator. Please note that you need to use IntVector's swap() member function to exchange
 elements:

![](RackMultipart20230211-1-wots4c_html_82a8c0ea6b1d1388.png)

# Problem Set 3 - List ADT
## Problem 1 

It  might  be  beneficial  to  review  the  lecture  material  regarding  template  class DoublyLinkedList  and DoublyLinkedListIterator also the the construction of an abstract data type and memory management.

Start with the header files provided on Canvas, as they have been fully tested.

Using  the  template  classes DoublyLinkedList  and DoublyLinkedListIterator, implement the template class List as specified below:

```
**#pragma once**

**#include**  "DoublyLinkedList.h" **#include** "DoublyLinkedListIterator.h" **#include** <stdexcept>

**template**<**typename** T>

**class** List

{ 

**private**:

// auxiliary definition to simplify node usage **using** Node = DoublyLinkedList<T>;

Node**\*** fRoot;  // the first element in the list size\_t fCount;  // number of elements in the list

**public**:

// auxiliary definition to simplify iterator usage **using** Iterator = DoublyLinkedListIterator<T>;


List(); 

List( **const** List**&** aOtherList ); 

List**& operator=**( **const** List**&** aOtherList ); ~List(); 

**bool** isEmpty() **const**; size\_t size() **const**; 

**void** push\_front( **const** T**&** aElement ); **void** push\_back( **const** T**&** aElement ); **void** remove( **const** T**&** aElement ); 

// default constructor

// copy constructor 

// assignment operator

// destructor - frees all nodes

// Is list empty? // list size

// adds aElement at front

// adds aElement at back

// remove first match from list



**const** T**& operator[]**( size\_t aIndex ) **const**; // list indexer

Iterator begin() **const**;  // return a forward iterator Iterator end() **const**;  // return a forward end iterator Iterator rbegin() **const**;  // return a backwards iterator Iterator rend() **const**;  // return a backwards end iterator

// move features

List( List**&&** aOtherList );  // move constructor List**& operator=**( List**&&** aOtherList );  // move assignment operator **void** push\_front( T**&&** aElement );  // adds aElement at front **void** push\_back( T**&&** aElement );  // adds aElement at back

};
```

The template class List defines an “object adapter” for DoublyLinkedList objects (i.e., the list representation). Somebody else has already started with the implementation, but left the project unfinished. You find a header file for the incomplete List class on Canvas. This header file contains the specification of the template class List and the implementations for the destructor ~List() and the remove() method. You need to implement the remaining member functions.


##Problem 2

Implement the default constructor, the methods push\_front(), size(), and isEmpty(), and the iterator methods first. You can use #define P1  in Main.cpp  to enable the corresponding test driver.

```
**void** testP1()

{

string s1( "AAAA" ); string s2( "BBBB" ); string s3( "CCCC" ); string s4( "DDDD" );

List<string> lList;

lList.push\_front( s4 ); lList.push\_front( s3 ); 

lList.push\_front( s2 ); lList.push\_front( s1 );

// iterate from the top

cout << "Top to bottom " << lList.size() << " elements:" << endl; **for** ( **const** string**&** element : lList )

{

cout << element << endl;

}

}
```

The result should look like this:

```
Top to bottom 4 elements: AAAA

BBBB 

CCCC 

DDDD
```

Implement the method push\_back(), which is just a variant of method push\_front(). You can use #define P2 in Main.cpp to enable the corresponding test driver. 

```
**void** testP2()

{

string s1( "AAAA" ); string s2( "BBBB" ); string s3( "CCCC" ); string s4( "DDDD" );

List<string> lList;

lList.push\_front( s4 ); lList.push\_front( s3 ); 

lList.push\_front( s2 ); lList.push\_front( s1 );

string s5( "EEEE" ); string s6( "FFFF" );

lList.push\_back( s5 ); lList.push\_back( s6 );

// iterate from the top

cout << "Bottom to top" << lList.size() << " elements:" << endl; **for** ( List<string>::Iterator iter = lList.rbegin(); 

iter != iter.rend(); iter-- )

{

cout << **\***iter << endl; }

}
```

The result should look like this:

```
Bottom to top6 elements: FFFF

EEEE 

DDDD 

CCCC 

BBBB AAAA
```

Implement **operator[]**. The indexer has to search for the element that corresponds to aIndex.  Also, aIndex  may  be  out  of  bounds.  Hence  the  indexer  has  to  throw  a range\_error  exception.  You  can  use #define P3  in Main.cpp  to  enable  the corresponding test driver.

```
**void** testP3()

{

string s1( "AAAA" ); string s2( "BBBB" ); string s3( "CCCC" ); string s4( "DDDD" ); string s5( "EEEE" ); string s6( "FFFF" );

List<string> lList;

lList.push\_front( s4 ); lList.push\_front( s3 ); lList.push\_front( s2 ); lList.push\_front( s1 ); lList.push\_back( s5 ); lList.push\_back( s6 );

cout << "Element at index 4: " << lList[4] << endl; lList.remove( s5 );

cout << "Element at index 4: " << lList[4] << endl;

}
```

The result should look like this:

```
Element at index 4: EEEE Element at index 4: FFFF

Add proper copy control to the template class List, that is, implement the copy constructor and the assignment operator:

- List( **const** List& aOtherList ),
- List**& operator=**( **const** List**&** aOtherList ).
```

You can use #define P4 in Main.cpp to enable the corresponding test driver. 

```
**void** testP4()

{

string s1( "AAAA" ); string s2( "BBBB" ); string s3( "CCCC" ); string s4( "DDDD" ); string s5( "EEEE" );

List<string> lList;

lList.push\_front( s4 ); lList.push\_front( s3 ); lList.push\_front( s2 );

List<string> copy( lList );

// iterate from the top

cout << "A - Top to bottom " << copy.size() << " elements:" << endl;

**for** ( **const** string**&** element : copy ) {

cout << element << endl;

}

// override list lList = copy;

lList.push\_front( "AAAA" ); lList.push\_back( "EEEE" );

// iterate from the top

cout << "B – Bottom to top " << lList.size() << " elements:" << endl;

**for** ( **auto** iter = lList.rbegin(); iter != iter.rend(); iter-- ) {

cout << **\***iter << endl;

}

}
```

The result should look like this:

```
A - Top to bottom 3 elements: BBBB

CCCC 

DDDD

B – Bottom to top 5 elements: EEEE

DDDD 

CCCC 

BBBB AAAA
```

Implement the move features:

```
- List( List**&&** aOtherList ),
- List**& operator=**( List**&&** aOtherList ),
- **void** push\_front( T**&&** aElement ),
- **void** push\_back( T**&&** aElement ).
```

You can use #define P5 in Main.cpp to enable the corresponding test driver. 

```
**void** testP5()

{

List<string> lList;

lList.push\_front( "DDDD" ); lList.push\_front( "CCCC" ); lList.push\_front( "BBBB" );

List<string> move( std::move(lList) );

// iterate from the top

cout << "A - Top to bottom " << move.size() << " elements:" << endl;

**for** ( **const** string**&** element : move ) {

cout << element << endl;

}

// override list

lList = std::move(move);

lList.push\_front( "AAAA" ); lList.push\_back( "EEEE" );

// iterate from the top

cout << "B – Bottom to top " << lList.size() << " elements:" << endl;

**for** ( **auto** iter = lList.rbegin(); iter != iter.rend(); iter-- ) {

cout << **\***iter << endl;

}

}
```

The result should look like this:

```
A - Top to bottom 3 elements: BBBB 

CCCC 

DDDD

B – Bottom to top 5 elements: EEEE 

DDDD 

CCCC 

BBBB 

AAAA
```
