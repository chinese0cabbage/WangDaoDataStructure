#include"TypeUtils.h"

void InsertNode(TreeNodeCollector* stack, TreeNode *node) {//tested
	stack->StackCollector[node->Pos - 1] = node;
}

TreeNode* PopParentNode(TreeNodeCollector* stack, TreeNode *node) {//tested
	if (node->Pos == 1)
		return NULL;
	return stack->StackCollector[node->Pos / 2];
}

TreeNode* GetSpecifyNode(TreeNodeCollector* stack, int pos) {//tested
	if (pos < 0)
		return NULL;
	return stack->StackCollector[pos];
}