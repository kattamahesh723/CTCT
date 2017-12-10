#include<iostream>
#include "LinkedListUtility.h"

using namespace std;


void printList(node *head)
{
	node *current = head;
	while(current)
	{
		cout<<current->data<<"->";
		current = current->next;
	}

	cout<<"NULL"<<endl;
	cout<<endl;
}

void createLinkedList(node *head, int N)
{
	//cout<<"Enter elements into linked list"<<endl;
	cin>>head->data;
	head->next = NULL;
	int value;
	node *current = head;

	for(int i=1; i<N; i++){
		cin>>value;
		node *newNode = new node;
		newNode->data = value;
		newNode->next = NULL;
		current->next = newNode;
		current = newNode;
	}
}

void reverseLinkedList(node **L1){
	node *head = *L1;
	if(head){
		if(head->next){
			node *prev = NULL;
			node *nextNode = NULL;
			while(head->next){
				nextNode = head->next;
				head->next = prev;
				prev = head;
				head = nextNode;
			}
			head->next = prev;
		}
	}
	*L1 = head;
}

void copyLinkedList(node *oldList, node **newList){
	if(oldList == NULL){
		cout<<"Empty list passed, no elements to copy"<<endl;
		*newList = NULL;
	}
	else{
		node *P = oldList;		// To iterate through oldList
		node *Q = NULL;			// To iterate through newList

		while(P){
			node *newNode = new node;
			newNode->data = P->data;
			newNode->next = NULL;

			if(!Q){
				Q = newNode;
				*newList = Q;
			}
			else{
				Q->next = newNode;
				Q = Q->next;
			}
			P = P->next;
		}
	}
}

int LinkedListLength(node *head){
	int length = 0;

	node *current = head;

	while(current){
		length++;
		current = current->next;
	}

	return length;
}

