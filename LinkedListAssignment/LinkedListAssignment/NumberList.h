// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
	// Declare a structure for the list
	struct ListNode {
		double value;           // The value in this node
		struct ListNode *next;  // To point to the next node
	};

	//struct ListNode(double num, )

	ListNode *head;       // List head pointer
	ListNode *tail;

public:
	// Constructor
	NumberList() {
		head = nullptr;
	}

	// Destructor
	~NumberList();

	// Linked list operations
	void appendNode(double);
	void insertNode(double); //enter in terms of order of numbers least to greatest
	void insertNodeAt(int, double);
	void deleteNode(double);
	void displayList() const;

	NumberList(NumberList const *list);

	bool empty() const;
	int size() const;
	int count(double) const;
	int erase(double);
	ListNode *begin() const;
	ListNode *end() const;
	double front() const;

	void push_front(double);
	void push_back(double);
	double pop_front();

	void insertionSort();
};
#endif