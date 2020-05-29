#pragma once
#include<malloc.h>
#include"TypeUtils.h"
//��ͷ�����Ϊ��̬�Ľڵ㣬��ջ����ͷ��㴦���룬��ջ��ֱ�ӵ���ͷ����Ԫ��
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