/*
	If any binary tree is binary search tree, then the inOrder traversal of that tree is a sorted array.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <climits>
//#include "TreeHelper.h"

using namespace std;

struct node{
	int data;
	node *left, *right;
};

struct node* newNode(int data)
{
    struct node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return (n);
}

void printVector(vector <int> &treeNodes){
	cout<<"========================================================"<<endl;
	for(int i=0; i<treeNodes.size(); i++){
		cout<<treeNodes[i]<<"\t";
	}
	cout<<endl;
	cout<<"========================================================"<<endl;
	
}


void inOrder(node *root, vector<int> &treeNodes){
	if(root){
		inOrder(root->left, treeNodes);
		treeNodes.push_back(root->data);
		inOrder(root->right, treeNodes);
	}
}

bool isSorted(vector <int> &treeNodes){

	int current = treeNodes[0];
	for(int i=1; i<treeNodes.size(); i++){
		if(current > treeNodes[i])
			return false;
		current = treeNodes[i];
	}

	return true;
}

// Time complexity O(n)
bool isValidBST2(node *root, pair<int, int> &p){
	if(root){
		if(root->data > p.first && root->data <= p.second){
			int temp = p.second;
			p.second = root->data;
			bool r1 = isValidBST2(root->left, p);

			p.second = temp;
			p.first = root->data;
			bool r2 = isValidBST2(root->right, p);

			return r1 && r2;
		}
	}
	return true;
}

bool isValidBST(node *root){

	vector <int> treeNodes;

	inOrder(root, treeNodes);
	printVector(treeNodes);

	return isSorted(treeNodes);

}

int main()
{
	//node *root = createArrayAndReturnTree();
	struct node *root = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);

	pair <int, int> p;
	p.first = INT_MIN;
	p.second = INT_MAX;

	bool result = isValidBST2(root, p);
	//bool result = isValidBST(root);

	if(result)
		cout<<"Tree satisfies BST properties"<<endl;
	else
		cout<<"Tree does not satisfies BST properties"<<endl;
}

