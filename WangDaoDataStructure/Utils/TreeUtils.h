#pragma once
#include"TypeUtils.h"
#include"DataUtils.h"

//�ݹ�����������,�ݹ���������Ӷ�ΪO(lgn)
int GetTreeDepth(TreeNode* tree) { // tested
	if (!tree)
		return 0;
	else
		return 1 + Max(GetTreeDepth(tree->LeftChild), GetTreeDepth(tree->RightChild));
}