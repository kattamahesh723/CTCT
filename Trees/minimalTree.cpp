#include <iostream>
#include "TreeHelper.h"

using namespace std;


node *constructBST(int *array, int start, int end);


int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	node *root = constructTree(array, 0, 12);

	cout<<"In order traversal"<<endl;
	inOrder(root);
	cout<<endl;

	cout<<"Pre order traversal"<<endl;
	preOrder(root);
	cout<<endl;

	cout<<"Post order traversal"<<endl;
	postOrder(root);
	cout<<endl;
}
