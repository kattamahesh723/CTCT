/*
	Q.  Find if a linked list is palindrome.
*/

/*
	Tip: Solution is presented by creating duplicate list and reversing it and then comparing it to original list.

		 It can be solved using stacks also, where we push elements till the middle element, then compare by poping 
		 elements therafter. If no conflicts found then the given linked list is palindrome.	
*/

#include<iostream>
#include<stack>
#include "LinkedListUtility.h"

using namespace std;

bool isPalindrome(node*, node*);	// Using reverse linked list and comparison
bool isPalindromeStack(node*); 		// Using stack and iterative method

int main()
{
	int N; // Number of elements in the linked list
	cout<<"Enter number of linkd list elements"<<endl;
	cin>>N;

	node *head = new node;
	cout<<"Enter elements into linked list"<<endl;
	createLinkedList(head, N);

	cout<<"Input linked list is: "<<endl;
	printList(head);

	node *copiedList = new node;
	copyLinkedList(head, &copiedList);
	cout<<"Copied list is:"<<endl;
	printList(copiedList);

	cout<<"After copied list is reversed: "<<endl;
	reverseLinkedList(&copiedList);
	printList(copiedList);
	

	string result = isPalindrome(head, copiedList)?"YES":"NO";

	string stackResult = isPalindromeStack(head)?"YES":"NO";

	cout<<"Is the given linked list is palindrome? "<<stackResult<<endl;

}

bool isPalindromeStack(node *head){
	stack <int> listNodes;		// stores nodes till middle of the linked list

	node *fast = head;
	node *slow = head;

	while(fast && fast->next){
		listNodes.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}

	if(fast)			// Check if linked list contaions odd number of nodes, if then skip the middle element
		slow = slow->next;

	while(slow){
		int value = listNodes.top();
		cout<<"slow: "<<slow->data<<" stack: "<<value<<endl;
		listNodes.pop();
		if(value != slow->data)
			return false;
		slow = slow->next;
	}
	
	return true;

}

bool isPalindrome(node *head, node *copiedList){
	node *P = head;
	node *Q = copiedList;

	while(P && Q){
		if(P->data != Q->data)
			return false;
		P = P->next;
		Q = Q->next;
	}	
	return true;
}