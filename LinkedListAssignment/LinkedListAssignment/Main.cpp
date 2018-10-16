#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Numberlist.h"

using namespace std;

int main() {
	NumberList listOfNumbers;

	listOfNumbers.appendNode(5);
	listOfNumbers.appendNode(3);
	listOfNumbers.appendNode(12);
	listOfNumbers.appendNode(6);
	listOfNumbers.appendNode(9);
	listOfNumbers.appendNode(23);
	listOfNumbers.appendNode(1);
	listOfNumbers.insertionSort();

	listOfNumbers.displayList();

	return 0;
}