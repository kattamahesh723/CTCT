/*
	Q.  Implement an algorithm to delete a node in the middle of a singly linked list, given access to only to that node
		(Head node information is not available)
*/

/*
	Algorithm:	Copy elements from next node of the middle node into the current node and delete the last node
*/
#include<iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

void createLinkedList(node *head, int N);	// head is the head of linked list, N is number of elements in the linked list
node* findMiddleNode(node *head);			// Finds the middle node and returns its reference
void deleteMiddleNode(node *middle);		// Deletes the middle node with its reference passed


int main()
{
	int N; 	// number of elements in the linked list
	cout<<"Enter number of elements in the linked list"<<endl;
	cin>>N;

	node *head = new node;
	createLinkedList(head, N);
	node *middle_node = findMiddleNode(head);
	deleteMiddleNode(middle_node);

	node *current = head;
	while(current){
		cout<<current->data<<"->";
		current = current->next;
	}
	cout<<"NULL"<<endl;
	//cout<<"Middle node value: "<<middle_node->data<<endl;

	return 0;

}

void createLinkedList(node *head, int N)
{
	int value;
	node *current = head;

	cout<<"Enter elements of the linked list"<<endl;
	cin>>value;
	head->data = value;
	for(int i=1; i<N; i++){
		cin>>value;
		node *newNode = new node;
		newNode->data = value;
		newNode->next = NULL;
		current->next = newNode;
		current = newNode;
	}
}

node* findMiddleNode(node *head)
{
	node *slow_node = head;
	node *fast_node = head->next;

	while(fast_node){
		slow_node = slow_node->next;
		if(fast_node->next){
			fast_node = (fast_node->next)->next;
		}
		else
			fast_node = NULL;
	}

	return slow_node;
}

void deleteMiddleNode(node *middle){
	node *current = middle;
	node *nextNode = middle->next;

	while(nextNode->next){
		//cout<<"current: "<<current->data<<"		Next: "<<nextNode->data<<endl;
		current->data = nextNode->data;
		current = nextNode;
		nextNode = nextNode->next;
		//cout<<"after current: "<<current->data<<"		after Next: "<<nextNode->data<<endl;
	}
	current->data = nextNode->data;
	current->next= NULL;
}