#include <iostream>
#include "BSTHelper.h"

using namespace std;

node* shiftNode(node *node1, int distance);
node* ancestor(node *root, node *node1, node *node2);
node* ancestor2(node *root, node *node1, node *node2);
int distanceFromRoot(node *root, node *n);

int main(int argc, char const *argv[])
{
	//cout<<"Create BST?"<<endl;
	cout<<"Select the oepration from below options"<<endl;
	
	node *root = NULL;

	int menuNumber = 0;


	while(menuNumber != 2){
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"1. Insert\n2. Quit"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cin>>menuNumber;

		if(menuNumber == 1){
			int data;
			cout<<"Enter value to be added into BST"<<endl;
			cin>>data;
			root = insert(root,data);
		}
		else if(menuNumber == 2){
			cout<<"Quitting"<<endl;
		}

		else{
			cout<<"Entered wrong option, please re-enter again"<<endl;
		}
	}

	node *node1 = root->left->left;
	node *node2 = root->right->right;
	
	node *ancestorNode1 = ancestor(root, node1, node2);
	node *ancestorNode2 = ancestor2(root, node1, node2);
	
	if(ancestorNode1)
		cout<<"Common ancestor from method 1 is "<<ancestorNode1->data<<endl;
	else
		cout<<"No common ancestor found, might be from different trees"<<endl;

	if(ancestorNode2)
		cout<<"Common ancestor from method 2 is "<<ancestorNode2->data<<endl;
	else
		cout<<"No common ancestor found, might be from different trees"<<endl;
	return 0;
}

int distanceFromRoot(node *root, node *n){
	node *current = n;
	int distance = 0;
	while(current->parent){
		distance++;
		current = current->parent;
	}

	return distance;
}

node* shiftNode(node *node1, int distance){
	while(distance > 0){
		node1 = node1->parent;
		distance--;
	}

	return node1;
}

// When parent attribute is used
node* ancestor(node *root, node *node1, node *node2){
	int distance1 = distanceFromRoot(root, node1);
	int distance2 = distanceFromRoot(root, node2);

	if(distance1 > distance2)	node1 = shiftNode(node1, distance1-distance2);
	else	node2 = shiftNode(node2, distance2 - distance1);

	cout<<"node1->data: "<<node1->data<<endl;
	cout<<"node2->data: "<<node2->data<<endl;
	while(node1->parent && node2->parent && node1 != node2){
		node1 = node1->parent;
		node2 = node2->parent;
	}

	return node1;
}

// When parent attribute is not used

node* ancestor2(node *root, node *node1, node *node2){
	if(root == NULL)	return NULL;

	if(node1 == root || node2 == root)	return root;

	node *leftSubTree = ancestor2(root->left, node1, node2);
	node *rightSubTree = ancestor2(root->right, node1, node2);

	if(leftSubTree && rightSubTree) 	return root;

	return (leftSubTree != NULL)? leftSubTree:rightSubTree;
}
