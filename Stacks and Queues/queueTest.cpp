/*
	Q.	Implement queue.
*/

#include <iostream>
#include "queueUtility.h"

using namespace std;

int main()
{
	string menu = "1. Add\n2. Remove\n3. Peek\n4. Print\n5. Quit";

	Queue q;

	int item = 0; 	// Number from the menu

	while(item != 5){
		cout<<"Select one of the operation you want to perform"<<endl;
		cout<<menu<<endl;

		cin>>item;

		switch(item){
			case 1: 
				int value;
				cout<<"Enter value into queue"<<endl;
				cin>>value;
				q.add(value);
				break;

			case 2: q.remove(); break;

			case 3: 
				cout<< "========================================================"<<endl;
				cout<<"Peek value is "<<q.peek()<<endl;
				cout<< "========================================================"<<endl;
				break;

			case 4:	q.printQueue(); break;

			case 5:
				cout<<"Quitting"<<endl;
				break;
				
			default:
				cout<<"Wrong input, please input again"<<endl;

		}

	}
}