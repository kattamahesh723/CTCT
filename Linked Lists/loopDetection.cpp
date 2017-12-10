/*
	Q.  Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
*/

#include <iostream>
#include "LinkedListUtility.h"

using namespace  std;

node* newNode(int value){
	node *temp = new node;
	temp->data = value;
	temp->next = NULL;
	return temp;
}

// Returns start node of the loop, assuming that given Linked list contaions loop. Didn't handled the case where LL has no loop
node* headNodeFromLoop(node *head){	
	node *slow = head;
	node *fast = head;

	slow = slow->next;
	fast = fast->next->next;

	while(slow != fast){
		slow = slow->next;
		fast = fast->next->next;
	}

	slow = head;

	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}

	return slow;

}

int main()
{
	node *head = newNode(50);
	head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next = head->next->next;

    /*
		Linked list:  50->20->15->4->10
							  ^       |
							  |_______|
    */
    node *start = headNodeFromLoop(head);

    cout<<"Start node of the loop is: "<<start->data<<endl;
}