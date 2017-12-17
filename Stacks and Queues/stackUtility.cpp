#include "stackUtility.h"
#include <limits>

Stack::Stack(){
	top = NULL;
	minimum = numeric_limits<int>::max();
	capacity = 0;
}

void Stack::push(int item){
	if(isFull()){
		cout<< "Stack is full, no insertions are allowed" << endl;
	}
	else if(top){		// If top is not null then add element above the recent top, inserting infront of the head node
		//cout<<"not first item"<<endl;
		node *newNode = new node;
		newNode->data = item;
		newNode->next = top;
		minimum = min(minimum, item);
		top = newNode;
		top->minimum = minimum;
		capacity++;
	}
	else{			// Else create top of the stack
		top = new node;
		//cout<<"First item"<<endl;
		top->data = item;
		top->minimum = item;
		minimum = item;
		top->next = NULL;
		capacity++;
	}
}

void Stack::pop(){
	if(isEmpty()){
		cout << "Stack is empty, pop operation is not valid"<<endl;
	}	
	else{
		node *newNode = top;
		top = top->next;
		if(top)
			minimum = top->minimum;
		free(newNode);
		capacity--;
	}
}

int Stack::peek(){
	if(isEmpty()){
		cout << "Stack is empty, no top element"<<endl;
	}
	else{
		return top->data;
	}
	return 0;
}

bool Stack::isEmpty(){
	if(!top)
		return true;
	return false;
}

bool Stack::isFull(){
	if(capacity == 10)			// Size of the stack is restricted to 10 here for simplicity
		return true;
	return false;
}

int Stack::minValue(){
	return minimum;
}

void Stack::printStack(){
	// cout<< "Stack elements so far:"<<endl;
	// cout<< "========================================================"<<endl;
	node *current = top;

	while(current){
		//cout<<"here"<<endl;
		cout << current->data << "->";
		current = current->next;
	}
	cout<<"NULL"<<endl;
	// cout<< "========================================================"<<endl;

	// cout<< "========================================================"<<endl;
	// current = top;

	// while(current){
	// 	//cout<<"here"<<endl;
	// 	cout << current->minimum << "->";
	// 	current = current->next;
	// }
	// cout<<"NULL"<<endl;
	// cout<< "========================================================"<<endl;
}