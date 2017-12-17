/*
	Q.	Sort stack, can use at most one extra stack. Can not use any other data structure.
*/

#include <iostream>
#include "stackUtility.h"

using namespace std;

Stack sortedStack;
Stack s;			// Temporary stack in which items are stacked into from stdin

void sortStack();

int main()
{
	string menu = "1. Push\n2. Pop\n3. Peek\n4. Print\n5. Sort\n6. Quit";


	int item = 0; 	// Number from the menu

	while(item != 6){
		cout<<"Select one of the operation you want to perform"<<endl;
		cout<< "========================================================"<<endl;
		cout<<menu<<endl;

		cin>>item;

		switch(item){
			case 1: 
				int value;
				cout<<"Enter value into stack"<<endl;
				cin>>value;
				s.push(value);
				break;

			case 2: s.pop(); break;

			case 3: 
				cout<< "========================================================"<<endl;
				cout<<"Peek value is "<<s.peek()<<endl;
				cout<< "========================================================"<<endl;
				break;

			case 4:	s.printStack(); break;

			case 5: 
				sortStack();
				cout<< "After sorting stack looks like"<<endl;
				sortedStack.printStack();
				break;
			case 6:
				cout<<"Quitting"<<endl;
				break;
				
			default:
				cout<<"Wrong input, please input again"<<endl;
				break;

		}

	}
}


void sortStack(){

	if(sortedStack.isEmpty()){
		sortedStack.push(s.peek());
		s.pop();
	}
	
	// Do this till temp is emptied.
	cout<<"Here"<<endl;
	while(!s.isEmpty()){
		int currTop = s.peek();
		s.pop();
		// Iterate till position for currTop is found in the sorted stack
		while(!sortedStack.isEmpty() && currTop > sortedStack.peek()){		
			s.push(sortedStack.peek());
			sortedStack.pop();
		}

		// Right position for currTop is found, then insert it into that position
		sortedStack.push(currTop);
	}
		
	
}













