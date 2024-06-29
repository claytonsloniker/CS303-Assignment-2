#pragma once

#include <iostream>

using namespace std;

struct Node {
	int itemNum;
	Node* nextPtr;
};

class LinkedList {
private:
	Node* headPtr;
	Node* tailPtr;
	int numItems;
public:
	LinkedList();
	~LinkedList();
	void loadList(LinkedList& l);
	void push_front(int d);
	void push_back(int d);
	void pop_front();
	void pop_back();
	int front();
	int back();
	bool empty() { return headPtr == nullptr; }
	void insert(int index, const int& item);
	bool remove(int index);
	int find(const int& item);
	void printList();
};