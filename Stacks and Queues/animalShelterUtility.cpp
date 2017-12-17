#include "animalShelterUtility.h"

Queue::Queue(){
	top = NULL;
	tail = NULL;
}

void Queue::add(string item){
	if(isEmpty()){
		top = new node;
		tail = new node;
		top->data = item;
		top->time_stamp = time(NULL);
		top->next = NULL;
		tail = top;
	}
	else{
		node *newNode = new node;
		newNode->data = item;
		newNode->time_stamp = time(NULL);
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
}

void Queue::remove(){
	if(isEmpty()){
		cout<< "Empty queue, not possible to remove item from the queue"<<endl;
	}
	else{
		node *newNode = top;
		top = top->next;
		free(newNode);
	}
}

node* Queue::peek(){
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	else
		return top;

	return NULL;
}

bool Queue::isEmpty(){
	if(!top)
		return true;
	return false;
}

void Queue::printQueue(){
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	else{
		node *current = top;
		cout<<"=========================================================="<<endl;
		while(current){
			cout<<current->data<<"->";
			current = current->next;
		}
		cout<<"NULL"<<endl;
		cout<<"=========================================================="<<endl;
	}
}