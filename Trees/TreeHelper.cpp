#include "TreeHelper.h"

node* createArrayAndReturnTree(){
	int size;
	cout<<"Enter the size of the array"<<endl;
	cin>>size;

	int *array = (int *)malloc(sizeof(int)*size);

	cout<<"Enter elements into array"<<endl;

	for(int i=0; i<size; i++)
		cin>>array[i];

	node *root = constructTree(array, 0, size-1);

	return root;
}

node* constructTree(int *array, int start, int end){

	if(start > end)
		return NULL;

	int middle = (end + start)/2;

	node *root = new node;

	root->data = array[middle];
	root->left = constructTree(array, start, middle-1);
	root->right = constructTree(array, middle+1, end);

	return root;
}

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