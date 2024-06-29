// ASSIGNMENT 2
// Name: Clayton Sloniker

#include "LinkedList.h"
#include "Stack.h"

int main()
{
	LinkedList list;

	cout << string(10, '-') << "Linked List" << string(10, '-') << "\n\n";

	// Test push_back
	list.loadList(list);
	list.printList();

	// Test pop_front and pop_back
	list.pop_front();
	list.pop_back();
	list.printList();

	// Test front and back
	cout << "Front: " << list.front() << endl;
	cout << "Back: " << list.back() << endl;
	cout << endl;

	// Test empty
	cout << "Is Empty? (0 if empty, 1 if no): " << list.empty() << "\n\n";

	// Test insert
	list.insert(5, 100);
	list.printList();

	// Test remove
	cout << "Removed? (0 if failed, 1 if successful): " << list.remove(5) << endl;
	list.printList();

	// Test find
	cout << "Index: " << list.find(5) << "\n\n";


	// Vector as Stack

	Stack stack;

	cout << string(10, '-') << "Vector as Stack" << string(10, '-') << "\n\n";

	// Test push
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.printStack();

	// Test pop
	stack.pop();
	stack.printStack();

	// Test empty
	cout << "Is Empty? (0 if empty, 1 if no): " << stack.empty() << "\n\n";

	// Test top
	cout << "Top Value: " << stack.top() << "\n\n";

	// Test average
	cout << "Average Value: " << stack.average() << endl;


}
