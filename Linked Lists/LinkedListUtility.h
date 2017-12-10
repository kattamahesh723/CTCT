/*
	Header file to help in creating linked list and printing it.
	Crating LL and Printing are two common methods frequently occur in any LL problem we solve.
	So I created a header file to reduce implementing it repeatedly.
*/
#ifndef PRINT_H
#define PRINT_H
struct node
{
	int data;
	node *next;
};

void printList(node *head);	// Print linked list
void createLinkedList(node *head, int N);	// N is the number of elements in LL, head is the pointer to start of LL
void reverseLinkedList(node **head);	// Reverses the linked list, head is the pointer to the address of the head node
void copyLinkedList(node *oldList, node **newList);	// Copies elements from oldList to newList
int LinkedListLength(node *head); 		// Returns the length of the linked list
#endif