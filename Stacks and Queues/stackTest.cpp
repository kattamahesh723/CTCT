/*
	Q.	Implement a stack data structure.
*/

#include<iostream>
#include "stackUtility.h"
#include <string>


using namespace  std;

int main()
{
	//cout<<"Menu of operations performed on Stack"<<endl;
	string menu = "1. Push\n2. Pop\n3. Peek\n4. Print\n5.Minimum Value\n6. Quit";


	Stack s;

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

			case 5: cout<<"Minimum value is "<<s.minValue()<<endl; break;
			case 6:
				cout<<"Quitting"<<endl;
				break;
				
			default:
				cout<<"Wrong input, please input again"<<endl;
				break;

		}

	}

}