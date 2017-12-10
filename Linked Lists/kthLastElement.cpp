/*
	Q.  Implement an algorithm to find the kth to last element of a singly linked list.
*/

#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

node* kthToLastElementIterative(node *head, int k);
node* kthToLastElementRecursive(node *head, int k, int &index);

int main()
{
	int N,k;	// Number of nodes in the linked list
	cout<<"Enter number of nodes in the linked list"<<endl;
	cin>>N;

	node *head = (node*)malloc(sizeof(node));

	cout<<"Enter linked list elements"<<endl;

	int value;
	cin>>value;

	head->data = value;
	head->next = NULL;

	node *current = head;

	for(int i=1; i<N; i++){
		cin>>value;
		node *newNode = (node*)malloc(sizeof(node));
		newNode->data = value;
		newNode->next = NULL;
		current->next = newNode;
		current = newNode;
	}

	cout<<"Enter k value"<<endl;
	cin>>k;

	node *kNode = kthToLastElementIterative(head,k);
	cout<<"The value of the kth node is ";
	cout<<kNode->data<<endl;

	int index = 0; 	// Used as global to recursive function to count till k 
	node *kNodeRec = kthToLastElementRecursive(head,k, index);
	cout<<"The value of the kth node is ";
	cout<<kNodeRec->data<<endl;

	
}

// Iteratice way to find the kth element from end, Time complexity is O(n), space complexity is O(1)
node* kthToLastElementIterative(node *head, int k){
	node *p1=head, *pk = head;

	/*
		Iterate till pk is k nodes away from p1
	*/
	for(int i=0; i<k; i++){	
		if(!pk)
			return NULL;	// Out of bounds
		cout<<"data: "<<pk->data<<endl;
		pk = pk->next;
	}

	/*
		When pk is at last node p1 is at kth node from end
	*/
	cout<<"data: "<<pk->data<<endl;
	while(pk){
		cout<<"data: "<<pk->data<<endl;
		p1 = p1->next;
		pk = pk->next;
	}

	return p1;
}

// Recursive way to find the kth element from end, Time complexity is O(n), Space complexity is O(n)
node* kthToLastElementRecursive(node *head, int k, int &index){
	if(!head)
		return 0;

	node *nd = kthToLastElementRecursive(head->next, k, index);
	index++;
	if(index == k)
		return head;

	return nd;
}
