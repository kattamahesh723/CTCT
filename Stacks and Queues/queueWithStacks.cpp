/*
	Q.	Implement queue using two stacks.
*/

#include <iostream>
#include "stackUtility.h"
#include <string>

Stack stackNew;
Stack stackOld;

void enQueue(int item);
void deQueue();
int peek();
bool isEmpty();
void shiftStacks();
void printQueue();

int main()
{
	string menu = "1. EnQueue\n2. DeQueue\n3. Print\n4. Quit";

	
	int menuNumber = 0; 
	while(menuNumber != 4){
		cout<<"Select one of the options from below menu to operate on the queue"<<endl;
		cout<<"================================================"<<endl;
		cout<<menu<<endl;

		cin>>menuNumber;
		switch(menuNumber){
			case 1: 
				int item;
				cout<<"Enter value to enqueue into queue"<<endl;
				cin>>item;
				enQueue(item);
				break;

			case 2:
				if(peek())
					cout<<"The value "<<peek()<<" is removed from queue"<<endl;
				deQueue();
				break;

			case 3:
				printQueue();
				break;

			case 4:
				cout<<"Quitting"<<endl;
				break;

			default:
				break;
		}
	}
}

void enQueue(int item){
	stackNew.push(item);
}

void deQueue(){
	shiftStacks();
	stackOld.pop();
}

int peek(){
	shiftStacks();
	return stackOld.peek();
}

bool isEmpty(){
	return stackOld.isEmpty() && stackOld.isEmpty();
}

void shiftStacks(){
	if(stackOld.isEmpty()){
		while(!stackNew.isEmpty()){
			int topItem = stackNew.peek();
			// cout<<"Item: "<<topItem<<endl;
			stackNew.printStack();
			stackNew.pop();
			stackOld.push(topItem);
		}
	}
}

void printQueue(){

	cout<<"Elements in the Queue so far"<<endl;
	cout<<"================================================"<<endl;
	stackOld.printStack();
	stackNew.printStack();
	cout<<"================================================"<<endl;
}