#include"BST.h"

TreeNode* ApplyNewNode(double val, int pos);
int main() {
	double arr[] = { 14, 21,19,17,9,10,11,7,6,5,5,3,1,2 };
	TreeNode* tree = NULL;
	tree = ApplyNewNode(0, 0);
	InsertNode2BST(tree, 1);
	return 0;
}