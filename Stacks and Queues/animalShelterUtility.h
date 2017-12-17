#include <iostream>
#include <time.h>
#include <string>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

struct node{
	string data;
	time_t time_stamp;
	node *next;
};

class Queue{

private:
	node *top, *tail;			// top points to first item of the queue, tail points to the last recent added item

public:
	Queue();					// Default constructor
	void add(string item);			// Adding item into queue
	void remove();				// Removes the first item in the queue
	node* peek();					// Returns the top item in the queue
	bool isEmpty();				// Checks if queue is empty
	void printQueue();			// Prints to stdout the current queue items
};

#endif