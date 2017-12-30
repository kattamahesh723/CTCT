/*
	Three conditions:
		1. For any given node successor is the leftmost node from the right sub tree
		2. If there is no right sub tree, and the node is left to its parent then successor is parent
		3. If node is right to its parent, then successor is among its ancestors, if ancestor is left to its parent
*/

#include <iostream>
#include "BSTHelper.h"
//#include "TreeHelper.h"

using namespace std;

node* leftMost(node *n){
	node *current = n;

	while(current->left)
		current = current->left;

	return current;
}

node* returnIfParentLeft(node *n){

	if(!n)
		return NULL;
	node *parent = n->parent;

	if(parent->left == n)
		return parent;
	else{
		return returnIfParentLeft(n->parent);
	}
}

node* inorderSuccessor(node *node){
	if(node->right){
		return leftMost(node->right);
	}
	else{
		return returnIfParentLeft(node);
	}
}


int main()
{
	cout<<"Create BST?"<<endl;
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

	node *n = root->left->right->right;
	node *successor = inorderSuccessor(n);

	cout<<"In order traversal"<<endl;
	inOrder(root);
	cout<<endl;
	cout<<endl;
	cout<<"Node: "<<n->data<<"\tSuccessor: "<<successor->data<<"\tParent: "<<endl;//<<successor->parent->data<<endl;
	
}