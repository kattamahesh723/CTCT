#include <iostream>
#include "TreeHelper.h"

using namespace std;

struct listNode{
	int data;
	listNode *next;
};

struct TreeNode{
	node *data;
	TreeNode *next;
};

// Create a node for the linked list
listNode *createNode(int data){
	listNode *newNode = new listNode;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

TreeNode *createTreeNode(node *data){
	TreeNode *newNode = new TreeNode;
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

// Initialize the array of the current nodes, which holds the latest added node in any depth
void initializeNodeArray(listNode *currentNode[], int height){
	for(int h=0; h<height; h++){
		currentNode[h] = NULL;
	}
}


void printLinkedListIter(TreeNode *head){
	TreeNode *current = head;


	while(current){
		cout<<current->data->data<<"->";
		current = current->next;
	}
	cout<<"NULL"<<endl;
}

void printListsIter(TreeNode *array[], int height){
	cout<<"=================================================="<<endl;
	for(int h=0; h<height; h++){
		printLinkedListIter(array[h]);
	}
	cout<<"=================================================="<<endl;
}

void printLinkedList(listNode *head){
	listNode *current = head;

	while(current){
		cout<<current->data<<"->";
		current = current->next;
	}
	cout<<"NULL"<<endl;
}

void printLists(listNode *array[], int height){
	cout<<"=================================================="<<endl;
	for(int h=0; h<height; h++){
		printLinkedList(array[h]);
	}
	cout<<"=================================================="<<endl;
}

// Recursive algorithm to create the linked lists of nodes at all depths
void createListOfDepths(node *root, listNode **array, listNode **currentNode, int depth, int index){
	if(root && index != depth){

		if(!currentNode[index]){
			array[index] = createNode(root->data);
			currentNode[index] = array[index];
		}
		else{
			currentNode[index]->next = createNode(root->data);
			currentNode[index] = currentNode[index]->next;
		}

		createListOfDepths(root->left, array, currentNode, depth, index+1);
		createListOfDepths(root->right, array, currentNode, depth, index+1);
	}
}

void createListOfDepthsIterative(node *root, TreeNode **array){
	TreeNode *head = new TreeNode;

	int flag = false;				// Indicates if head is null or not
									// Head is null, means there is no node added to linked list in the current iteration
									// Reached end of the tree
	if(root){
		head->data = root;
		head->next = NULL;
		flag = true;
	}

	int index = 0;					// Indicated the current index of the array to which the linked list is pushed
	while(flag){
		flag = false;
		array[index] = head;

		head = new TreeNode;
		TreeNode *current = head;

		head = NULL;

		TreeNode *parents = array[index];

		while(parents){
			if(parents->data->left){
				if(!head){
					head = createTreeNode(parents->data->left);
					current = head;
				}
				else{
					current->next = createTreeNode(parents->data->left);
					current = current->next;
				}
				flag = true;
			}

			if(parents->data->right){
				if(!head){
					head = createTreeNode(parents->data->right);
					current = head;
				}
				else{
					current->next = createTreeNode(parents->data->right);
					current = current->next;
				}
				flag = true;
			}
			

			parents = parents->next;
			
		}
		index++;

	}
}



int main()
{
	node *root = createArrayAndReturnTree();

	int height = returnTreeHeight(root);

	listNode *array[height];
	listNode *currentNode[height];

	TreeNode *arrayIter[height];

	// array[0] = NULL;
	initializeNodeArray(currentNode, height);

	
	createListOfDepths(root, array, currentNode, height, 0);
	createListOfDepthsIterative(root,arrayIter);

	cout<<"Recursive method:"<<endl;
	printLists(array, height);

	cout<<"Iterative method:"<<endl;
	printListsIter(arrayIter, height);

}










