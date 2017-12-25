/*
	By recursively finding the heights of left and right branches and checking the balanced condition can solve this problem.
	But fidning height and checking condtion repeatedly has time complexity O(n^2)

	Instead can we check simultaneoulsy the condition for balanced tree while finding the height. 
	In this problem we don't need to find the height of the tree, but if we have to find the height of the tree for any other
	purposes in the same problem, then the first method is prefered.
*/

#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node* newNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int checkHeight(Node *root){
	if(!root)	return 0;

	int leftHeight = checkHeight(root->left);

	if(leftHeight == -1)	return -1;

	int rightHeight = checkHeight(root->right);

	if(rightHeight == -1)	return -1;

	if(abs(leftHeight - rightHeight) > 1)
		return -1;
	else
		return max(leftHeight, rightHeight)+1;
}

bool isBSTBalanced(Node *root){
	return checkHeight(root) != -1;
}

int main()
{
	struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(8);
 

    bool result = isBSTBalanced(root);

    if(result)
    	cout<<"Balanced"<<endl;
    else
    	cout<<"Not balanced"<<endl;
}