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
