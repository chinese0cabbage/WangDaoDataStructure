#include"BST.h"

TreeNode* ApplyNewNode(double val, int pos);
int main() {
	double arr[] = { 14, 21,19,17,9,10,11,7,6,5,5,3,1,2,22,8,7.5 };
	TreeNode* tree = NULL;
	tree = ApplyNewNode(arr[0], 0);
	for (int i = 1; i < 17; i++)
	{
		InsertNode2BST(tree, arr[i]);
	}
	DeleteBSTNode(tree, 2);
	TreeNode* node = SearchBSTNode(tree, 14);
	return 0;
}