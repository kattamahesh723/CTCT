/*
	Q.  Write code to remove duplicates from an unsorted linked list. Is is possible to do without using temporary buffer.
*/

#include<iostream>
#include<unordered_map>
#include <ctime>

using namespace std;

struct node{
	int data;
	node *next;
};

node* removeDups(node *head);	// Using hashtable, complexity is O(N)
node* removeDups2(node *head);  // Without using any extra space, complexity is O(N^2)
void printNodes(node *head);

int main(int argc, char const *argv[])
{
	int N; // Number of nodes in linked list
	cout<<"Enter number of nodes in the linked list"<<endl;
	cin>>N;

	node *head = (node*)malloc(sizeof(node));

	cout<<"Enter "<<N<<" values to form "<<N<<" length linked list"<<endl;
	int value;
	cin>>value;
	head->data = value;
	head->next = NULL;

	node *current = head;

	for(int i=1; i<N; i++){
		cin>>value;
		node *next = (node*)malloc(sizeof(node));
		next->data = value;
		next->next = NULL;
		current->next = next;
		current = current->next;
	}
	cout<<"Before removing duplicates"<<endl;
	printNodes(head);
	cout<<endl;

	int start_s=clock();
	head = removeDups(head);
	cout<<"After removing duplicates using 1st method"<<endl;
	
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	printNodes(head);
	cout<<endl;

	int start=clock();
	head = removeDups2(head);
	cout<<"After removing duplicates using 2nd method"<<endl;
	
	int stop=clock();
	cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
	printNodes(head);
	return 0;
}

void printNodes(node *head){
	node *current = head;

	while(current){
		cout<<current->data<<"->";
		current = current->next;
	}

	cout<<"NULL"<<endl;
}

node* removeDups(node *head){
	unordered_map<int,int> hashtable;
	node *current = head;
	hashtable[head->data] = head->data;

	if(head->next){
		node *rem = head->next;
		while(rem){
			if(hashtable.find(rem->data) == hashtable.end()){
				cout<<"if rem:"<<rem->data<<endl;
				hashtable[rem->data] = rem->data;
				current = rem;
				rem = rem->next;
			}
			else{
				cout<<"else rem:"<<rem->data<<endl;
				current->next = rem->next;
				rem = current->next;
			}
		}	
	}
	
	return head;
}

node* removeDups2(node *head){
	node *current = head;
	
	while(current){
		node *prev = current;
		node *next = current->next;
		while(next){
			if(next->data == current->data){
				prev->next = next->next;
				next = prev->next;
			}
			else{
				prev = next;
				next = next->next;
			}
		}
		current = current->next;
	}
	return head;
}















