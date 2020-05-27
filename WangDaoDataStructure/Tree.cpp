#include"Utils/TypeUtils.h"
#include"Utils/TreeNodeStack.h"
#include<malloc.h>
#include<stdio.h>
TreeNode* InitTree() {
	TreeNode* head, * last;
	TreeNodeStack* stack;
	head = (TreeNode*)malloc(sizeof(TreeNode));
	stack = (TreeNodeStack*)malloc(sizeof(TreeNodeStack));
	double input = 0;
	printf("��������ڵ��ֵ:");
	scanf("%lf", &input);
	head->val = input;
	head->Pos = 1;
	InsertNode(stack, head);
	last = head;
	CommandType command = Left;
	while(command != End) {
		command = WaitCommandTip();
		switch (command)
		{
		case Cancel:
			return NULL;
		case Back:
			last = PopParentNode(stack, last);
			if (last == nullptr) {
				printf("��ǰ�Ǹ��ڵ㣬�����ڸ��ڵ�!");
				last = head;
				continue;
			}
			break;
		case End:
			return head;
		case Left:
			TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("������Ҫ������ڵ��ֵ:");
			scanf("%lf", &input);
			newNode->val = input;
			newNode->Pos = last->Pos * 2;
			last->LeftChild = newNode;
			InsertNode(stack, last);
			last = newNode;
			break;
		case Right:
			TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("������Ҫ�����ҽڵ�ڵ��ֵ:");
			scanf("%lf", &input);
			newNode->val = input;
			newNode->Pos = last->Pos * 2 + 1;
			last->RightChild = newNode;
			InsertNode(stack, last);
			last = newNode;
			break;
		default:
			break;
		}
	}
	return head;
}

CommandType WaitCommandTip() {
	int inputCommand = -1;
	printf("*********��ʾ**********");
	printf("0:ȡ��(�����˳�),1:������һ�ڵ�ѡ��,2:��������,3:�������ӽڵ��ֵ,4:�������ӽڵ��ֵ");
	printf("��������һ������ָ�");
	scanf("%d", &inputCommand);
	if (inputCommand >= 0 && inputCommand <= 4) {
		return (enum CommandType)inputCommand;
	}
	else {
		printf("��ǰ��������淶���밴����ʾ��ָʾ��������");
		return WaitCommandTip();
	}
}