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
	printf("请输入根节点的值:");
	scanf_s("%lf", &input);
	head->val = input;
	head->Pos = 1;
	head->LeftChild = NULL;
	head->RightChild = NULL;
	InsertNode(stack, head);
	last = head;
	CommandType command = Left;
	while (command != End) {
		printf("当前节点的索引是:%d\n", last->Pos - 1);
		command = WaitCommandTip();
		TreeNode* newNode;
		switch (command)
		{
		case Cancel:
			return NULL;
		case Get:
			int pos;
			tmp = last;
			printf("请输入想要取出节点的索引：");
			scanf_s("%d", &pos);
			last = GetSpecifyNode(stack, pos);
			if (last == NULL) {
				printf("输入的索引不合法或该位置没有元素\n");
				last = tmp;
				continue;
			}
			tmp = NULL;
			break;
		case End:
			return head;
		case Left:
			if (last->LeftChild != NULL) {
				printf("当前父节点的左子节点存在数据，是否覆盖\n");
				Confirm confirm = WaitConfirm();
				if (confirm == No) {
					continue;
				}
			}
			newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("请输入要插入左节点的值:");
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
				printf("当前父节点的右子节点存在数据，是否覆盖\n");
				Confirm confirm = WaitConfirm();
				if (confirm == No) {
					continue;
				}
			}
			newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("请输入要插入右节点节点的值:");
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
	printf("*********提示**********\n");
	printf("0:取消(程序退出),1:获取指定索引位置的节点作为父节点,2:结束插入,3:插入左子节点的值,4:插入右子节点的值\n");
	printf("请输入下一步操作指令：");
	scanf_s("%d", &inputCommand);
	if (inputCommand >= 0 && inputCommand <= 4) {
		return (enum CommandType)inputCommand;
	}
	else {
		printf("当前输入命令不规范，请按照提示的指示输入命令");
		return WaitCommandTip();
	}
}

Confirm WaitConfirm() {
	printf("请确认 0:no 1:yes\n");
	int inputCommand;
	scanf_s("%d", &inputCommand);
	switch (inputCommand)
	{
	case 0:
		return No;
	case 1:
		return Yes;
	default:
		printf("输入非法，请重新输入\n");
		return WaitConfirm();
	}
}