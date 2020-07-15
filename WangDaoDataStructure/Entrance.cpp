#include"BST.h"
#include"Utils/TreeUtils.h"

int main() {
	double arr[] = { 14, 21,19,17,9,10,11,7,6,5,5,3,1,2,22,8,7.5 };
	TreeNode* head = (TreeNode*)malloc(sizeof(TreeNode));
	head->val = 14;
	head->LeftChild = NULL;
	head->RightChild = NULL;
	for (int i = 1; i < 17; i++)
	{
		InsertNode2BST(head, arr[i]);
	}
	int a = GetTreeDepth(head);
}