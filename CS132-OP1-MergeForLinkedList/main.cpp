// main.cpp 

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

/*

For this program you will be writing and testing a merge function. 
This function will be like the merge function that belongs to List in the STL, 
 in that it will only work if you are working with list that are already sorted. 
If you were to use the function like this: list1.merge( list2 ); 
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
