#pragma once
#include<malloc.h>
#include"TypeUtils.h"
//��ͷ�����Ϊ��̬�Ľڵ㣬��ջ����ͷ��㴦���룬��ջ��ֱ�ӵ���ͷ����Ԫ��
void PushNode(TreeNodeList* stack, TreeNode* node) {
	TreeNodeList* newStack;
	newStack = (TreeNodeList*)malloc(sizeof(TreeNodeList));
	if (!stack)
		stack = newStack;
	newStack->node = node;
	newStack->next = stack;
	stack = newStack;
}

TreeNode* PopNode(TreeNodeList* stack) {
	TreeNode* node = stack->node;
	stack = stack->next;
	return node;
}