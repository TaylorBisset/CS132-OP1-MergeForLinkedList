// main.cpp

/*
Name:           Taylor Bisset
Section:        A
Program Name:   CS132-OP1-MergeForLinkedList

Description:    This program implements and tests a merge function for a sorted linked list. 
				It merge two sorted lists, is as few moves as possible. 

Repo:           https://github.com/TaylorBisset/CS132-OP1-MergeForLinkedList

*/

#include <iostream>
#include <iomanip>

#include "LkList.h"
// #include "stdafx.h"

using namespace std;

int main()
{
	LkList list, list2;

	//------------------------

	list.insert( { 0, 10, 20, 30, 40} );
	list2.insert( { 1, 2, 3, 5, 11, 12, 13, 26, 27, 28, 29, 34, 35, 36, 37, 44, 45, 46, 47} );
	
	list.merge(list2);
	
	cout << "Merge #1 (source overlaps destination): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	
	list.clear();
	list2.clear();

	//------------------------

	list.merge(list2);
	
	cout << "Merge #2 (empty merge): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;

	list.clear();
	list2.clear();
	
	//------------------------

	list2.insert( { 0, 10, 20, 30, 40 } );

	list.merge(list2);

	cout << "Merge #3 (into an empty list): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;

	list.clear();
	list2.clear();
	
	//------------------------
	
	list.insert( { 0, 5, 10, 15, 20, 25, 30, 35, 40} );
	
	
	list.merge(list2);
	
	cout << "Merge #4 (from an empty list): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	
	list.clear();
	list2.clear();
	
	//------------------------

	list.insert( { 40, 47, 54, 61, 68 } );
	
	list2.insert( { 0, 3, 6, 9, 12, 15, 18 } );


	list.merge(list2);

	cout << "Merge #5 (source before destination): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	
	list.clear();
	list2.clear();
	
	//------------------------

	list.insert( { 10, 17, 21, 28 } );
	
	list2.insert( { 50, 53, 56, 59, 62, 65 } );	
	
	list.merge(list2);
	
	cout << "Merge #6 (source after destination): \n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	
	list.clear();
	list2.clear();
	
	//------------------------

	list.insert( { 0, 9, 18, 27 } );
	
	list2.insert( { -6, -4, -2, 0, 2, 4, 6, 8, 10, 12, 16, 
	                 18, 20, 22, 24, 26, 28, 30, 32, 34 } );	
	
	list.merge( list2 );
	
	cout << "Merge #7 (source overlaps destination):\n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	
	list.clear();
	list2.clear();
	
	//------------------------

	list.insert( { -6, 2, 10, 18, 26, 34 } );
	
	list2.insert( { 10, 13, 16, 19, 22, 25 } );	
	
	list.merge( list2 );
	
	cout << "Merge #8 (source within destination):\n" << list << endl;
	cout << "List size after merge: " << list.size() << endl;
	cout << endl << endl;
	
	list.clear();
	list2.clear();

	//------------------------

	system("pause");
	return 0;
}

/*
OUTPUT:

Merge #1 (source overlaps destination):
0  1  2  3  5  10  11  12  13  20  26  27  28  29  30  34  35  36  37  40  44  45  46  47
List size after merge: 5


Merge #2 (empty merge):

List size after merge: 0


Merge #3 (into an empty list):
0  10  20  30  40
List size after merge: 0


Merge #4 (from an empty list):
0  5  10  15  20  25  30  35  40
List size after merge: 9


Merge #5 (source before destination):
0  3  6  9  12  15  18  40  47  54  61  68
List size after merge: 5


Merge #6 (source after destination):
10  17  21  28  50  53  56  59  62  65
List size after merge: 4


Merge #7 (source overlaps destination):
-6  -4  -2  0  0  2  4  6  8  9  10  12  16  18  18  20  22  24  26  27  28  30  32  34
List size after merge: 4


Merge #8 (source within destination):
-6  2  10  10  13  16  18  19  22  25  26  34
List size after merge: 6


Press any key to continue . . .

*/

/*

For this program you will be writing and testing a merge function. 
This function will be like the merge function that belongs to List in the STL, 
 in that it will only work if you are working with list that are already sorted. 
If you were to use the function like this: `list1.merge( list2 );` 
 then all of the data from list2 would be moved into list1 in the correct places. 
After the merge is completed list2 should be an empty List that can be used again 
 (in the main, I call the clear function for list2, but this should not be needed).

Note: in the merge, you must move as many nodes as possible with each "move"...
 meaning you can't just call insert or manually move one node at a time 
 unless one node is all that needs to be moved with that move.

Note 2:  For this lab, duplicate values are allowed in the lists

Project Hint 1: Compile and run the given file after you download them and 
 and add/copy them a Visual Studio project to make sure it will work before you start to change things.

I would really encourage you to use the debugger to examine data during run time and follow the execution of your code.

Project Hint 2: If you take care of the special cases like moving all the node that go before or after the target list, 
 it will then make it easier to move the nodes that will go within the middle of the target list.

For turn in you need to turn in the code for the merge function and the output from main when you have all 8 test uncommented.  
Put a normal program header before the print out of your merge function.

*/
