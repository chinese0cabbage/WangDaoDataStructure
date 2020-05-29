#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include"Utils/TypeUtils.h"
#include"Utils/TreeNodeColt.h"

CommandType WaitCommandTip();
Confirm WaitConfirm();
TreeNode* InitTree() {
	TreeNode* head, * last, * tmp;
	TreeNodeCollector* stack;
	head = (TreeNode*)malloc(sizeof(TreeNode));
	stack = (TreeNodeCollector*)malloc(sizeof(TreeNodeCollector));
	for (int i = 0; i < 500; i++)
	{
		stack->StackClooector[i] = NULL;
	}
	double input = 0;
	printf("��������ڵ��ֵ:");
	scanf_s("%lf", &input);
	head->val = input;
	head->Pos = 1;
	head->LeftChild = NULL;
	head->RightChild = NULL;
	InsertNode(stack, head);
	last = head;
	CommandType command = Left;
	while (command != End) {
		printf("��ǰ�ڵ��������:%d\n", last->Pos - 1);
		command = WaitCommandTip();
		TreeNode* newNode;
		switch (command)
		{
		case Cancel:
			return NULL;
		case Get:
			int pos;
			tmp = last;
			printf("��������Ҫȡ���ڵ��������");
			scanf_s("%d", &pos);
			last = GetSpecifyNode(stack, pos);
			if (last == NULL) {
				printf("������������Ϸ����λ��û��Ԫ��\n");
				last = tmp;
				continue;
			}
			tmp = NULL;
			break;
		case End:
			return head;
		case Left:
			if (last->LeftChild != NULL) {
				printf("��ǰ���ڵ�����ӽڵ�������ݣ��Ƿ񸲸�\n");
				Confirm confirm = WaitConfirm();
				if (confirm == No) {
					continue;
				}
			}
			newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("������Ҫ������ڵ��ֵ:");
			scanf_s("%lf", &input);
			newNode->val = input;
			newNode->Pos = last->Pos * 2;
			newNode->LeftChild = NULL;
			newNode->RightChild = NULL;
			last->LeftChild = newNode;
			InsertNode(stack, newNode);
			last = newNode;
			break;
		case Right:
			if (last->RightChild != NULL) {
				printf("��ǰ���ڵ�����ӽڵ�������ݣ��Ƿ񸲸�\n");
				Confirm confirm = WaitConfirm();
				if (confirm == No) {
					continue;
				}
			}
			newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("������Ҫ�����ҽڵ�ڵ��ֵ:");
			scanf_s("%lf", &input);
			newNode->val = input;
			newNode->Pos = last->Pos * 2 + 1;
			newNode->LeftChild = NULL;
			newNode->RightChild = NULL;
			last->RightChild = newNode;
			InsertNode(stack, newNode);
			last = newNode;
			break;
		default:
			return NULL;
		}
	}
	return head;
}

CommandType WaitCommandTip() {
	int inputCommand = -1;
	printf("*********��ʾ**********\n");
	printf("0:ȡ��(�����˳�),1:��ȡָ������λ�õĽڵ���Ϊ���ڵ�,2:��������,3:�������ӽڵ��ֵ,4:�������ӽڵ��ֵ\n");
	printf("��������һ������ָ�");
	scanf_s("%d", &inputCommand);
	if (inputCommand >= 0 && inputCommand <= 4) {
		return (enum CommandType)inputCommand;
	}
	else {
		printf("��ǰ��������淶���밴����ʾ��ָʾ��������");
		return WaitCommandTip();
	}
}

Confirm WaitConfirm() {
	printf("��ȷ�� 0:no 1:yes\n");
	int inputCommand;
	scanf_s("%d", &inputCommand);
	switch (inputCommand)
	{
	case 0:
		return No;
	case 1:
		return Yes;
	default:
		printf("����Ƿ�������������\n");
		return WaitConfirm();
	}
}