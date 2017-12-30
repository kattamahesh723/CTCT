#include "BSTHelper.h"

node* newNode(int data){
	node *p = new node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	return p;
}

node* insert(node *root, int data){

	if(!root)
		return newNode(data);

	if(data <= root->data){
		node *temp = insert(root->left, data);
		root->left = temp;
		temp->parent = root;
	}
	else{
		node *temp = insert(root->right, data);
		root->right = temp;
		temp->parent = root;
	}

	return root;
}

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<"\t";
		inOrder(root->right);
	}
}