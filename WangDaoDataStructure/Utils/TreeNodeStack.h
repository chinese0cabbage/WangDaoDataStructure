#include"TypeUtils.h"
void InsertNode(TreeNodeStack* stack, TreeNode *node) {
	stack->StackClooector[node->Pos] = node;
}

TreeNode* PopParentNode(TreeNodeStack* stack, TreeNode *node) {
	if (node->Pos == 1)
		return nullptr;
	return stack->StackClooector[node->Pos / 2];
}