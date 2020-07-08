#pragma once
#include"Utils/TypeUtils.h"
#include"Utils/ErrorUtils.h"
#include<malloc.h>

void InsertNode2BST(TreeNode* tree, double goal) {
	if (!tree)
		ErrorExit(ErrorNullInput); //根节点为空，直接返回

	//初始化节点信息
	TreeNode* head = tree, * newNode;
	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->val = goal;
	newNode->LeftChild = NULL;
	newNode->RightChild = NULL;

	//查找合适的位置插入节点
	while (head) {
		if (head->val == goal) {
			return; //等于，不需要新增
		}
		else if (goal > head->val) { //大于根节点，向右走
			if (head->RightChild) { //右子节点不为空，继续向下
				head = head->RightChild;
			}
			else { //右子节点为空，将新节点结到右孩子的位置
				head->RightChild = newNode;
				return;
			}
		}
		else {
			if (head->LeftChild) {
				head = head->LeftChild;
			}
			else {
				head->LeftChild = newNode;
				return;
			}
		}
	}
}

TreeNode* SearchBSTNode(TreeNode* tree, double goal) {
	if (!tree)
		ErrorExit(ErrorNullInput);
	TreeNode* head = tree;
	while (head) {
		if (head->val == goal) {
			return head; //等于，返回当前节点
		}
		else if (goal > head->val) { //大于根节点，向右走
			if (head->RightChild) //右子节点不为空，继续向下
				head = head->RightChild;
			else
				return NULL; //右节点为空，证明树中不存在与目标值相同的节点
		}
		else {
			if (head->LeftChild)
				head = head->LeftChild;
			else
				return NULL;
		}
	}
}

void DeleteBSTNode(TreeNode* tree, double goal) {
	if (!tree)
		ErrorExit(ErrorNullInput);

}