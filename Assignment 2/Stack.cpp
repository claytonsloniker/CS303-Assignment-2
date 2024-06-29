#include "Stack.h"

Stack::Stack() {
	StackSize = 0;
}

bool Stack::empty() {
	return StackVector.empty();
}

void Stack::push(const int& item) {
	StackVector.push_back(item);
	cout << "Pushed " << item << " to stack" << endl;
	StackSize++;
}

void Stack::pop() {
	StackVector.pop_back();
	cout << "Popped from stack" << endl;
	StackSize--;
}

int Stack::top() {
	return StackVector.back();
}

int Stack::average() {
	int sum = 0;
	while (!StackVector.empty()) {
		sum += StackVector.back();
		StackVector.pop_back();
	}
	return sum / StackSize;
}

void Stack::printStack() {
	// Added to visualize the stack works
	for (auto i : StackVector) {
		cout << i << " ";
	}
	cout << "\n\n";
}