#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
	int StackSize;
	vector<int> StackVector;
public:
	Stack();
	bool empty();
	void push(const int& item);
	void pop();
	int top();
	int average();
	void printStack();
};
