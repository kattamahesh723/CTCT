#include <iostream>
#include "TreeHelper.h"
using namespace std;

int main()
{
	node *root = createArrayAndReturnTree();

	cout<<"In order traversal"<<endl;
	inOrder(root);
	cout<<endl;

	cout<<"Pre order traversal"<<endl;
	preOrder(root);
	cout<<endl;

	cout<<"Post order traversal"<<endl;
	postOrder(root);
	cout<<endl;

	cout<<"Height of the tree is: "<<returnTreeHeight(root)<<endl;
}