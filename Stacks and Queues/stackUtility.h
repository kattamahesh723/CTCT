
#include<iostream>

using namespace std;

#ifndef	STACK_H
#define	STACK_H

struct  node
{	
	int data;				// Stores the value of that node
	node *next;				// Pointer to next node
	int minimum;			// Keeps min value till that node
};

class Stack{

private:
	node *top;
	int minimum;			// Has the current minimu value 
	int capacity;			// Maximum capacity of stack

public:
	Stack();				// Initialize stack
	void pop();				// Remove the top item from the stack
	void push(int item);	// Add an item to the top of the stack
	int peek();				// Retrun the top item of the stack
	bool isEmpty();			// Return true if stack is empty
	bool isFull();			// Return true if stack is full
	void printStack();		// Prints current stack onto stdout
	int minValue();			// Returns minimum value
};

#endif