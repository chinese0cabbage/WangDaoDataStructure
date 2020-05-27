#include"Utils/TypeUtils.h"
#include"Utils/TreeNodeStack.h"
#include<malloc.h>
#include<stdio.h>
CommandType WaitCommandTip();
TreeNode* InitTree() {
	TreeNode* head, * last;
	TreeNodeStack* stack;
	head = (TreeNode*)malloc(sizeof(TreeNode));
	stack = (TreeNodeStack*)malloc(sizeof(TreeNodeStack));
	double input = 0;
	printf("请输入根节点的值:");
	scanf_s("%lf", &input);
	head->val = input;
	head->Pos = 1;
	InsertNode(stack, head);
	last = head;
	CommandType command = Left;
	while(command != End) {
		command = WaitCommandTip();
		TreeNode* newNode;
		switch (command)
		{
		case Cancel:
			return NULL;
		case Back:
			last = PopParentNode(stack, last);
			if (last == nullptr) {
				printf("当前是根节点，不存在父节点!");
				last = head;
				continue;
			}
			break;
		case End:
			return head;
		case Left:
			newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("请输入要插入左节点的值:");
			scanf_s("%lf", &input);
			newNode->val = input;
			newNode->Pos = last->Pos * 2;
			last->LeftChild = newNode;
			InsertNode(stack, last);
			last = newNode;
			break;
		case Right:
			newNode = (TreeNode*)malloc(sizeof(TreeNode));
			printf("请输入要插入右节点节点的值:");
			scanf_s("%lf", &input);
			newNode->val = input;
			newNode->Pos = last->Pos * 2 + 1;
			last->RightChild = newNode;
			InsertNode(stack, last);
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
	printf("0:取消(程序退出),1:返回上一节点选择,2:结束插入,3:插入左子节点的值,4:插入右子节点的值\n");
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