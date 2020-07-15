#pragma once
#include"BST.h"
#include"Utils/TreeNodeStack.h"

void InsertNode2AVL(TreeNode* tree, double goal) {
	if (!tree)
		return;
	TreeNodeList* stack;
	TreeNode* newNode = ApplyNewNode(goal, 0), * head = tree;
	while (head) {
		if (head->val == goal) {
			if (stack)
				free(stack);
			free(newNode);
			return;
		}
		else {
			PushNode(stack, head);
			if (goal > head->val) {
				if (head->RightChild) {
					head = head->RightChild;
				}
				else {
					head->RightChild = newNode;
					break;
				}
			}
			else {
				if (head->LeftChild) {
					head = head->LeftChild;
				}
				else {
					head->LeftChild = newNode;
					break;
				}
			}
		}
	}

}