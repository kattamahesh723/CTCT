/*
	Q.	Write a program to use multiple stacks but should operate like a single stack.
*/

#include <iostream>
#include "stackUtility.h"

using namespace std;

Stack stacks[5];			// Declared globally
int stackIndex = 0;

void push(int item);
void pop();
void printStacks();

int main()
{
	string menu = "1. Push\n2. Pop\n3. Print\n4. Quit";

	int menuNumber = 0; 	// Number from the menu

	while(menuNumber != 4){

		cout<<"Select one of the operation you want to perform"<<endl;
		cout<< "========================================================"<<endl;
		cout<<menu<<endl;

		cin>>menuNumber;

		switch(menuNumber){

			case 1: 
				cout<<"Enter element into stack"<<endl;
				int item;
				cin>>item;
				push(item);
				break;

			case 2:
				pop();
				break;

			case 3:
				printStacks();
				break;

			case 4:
				cout<< "Quitting" <<endl;
				break;

			default:
				break;

		}

	}

}

void push(int item){
	if(stacks[stackIndex].isFull() && stackIndex != 4){
		stackIndex++;
	}
	if(stackIndex < 5)
		stacks[stackIndex].push(item);
	
	
}

void pop(){
	stacks[stackIndex].pop();
	if(stacks[stackIndex].isEmpty())			// Check if after poping element stack has become empty
		stackIndex--;
}

void printStacks(){	
	cout<<"Stack elements"<<endl;
	cout<< "========================================================"<<endl;
	for(int ind = 0; ind < 5; ind++){
		cout<<ind+1<<": ";
		stacks[ind].printStack();
	}
	cout<< "========================================================"<<endl;
}









