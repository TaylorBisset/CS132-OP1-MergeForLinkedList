// LkList.cpp

#include <iostream>
#include "LkList.h"
// #include "stdafx.h"

using namespace std;

void LkList::merge(LkList& src)
{
	/*
	
	if (list1.at(0) < list2.at(0))
	{
		sift through list2 until list1.at(i) == list2.at(i);
		use insert for temp list? 
		merge those numbers into list1 after list1.at(0); maybe using another insert?


		Check if either list is empty
		If current list is empty, copy the source list
		If source list is empty, do nothing
			early terminate

		Initialize iterators for both lists
			head and src.head

		Handle the first element
		Iterate through both lists
		If the next element in the current list is larger, insert the source element before it
			Move to the next element in the current list

		If there are remaining elements in the source list, append them to the current list

		Update the source list
	}
	
	*/
}  // end of merge function

LkList::LkList()
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}

//LkList::~LkList(){}                      
//LkList::LkList(const LkList& other){}
//LkList& LkList::operator=(const LkList& rhs){}

int LkList::size()
{
	return count;
}

bool LkList::insert(int num)
{
	if (count == 0)
	{                      // empty list
		head = tail = new Node(num);
	}
	else
	{                                   // >1 count, then add back
		Node* temp = new Node(num);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	count++;
	return true;
}

void LkList::insert(const initializer_list<int>& il)
{
	for (int ele : il)
	{
		insert(ele);
	}
}

void LkList::clear()
{
	if (count == 0)
	{
		return;
	}

	while (tail != head)
	{
		tail = tail->prev;
		delete tail->next;
	}
	delete head;
	head = tail = nullptr;
	count = 0;
}

void LkList::resetIterator()
{
	it = head;
}

bool LkList::hasMore()
{
	return (it != nullptr);
}

int LkList::next()
{
	int num = it->data;
	it = it->next;
	return num;
}

ostream& operator << (ostream& outStr, LkList& lst)
{
	lst.resetIterator();
	while (lst.hasMore())
		outStr << lst.next() << "  ";
	return outStr;
}
