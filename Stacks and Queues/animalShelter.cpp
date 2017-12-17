/*
	Q.	An animal shelter which holds only dogs and cats, operates on a strictly "first in, first out" basis.
		People must adopt either the "oldest" (based on time of arrival) of all animals at the shelter, or they
		can select whether they would prefer a dog or a cat (and will receive the oldest of that type). They can
		not select which specific animal they want. Create a data structre to maintain these operations such as
		enQueue, deQueueAny, deQueueDog, deQueueCat.
*/
#include <iostream>
#include <time.h>
#include "animalShelterUtility.h"

using namespace std;

Queue dog, cat;

string popAnimal();
string popDog();
string popCat();
void printQueues();

int main()
{
	string menu = "1. AddDog\n2. AddCat\n3. PopDog\n4. PopCat\n5. Print\n6. PopAnimal\n7. Quit";


	int item = 0; 	// Number from the menu

	while(item != 7){
		cout<<"Select one of the operation you want to perform"<<endl;
		cout<<menu<<endl;

		cin>>item;
		string value;

		switch(item){
			case 1: 
				cout<<"Enter dog name into dog queue"<<endl;
				cin>>value;
				dog.add(value);
				break;
			case 2:
				cout<<"Enter cat name into cat queue"<<endl;
				cin>>value;
				cat.add(value);
				break;

			case 3: popDog(); break;

			case 4:	popCat(); break;

			case 5: printQueues(); break;

			case 6: popAnimal(); break;
			case 7:
				cout<<"Quitting"<<endl;
				break;
				
			default:
				cout<<"Wrong input, please input again"<<endl;

		}

	}

}

string popDog(){
	node *dogName = dog.peek();
	dog.remove();
	return dogName->data;
}

string popCat(){
	node *catName = cat.peek();
	cat.remove();
	return catName->data;
}

string popAnimal(){
	node *dogName = dog.peek();
	node *catName = cat.peek();

	if(dogName->time_stamp < catName->time_stamp){
		dog.remove();
		return dogName->data;
	}
	else{
		cat.remove();
		return catName->data;
	}
}

void printQueues(){
	dog.printQueue();
	cat.printQueue();
}