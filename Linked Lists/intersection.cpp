/*
	Q.  Given two linked lists, determine if the two lists intersect. Return the intersecting node. Note that
		the intersection is defined based on reference, not value. That is, if the kth node of the first list
		is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
*/

#include<iostream>
#include "LinkedListUtility.h"

using namespace std;

void createIntersectionLL(node **L1, node **L2);
void createNode(node *current, int value);
node* intersectingNode(node *L1, node *L2);

int main()
{
	node *L1 = new node;
	node *L2 = new node;

	createIntersectionLL(&L1,&L2);
	printList(L1);
	printList(L2);

	node *intersectNode = intersectingNode(L1, L2);

	cout<<"Value of the intersecting node is: "<<intersectNode->data<<" and address is: "<<intersectNode<<endl;
}

void createNode(node *current, int value){
	node *newNode = new node;
	newNode->data = value;
	newNode->next = NULL;
	current->next = newNode;
}

void createIntersectionLL(node **L1, node **L2){
	node *P = *L1;
	node *Q = *L2;

	P->data = 1;
	createNode(P, 2);
	P = P->next;

	createNode(P, 3);
	P = P->next;

	Q->data = 7;
	createNode(Q,8);
	Q = Q->next;

	createNode(P,4);
	P = P->next;
	Q->next = P;
	cout<<"Common node address when created is: "<<P<<endl;
	
	createNode(P,5);
	P = P->next;

}

node* intersectingNode(node *L1, node *L2){
	int length1 = LinkedListLength(L1);
	int length2 = LinkedListLength(L2);

	node *head1 = L1;
	node *head2 = L2;

	int diffLen;

	if(length1 > length2){
		diffLen = length1 - length2;
		for(int i=0; i<diffLen; i++)
			head1 = head1->next;
	}
	else{
		diffLen = length2 - length1;
		for(int i=0; i<diffLen; i++)
			head2 = head2->next;
	}

	while(head1 && head2){
		if(head1 == head2)
			break;
		head2 = head2->next;
		head1 = head1->next;
	}

	return head2;

}