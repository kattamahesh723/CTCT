#include "TreeHelper.h"

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<"\t";
		inOrder(root->right);
	}
}

void preOrder(node *root){
	if(root){
		cout<<root->data<<"\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(node *root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<"\t";
	}
}