#include <iostream>
using namespace std;

#ifndef BST_H
#define BST_H

struct node{
	int data;
	node *left, *right, *parent;
};

node* newNode(int data);
node* insert(node *root, int data);
void inOrder(node *root);

#endif