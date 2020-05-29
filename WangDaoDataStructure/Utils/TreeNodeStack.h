#pragma once
#include<malloc.h>
#include"TypeUtils.h"
//以头结点作为动态的节点，入栈是在头结点处接入，出栈是直接弹出头结点的元素
TreeNodeList* InitTreeNodeStack(TreeNode* head) {
	TreeNodeList* stack;
	stack = (TreeNodeList*)malloc(sizeof(TreeNodeList));
	stack->node = head;
	stack->next = NULL;
	return stack;
}

void PushNode(TreeNodeList* stack, TreeNode* node) {
	TreeNodeList* newStack;
	newStack = (TreeNodeList*)malloc(sizeof(TreeNodeList));
	newStack->node = node;
	newStack->next = stack;
	stack = newStack;
}

TreeNode* PopNode(TreeNodeList* stack) {
	TreeNode* node = stack->node;
	stack = stack->next;
	return node;
}