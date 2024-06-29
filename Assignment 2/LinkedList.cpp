#include "LinkedList.h"

LinkedList::LinkedList() {
	headPtr = nullptr;
	tailPtr = nullptr;
	numItems = 0;
}

LinkedList::~LinkedList() {
	Node* temp = headPtr;
	while (temp != nullptr) {
		Node* next = temp->nextPtr;
		delete temp;
		temp = next;
	}
	headPtr = nullptr;
	tailPtr = nullptr;
}

void LinkedList::loadList(LinkedList& l) {
	// Load list with 0-9
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
}

void LinkedList::push_front(int d) {
	Node* tempPtr = new Node;
	tempPtr->itemNum = d;
	tempPtr->nextPtr = nullptr;

	// Check if head is empty
	if (headPtr == nullptr) {
		headPtr = tempPtr;
		tailPtr = tempPtr;
	}
	else {
		tempPtr->nextPtr = headPtr;
		headPtr = tempPtr;
	}
	cout << "Pushed " << d << " to front" << endl;
	numItems++;
}

void LinkedList::push_back(int d) {
	Node* tempPtr = new Node;
	tempPtr->itemNum = d;
	tempPtr->nextPtr = nullptr;

	// Check if head is empty
	if (headPtr == nullptr) {
		headPtr = tempPtr;
		tailPtr = tempPtr;
	}
	else {
		tailPtr->nextPtr = tempPtr;
		tailPtr = tempPtr;
	}
	cout << "Pushed " << d << " to back" << endl;
	numItems++;
}

void LinkedList::pop_front() {
	if (headPtr == nullptr) {
		cout << "List is empty" << endl;
	}
	else {
		Node* tempPtr = headPtr;
		headPtr = headPtr->nextPtr;
		delete tempPtr;
	}
	cout << "Popped front" << endl;
	numItems--;
}

void LinkedList::pop_back() {
	if (headPtr == nullptr) {
		cout << "List is empty" << endl;
	}
	else {
		Node* tempPtr = headPtr;
		Node* prevPtr = nullptr;

		// Iterate to end of list
		while (tempPtr->nextPtr != nullptr) {
			prevPtr = tempPtr;
			tempPtr = tempPtr->nextPtr;
		}
		// Check if only one item in list
		if (prevPtr == nullptr) {
			headPtr = nullptr;
			tailPtr = nullptr;
		}
		// Check if more than one item in list
		else {
			prevPtr->nextPtr = nullptr;
			tailPtr = prevPtr;
		}
		delete tempPtr;
	}
	cout << "Popped back" << endl;
	numItems--;
}

int LinkedList::front() {
	if (headPtr == nullptr) {
		cout << "List is empty" << endl;
		return -1;
	}
	else {
		return headPtr->itemNum;
	}
}

int LinkedList::back() {
	if (headPtr == nullptr) {
		cout << "List is empty" << endl;
		return -1;
	}
	else {
		return tailPtr->itemNum;
	}
}

void LinkedList::insert(int index, const int& item) {
	Node* tempPtr = new Node;
	tempPtr->itemNum = item;
	tempPtr->nextPtr = nullptr;

	// Check if head is empty
	if (headPtr == nullptr) {
		headPtr = tempPtr;
		tailPtr = tempPtr;
	}
	else {
		Node* temp = headPtr;
		Node* prev = nullptr;
		int i = 0;

		// Iterate to index
		while (temp != nullptr && i < index) {
			prev = temp;
			temp = temp->nextPtr;
			i++;
		}
		// Check if index is at head
		if (prev == nullptr) {
			tempPtr->nextPtr = headPtr;
			headPtr = tempPtr;
		}
		// Check if index is at tail
		else if (temp == nullptr) {
			tailPtr->nextPtr = tempPtr;
			tailPtr = tempPtr;
		}
		// Check if index is in middle
		else {
			prev->nextPtr = tempPtr;
			tempPtr->nextPtr = temp;
		}
	}
	cout << "Inserted " << item << " at index " << index << endl;
	numItems++;
}

bool LinkedList::remove(int index) {
	if (headPtr == nullptr) {
		cout << "List is empty" << endl;
		return false;
	}
	else {
		Node* temp = headPtr;
		Node* prev = nullptr;
		int i = 0;

		// Iterate to index
		while (temp != nullptr && i < index) {
			prev = temp;
			temp = temp->nextPtr;
			i++;
		}
		// Check if index is beyond the end of the list
		if (temp == nullptr) {
			cout << "Index is beyond the end of the list" << endl;
			return false;
		}
		// Check if index is at head
		if (prev == nullptr) {
			headPtr = headPtr->nextPtr;
			delete temp;
		}
		// Check if index is at tail
		else if (temp->nextPtr == nullptr) {
			prev->nextPtr = nullptr;
			tailPtr = prev;
			delete temp;
		}
		// Check if index is in middle
		else {
			prev->nextPtr = temp->nextPtr;
			delete temp;
		}
		numItems--;
		return true;
	}
}

int LinkedList::find(const int& item) {
	// Return the position of the first occurrence of item if it is found.Return the size of the list if it is not found.
	if (headPtr == nullptr) {
		cout << "List is empty" << endl;
		return -1;
	}
	else {
		Node* temp = headPtr;
		int i = 0;

		// Iterate through list
		while (temp != nullptr) {
			if (temp->itemNum == item) {
				return i;
			}
			temp = temp->nextPtr;
			i++;
		}
		return numItems;
	}
}

void LinkedList::printList() {
	Node* temp = headPtr;
	while (temp != nullptr) {
		cout << temp->itemNum << " ";
		temp = temp->nextPtr;
	}
	cout << endl;
	cout << "Number of items: " << numItems << "\n\n";
}