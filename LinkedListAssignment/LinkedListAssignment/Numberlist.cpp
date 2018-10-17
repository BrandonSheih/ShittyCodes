// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"

using namespace std;

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void NumberList::appendNode(double num) {
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list

						// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else { // Otherwise, insert newNode at end.
		   // Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void NumberList::displayList() const {
	ListNode *loc = head;

	while (loc) {
		cout << loc->value << " ";
		loc = loc->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void NumberList::insertNode(double num) {
	ListNode *newNode;					// A new node
	ListNode *nodePtr;					// To traverse the list
	ListNode *previousNode = nullptr;	// The previous node

										// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head || head->value > num) {
		newNode->next = head;
		head = newNode;
	}
	else { // Otherwise, insert newNode
		   // Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->value < num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		previousNode->next = newNode;
		newNode->next = nodePtr;
	}
}

void NumberList::insertNodeAt(int index, double num) {
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = num;

	if (!head || !index) {
		newNode->next = head;
		head = newNode;
	}

	else {
		nodePtr = head;

		previousNode = nullptr;

		for (int i = 0; nodePtr && i < index; i++) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		previousNode->next = newNode;
		newNode->next = nodePtr;
	}
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void NumberList::deleteNode(double num) {
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

							 // If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

bool NumberList::empty() const {
	return !head;
}

int NumberList::size() const {
	int size = 0;
	for (ListNode *nodePtr = begin(); nodePtr != end(); nodePtr = nodePtr->next, size++);
	return size;
}

int NumberList::count(double num) const {
	int count = 0;

	for (ListNode *ptr = begin(); ptr != end(); ptr = ptr->next) {
		count += (ptr->value == num);
	}
	return count;
}

/*int NumberList::erase(double num) {
	//finish
}*/

/*
void reverse(NumberList &list) {
NumberList temp;

while(!list.empty()){
temp.push_front(list.pop_front());
}
}
*/
/*
NumberList::NumberList(NumberList const &list) :head(nullptr) {
	
	//bad code because every time you copy one item you go through the entire list everytime

	for (ListNode *ptr = list.begin(); ptr != list.end(); ptr = ptr->next) {
		push_back(ptr->value);
	}
}*/

NumberList::ListNode *NumberList::begin() const {
	return head;
}

NumberList::ListNode *NumberList::end() const {
	return nullptr;
}

double NumberList::front() const {
	if (empty()) {
		//throw underflow();
	}

	return begin()->value;
}

void push_front(double num) {
	
}
/*
void NumberList::push_front(double num) {
	head = new ListNode(num, begin());
}*/

void NumberList::push_back(double num) {

}

double NumberList::pop_front() {
	if (empty()) {
		//throw underflow();
	}

	int e = front();
	ListNode *nodePtr = begin();
	head = begin()->next;
	delete nodePtr;
	return e;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

NumberList::~NumberList() {
	/*ListNode *current = head;
	ListNode *next;

	while (current) {
	next = current->next;
	delete current;
	current = next;
	}*/

	while (!empty()) {
		pop_front();
	}
}

//checks for out of bounds
class underflow {

};

//insertionSort
void NumberList::insertionSort() {
    ListNode *currentNode = head->next;
    ListNode *currentNodePrev = head;
    ListNode *compareNode = head;


    for (int i = 1; i < size() && currentNode->value; ++i) {

        if (currentNodePrev->value <= currentNode->value) { //skip sorted part of list
            currentNode = currentNode->next;
            currentNodePrev = currentNodePrev->next;
        }
        else {
           
            //when the current needs to be moved to the head
            if (head->value > currentNode->value) {
                currentNodePrev->next = currentNode->next;
                currentNode->next = head;
                head = currentNode;
            }

            else {
                //search for point to switch to
                for (compareNode = head; 
                     compareNode->next != nullptr && compareNode->next->value < currentNode->value; 
                     compareNode = compareNode->next);
                
                //update currentnode to next
                currentNodePrev->next = currentNode->next;
                currentNode->next = compareNode->next;
                compareNode->next = currentNode;
            }
        }

        currentNode = currentNodePrev->next;//continue.
    }
}

