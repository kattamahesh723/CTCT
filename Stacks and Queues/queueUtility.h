#include <iostream>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

struct node{
	int data;
	node *next;
};

class Queue{

private:
	node *top, *tail;			// top points to first item of the queue, tail points to the last recent added item

public:
	Queue();					// Default constructor
	void add(int item);			// Adding item into queue
	void remove();				// Removes the first item in the queue
	int peek();					// Returns the top item in the queue
	bool isEmpty();				// Checks if queue is empty
	void printQueue();			// Prints to stdout the current queue items
};

#endif