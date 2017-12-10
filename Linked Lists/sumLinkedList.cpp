/*
	Q.  You have two numbers represented by linked lists, where each node contains a single digit
		The digits are stored in reverse order, such that the 1's digit is at the head of the list.
		Write a function that adds the two numbers and returns the sum as a linked list.
*/

/*
	In the method reverseLinkedList, I passed double pointer (i.e pointer the address of the head node).
	If we just pass the head node adn tried to modify, the same changes are not reflected in the original
	Linked list (reversing the linked list in this example). In the later case we are just copying the pointer
	and trying to modify, in the first case we are trying to modify the node itself (as reference is passed).
	https://stackoverflow.com/questions/29965992/changing-the-pointer-inside-a-function-does-not-reflect-outside-the-function
*/

#include<iostream>
#include "LinkedListUtility.h"

using namespace std;

void appendNode(node *head, int value);
node* sumList(node *L1, node *L2);


int main()
{
	int N1,N2; 	// Number of elements in linked list
	cout<<"Enter number of elements in linked list 1"<<endl;
	cin>>N1;

	cout<<"Enter number of elements in linked list 2"<<endl;
	cin>>N2;

	node *L1 = new node;
	cout<<"Create linked list 1"<<endl;
	createLinkedList(L1, N1);
	cout<<"First linked list is "<<endl;
	printList(L1);
	cout<<endl;

	node *L2 = new node;
	cout<<"Create linked list 2"<<endl;
	createLinkedList(L2, N2);
	cout<<"Second linked list is "<<endl;
	printList(L2);
	cout<<endl;

	// Finding the sum formed from two lists
	//node *finalSumList = sumList(L1,L2);
	cout<<"Linked list after sum"<<endl;
	//printList(finalSumList);
	cout<<endl;

	cout<<"reverse L1 list"<<endl;
	reverseLinkedList(&L1);
	printList(L1);

	return 0;
}

void appendNode(node *current, int value){
	node *newNode = new node;
	newNode->data = value;
	newNode->next = NULL;
	current->next = newNode;
	//return current;
}

// void reverseLinkedList(node **L1){
// 	node *head = *L1;
// 	if(head){
// 		if(head->next){
// 			node *prev = NULL;
// 			node *nextNode = NULL;
// 			while(head->next){
// 				nextNode = head->next;
// 				head->next = prev;
// 				prev = head;
// 				head = nextNode;
// 			}
// 			head->next = prev;
// 		}
// 	}
// 	*L1 = head;
// }

node* sumList(node *L1, node *L2){

	node *finalList = new node;	// Contains final linked list formed after sum 
	node *current = finalList;
	bool flag = false;			// Check if first node is created
	int carry = 0;				// Carry value 

	node *head1 = L1;
	node *head2 = L2;

	while(true){
		if(head1 && head2){
			if(!flag){
				int value = head1->data + head2->data;
				finalList->data = value%10;
				carry = value/10;
				finalList->next = NULL;
				current = finalList;
				flag = true;
			}
			else{
				int value = head1->data + head2->data + carry;
				appendNode(current, value%10);
				current = current->next;
				carry = value/10;
			}
			head1 = head1->next;
			head2 = head2->next;
			
		}
		else if(head1 && !head2){
			if(!flag){
				int value = head1->data + carry;
				finalList->data = value%10;
				carry = value/10;
				finalList->next = NULL;
				current = finalList;
				flag = true;
			}
			else{
				int value = head1->data + carry;
				appendNode(current, value%10);
				current = current->next;
				carry = value/10;
			}
			head1 = head1->next;
		}
		else if(!head1 && head2){
			if(!flag){
				int value = head2->data + carry;
				finalList->data = value%10;
				carry = value/10;
				finalList->next = NULL;
				current = finalList;
				flag = true;
			}
			else{
				int value = head2->data + carry;
				appendNode(current, value%10);
				current = current->next;
				carry = value/10;
			}
			head2 = head2->next;
		}
		else
			break;
	}
	if(carry != 0)
		appendNode(current,carry);

	return finalList;
}