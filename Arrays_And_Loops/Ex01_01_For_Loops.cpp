//
//Introduction.
// 
// An array enables you to work with several data - items of the same type using a single name, the array name.
// The need for this occurs often - when working with series of financial market data. A loop is another fundamental programming facility.
// It provides the mechanism for repeating one or more statements as many times as your application requires it.Loops are essential in the majority of programs.
// 
// Arrays.
// ------
// 
// An array stores several data - items of the same type.You can create an array of dates, an array of floats(or in fact an array of any type of data).
// 
// Using an array.
// -------------
// 
// An array is a variable that represents a sequence of memory locations, each storing an item of data of the same data type.
// 
// Suppose for instance, we've written a program to calculate the 30-day MA price of a stock. Now, we want to extend the program
// to display the instances where the stock price was above the average and how many are below. We'll need the original
// EOD sample data to do this, but storing each data - item in a separate variable would be tortuous to code and
// highly impractical.An array provides you with the means of easily doing so.We could store the $365$ days worth
// of stock price data in an array defined as follows :
// 
// //Define an array of 365 stock prices
// double stockPrice[366];
// 

//tex:
// This defines an array with the name stockPrice to store $365$ values of type double.


// The data values are called elements. The number of elements specified between the brackets is the size of the array.
// The array elements are not initialized in this statement so they contain junk values.

// 
// The size of an array must always be specified using a constant integer expression.
// Any integer expression that the compiler can evaluate at compile time may be used, though mostly
// this will either be an integer literal or const integer that itself was initialized using a literal.
// 
// You refer to an array element using an integer called an index.The index of a particular array element
// is its offset from the first element.The first element has an offset of $0$ and therefore an index of $0$;
// and index value of $3$ refers to the fourth array element - three elements from the first.To reference an element,
// you put its index between the square brackets after the array name, so the set the fourth element of the
// stockPrice array to 99.0 you would write the following :
// 
// 

// Set the fourth array element to 99.0
// stockPrice[3] = 99.0;

// 
// 
// Let's look at another array:
// 
// //Define an array of weekly stock trading volumes(in millions of USD)
// unsigned int volume[52];
// 
// 
// The compiler will allocate fifty - two contiguous storage locations for storing values of type unsigned int
// as a result of this definition.Each element in the volume array contains a different number. Because the
// definition of volume doesn't specify any initial values, the fifty two elements will contain junk values
// (analogous to what happens if you define a single variable of type unsigned int without an initial value).
// You could define the array with proper initial values like this:
// 
// //Define and initialize array of 52 volumes
// unsigned int volume[52] = {
//             26,37,47,55,
//             21,33,25,62,
//             15,42,67,86,
//             53,48,42,99,
//             25,50,32,16,
//             64,75,85,81,
//             02,40,99,98,
//             12,65,05,07,
//             08,24,56,72,
//             09,18,27,36,
//             10,20,30,40,
//             11,22,55,66,
//             12,24,84,96,
//             13,39,78,91 };
// 
// 
// The braced initializer contains fifty - two values separated by commas.These might be the volumes 
// of the stocks traded on an exchange, recorded to the nearest million.Each array element will be assigned an 
// initial value from the list in the sequence, so the elements will have values shown.
// 
// The initializer must not have more values than there are elements; otherwise the statement won't compile. 
// There can be fewer values in the list, however, in which case, the elements for which no initial value has been 
// supplied will be initialized with zero (false for an array of bool elements).
// 
// cpp
// //All elements 0
// unsigned int volume = {};
// 
// 
// To define an array of values that cannot be modified, you simply add the keyword const to it's type. 
// The following defines an array of six unsigned int constants:
// 
// cpp
// const unsigned int volume[6]{ 26,37,47,55,62,75 };
// 
// 
// Any modification to either one of these six array elements(be it an assignment, increment 
// or any other modification) will now be prevented by the compiler.
// 
// Array elements participate in arithmetic expressions like the other variables.You could sum 
// the first three elements of volume like this:
// 
// cpp
// //The sum of three elements
// unsigned int sum{};
// sum = volume[0] + volume[1] + volume[2];
// 
// 
// Understanding Loops.
// -------------------
// 
// A loop is a mechanism that enables you to execute a statement or a block of statements repeatedly 
// until a particular condition is met.Two essential elements make up a loop : the statement or block of 
// statements that is to be executed repeatedly forms the so - called body of the loop, and a* loop condition* 
// of some kind that determines when to stop repeating the loop.A single execution of the body's loop's body is called an * iteration * .
// 
// A loop condition can take different forms to provide different ways of controlling the loop.For example, 
// a loop condition can do the following :
// 
// -Execute a loop a given number of times.
// - Execute a loop until a given value exceeds another value.
// - Execute the loop until a particular character is entered from the keyboard.
// - Execute a loop for each element in a collection of elements.
// 
// The for loop.
// -----------
// 
// The for loop generally executes a statement or a block of statements a predetermined number of times,
// but you can use it in other ways too.You specify how a for loop operates using three expressions separated
// by semicolons between parentheses following the for keyword.

// 
// The initialization expression is evaluated only once, at the beginning of the loop. The loop condition
// is checked next, and if it is true, the loop statement or statement block executes. If the condition is
// false the loop ends, and execution continues with the statement after the loop. After each execution of
// the loop statement or block, the iteration expression is evaluated, and the condition is checked to
// decide whether the loop should continue.


#include<iostream>
#include<cmath>

double bondPV()
{
    // Compute the PV of a fixed rate bond
    double couponRate = 0.03;
    double notional = 1.0;
    double principal = 10000000;

    // Flat rate curve
    double Z[6] = { 0.05, 0.05, 0.05, 0.05, 0.05, 0.05 };
    double principalRepayment[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };
    const int yearsToMaturity = 6;

    double pv = 0;

    for (int i = 0; i < yearsToMaturity; ++i)
    {
        double df = 1.0 / powf((1 + Z[i]), i);
        pv += (df * couponRate * notional);
        pv += df * principalRepayment[i];
    }

    std::cout << "PV of the bond = " << pv;
    return pv;
}