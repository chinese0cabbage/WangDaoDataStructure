#pragma once
#include"TypeUtils.h"
#include"DataUtils.h"

//递归计算树的深度,递归树求出复杂度为O(lgn)
int GetTreeDepth(TreeNode* tree) { // tested
	if (!tree)
		return 0;
	else
		return 1 + Max(GetTreeDepth(tree->LeftChild), GetTreeDepth(tree->RightChild));
}