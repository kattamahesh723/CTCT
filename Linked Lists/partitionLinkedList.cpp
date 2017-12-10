/*
	Q.  Partition a linked list around a value x, such that all nodes less than x come before all nodes
		greater than or equal to x. If x is contained within the list, the values of x only need to be 
		after the elements less than x. The partition element x can appear anywhere in the right partition
		It doesn't need to appear between the left and right partitions.
*/

#include<iostream>
#include "LinkedListUtility.h"

using namespace  std;



//void printList(node *head);
void createLinkedList(node *head, int N);	// N is the number of elements in LL, head is the pointer to start of LL
node* partition(node *head, int value);		// value contains the integer value around which partition has to be done

int main(int argc, char const *argv[])
{
	
	int N;
	cout<<"Enter number of elements in the Linke list"<<endl;
	cin>>N;

	node *head = new node;
	createLinkedList(head, N);

	int x;
	cout<<"Enter a value around which the partition to be done"<<endl;
	cin>>x;

	head = partition(head, x);
	printList(head);
	return 0;
}


node* partition(node *head, int x)
{
	node *start = head;
	node *tail = head;

	node *current = head;

	while(current)
	{
		node *next = current->next;
		if(current->data < x){
			current->next = start;
			start = current;
		}
		else{
			tail->next = current;
			tail = current;
		}
		current = next;
	}
	tail->next = NULL;
	return start;
}