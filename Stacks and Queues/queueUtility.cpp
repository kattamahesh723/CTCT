#include "queueUtility.h"

Queue::Queue(){
	top = NULL;
	tail = NULL;
}

void Queue::add(int item){
	if(isEmpty()){
		top = new node;
		tail = new node;
		top->data = item;
		top->next = NULL;
		tail = top;
	}
	else{
		node *newNode = new node;
		newNode->data = item;
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

int Queue::peek(){
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	else
		return top->data;

	return -1;
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