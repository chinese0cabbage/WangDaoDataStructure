#pragma once
#include"Utils/TypeUtils.h"
#include"Utils/ErrorUtils.h"
#include<malloc.h>

void InsertNode2BST(TreeNode* tree, double goal) {
	if (!tree)
		ErrorExit(ErrorNullInput); //���ڵ�Ϊ�գ�ֱ�ӷ���

	//��ʼ���ڵ���Ϣ
	TreeNode* head = tree, * newNode;
	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->val = goal;
	newNode->LeftChild = NULL;
	newNode->RightChild = NULL;

	//���Һ��ʵ�λ�ò���ڵ�
	while (head) {
		if (head->val == goal) {
			return; //���ڣ�����Ҫ����
		}
		else if (goal > head->val) { //���ڸ��ڵ㣬������
			if (head->RightChild) { //���ӽڵ㲻Ϊ�գ���������
				head = head->RightChild;
			}
			else { //���ӽڵ�Ϊ�գ����½ڵ�ᵽ�Һ��ӵ�λ��
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
			return head; //���ڣ����ص�ǰ�ڵ�
		}
		else if (goal > head->val) { //���ڸ��ڵ㣬������
			if (head->RightChild) //���ӽڵ㲻Ϊ�գ���������
				head = head->RightChild;
			else
				return NULL; //�ҽڵ�Ϊ�գ�֤�����в�������Ŀ��ֵ��ͬ�Ľڵ�
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