#include"TypeUtils.h"

void InsertNode(TreeNodeCollector* stack, TreeNode *node) {//tested
	stack->StackClooector[node->Pos - 1] = node;
}

TreeNode* PopParentNode(TreeNodeCollector* stack, TreeNode *node) {//tested
	if (node->Pos == 1)
		return NULL;
	return stack->StackClooector[node->Pos / 2];
}

TreeNode* GetSpecifyNode(TreeNodeCollector* stack, int pos) {//tested
	if (pos < 0)
		return NULL;
	return stack->StackClooector[pos];
}