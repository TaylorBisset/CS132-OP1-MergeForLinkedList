// LkList.cpp

#include <iostream>
#include "LkList.h"
// #include "stdafx.h"

using namespace std;

void LkList::merge(LkList& src)
{
	// early termination
	if (head == nullptr) 
	{
		// If current list is empty, copy the source list
		head = src.head;
		tail = src.tail;
		src.head = src.tail = nullptr;  // Clear the source list
		return;
	}
	// early termination
	if (src.head == nullptr) 
	{
		// Source list is empty, do nothing
		return;
	}
	// initialize lists
	Node* curr = head;
	Node* srcCurr = src.head;

	// First element
	if (srcCurr->data < curr->data) 
	{
		// Insert the source element before the current element
		src.head = srcCurr->next;
		srcCurr->next = curr;
		head = srcCurr;
		curr = srcCurr;
		srcCurr = src.head;
	}
	// Iterate through lists
	while (curr->next != nullptr && srcCurr != nullptr)
	{
		// check if source is less than next var in current list
		if (srcCurr->data < curr->next->data) 
		{
			// insert source before next in current list
			src.head = srcCurr->next;
			srcCurr->next = curr->next;
			curr->next = srcCurr;
			curr = srcCurr;
			srcCurr = src.head;
		}
		else
		{
			// Move to next elements
			curr = curr->next;
		}
	}
	// Handle remaining elements
	if (srcCurr != nullptr)
	{
		curr->next = srcCurr;
		tail = src.tail;
	}
	// clear source list
	src.head = src.tail = nullptr;
}  // end of merge function

LkList::LkList()
{
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}

LkList::~LkList()
{
	clear();
}

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
	Node* current = head;			// Set temp pointer `current`

	while (current != nullptr)		// Iterate through current list 
	{
		Node* next = current->next;	// Set temp pointer `next`
		delete current;				// Delete current node to free memory
		current = next;				// Move to next node
	}

	head = tail = it = nullptr;		// Update all to nullptr after deleting nodes
	count = 0;						// Reset count in list to 0
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
