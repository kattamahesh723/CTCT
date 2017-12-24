#include <iostream>

using namespace std;

#ifndef TREE_H
#define TREE_H

struct node{
	int data;
	node *left, *right;
};

void inOrder(node *root);
void preOrder(node *root);
void postOrder(node *root);

#endif