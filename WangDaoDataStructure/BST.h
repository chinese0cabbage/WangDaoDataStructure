#pragma once
#include"Utils/TypeUtils.h"
#include"Utils/ErrorUtils.h"

TreeNode* ApplyNewNode(double val, int pos);
void DeleteChildNodeWith2ChildByMove(TreeNode* parent, double goal);
void FreeEqualChild(TreeNode* parent, double goal);
void DeleteChildNodeWith2ChildByReplace(TreeNode* parent, double goal);
void InsertNode2BST(TreeNode* tree, double goal) { //tested
	if (!tree)
		ErrorExit(ErrorNullInput); //���ڵ�Ϊ�գ�ֱ�ӷ���

	//��ʼ���ڵ���Ϣ
	TreeNode* head = tree, * newNode;
	newNode = ApplyNewNode(goal, 0);

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

TreeNode* SearchBSTNode(TreeNode* tree, double goal) { //tested
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

void DeleteBSTNode(TreeNode* tree, double goal) { //tested
	if (!tree)
		ErrorExit(ErrorNullInput);
	TreeNode* head = tree, * parent = NULL;
	while (head) {
		if (goal > head->val) {
			if (head->RightChild) {
				parent = head;
				head = head->RightChild;
			}
			else
				return;
		}
		else if (goal < head->val) {
			if (head->LeftChild) {
				parent = head;
				head = head->LeftChild;
			}
			else
				return;
		}
		else {
			if (head->LeftChild && head->RightChild) {
				// DeleteChildNodeWith2ChildByMove(parent, goal);
				DeleteChildNodeWith2ChildByReplace(parent, goal);
				return;
			}
			else {
				FreeEqualChild(parent, goal);
				return;
			}
		}
	}
}

//ɾ����ǰ�ڵ�����ֵ��ȵĺ��ӽڵ�
void FreeEqualChild(TreeNode* parent, double goal) { //tested
	TreeNode* toDelete = NULL;
	if (parent->LeftChild && parent->LeftChild->val == goal) {
		toDelete = parent->LeftChild;
		if (!toDelete->LeftChild && !toDelete->RightChild)
			parent->LeftChild = NULL;
		else if (toDelete->LeftChild)
			parent->LeftChild = toDelete->LeftChild;
		else
			parent->LeftChild = toDelete->RightChild;
		free(toDelete);
	}
	else if (parent->RightChild && parent->RightChild->val == goal) {
		toDelete = parent->RightChild;
		if (!toDelete->LeftChild && !toDelete->RightChild)
			parent->RightChild = NULL;
		else if (toDelete->LeftChild)
			parent->RightChild = toDelete->LeftChild;
		else
			parent->RightChild = toDelete->RightChild;
		free(toDelete);
	}
}

//��ɾ���ڵ�����Һ��ӽڵ㶼�ᷢ��Ǩ�ƣ�һ���ӵ�˫�׽ڵ��ϣ�һ���������䵽������С�Ľڵ��½���
void DeleteChildNodeWith2ChildByMove(TreeNode* parent, double goal) { //tested
	TreeNode* toDelete = NULL, * toAdd = NULL;
	if (parent->LeftChild->val == goal) {
		toDelete = parent->LeftChild;
		parent->LeftChild = toDelete->LeftChild;
		toAdd = parent->LeftChild;
		while (toAdd->RightChild)
			toAdd = toAdd->RightChild;
		toAdd->RightChild = toDelete->RightChild;
	}
	else {
		toDelete = parent->RightChild;
		parent->RightChild = toDelete->RightChild;
		toAdd = parent->RightChild;
		while (toAdd->LeftChild)
			toAdd = toAdd->LeftChild;
		toAdd->LeftChild = toDelete->LeftChild;
	}
	free(toDelete);
}

//��ɾ���ڵ�����Һ��Ӿ����ֲ�����Ѱ�������������ڵ�(������������С�ڵ�)���汻ɾ���ڵ㣬������ƶ��Ľڵ㻹�����������������ĸ��ڵ�ŵ����ƶ��ڵ�λ��
void DeleteChildNodeWith2ChildByReplace(TreeNode* parent, double goal) { //tested
	TreeNode* replaceNode = NULL, * replaceNodeParent = NULL, * toDelete = NULL;
	if (parent->LeftChild->val == goal) {
		toDelete = parent->LeftChild;
		replaceNodeParent = toDelete;
		replaceNode = replaceNodeParent->LeftChild;
		if (replaceNode->RightChild) {
			while (replaceNode->RightChild) {
				replaceNodeParent = replaceNode;
				replaceNode = replaceNode->RightChild;
			}
			if (replaceNode->LeftChild) {
				replaceNodeParent->RightChild = replaceNode->LeftChild;
				replaceNode->LeftChild = NULL;
			}
			replaceNode->LeftChild = toDelete->LeftChild;
			replaceNode->RightChild = toDelete->RightChild;
			parent->LeftChild = replaceNode;
		}
		else {
			parent->LeftChild = toDelete->LeftChild;
			parent->LeftChild->RightChild = toDelete->RightChild;
		}
		free(toDelete);
	}
	else {
		toDelete = parent->RightChild;
		replaceNodeParent = toDelete;
		replaceNode = replaceNodeParent->RightChild;
		if (replaceNode->LeftChild) {
			while (replaceNode->LeftChild) {
				replaceNodeParent = replaceNode;
				replaceNode = replaceNode->LeftChild;
			}
			if (replaceNode->RightChild) {
				replaceNodeParent->LeftChild = replaceNode->RightChild;
				replaceNode->RightChild = NULL;
			}
			replaceNode->LeftChild = toDelete->LeftChild;
			replaceNode->RightChild = toDelete->RightChild;
			parent->RightChild = replaceNode;
		}
		else {
			parent->RightChild = toDelete->RightChild;
			parent->RightChild->LeftChild = toDelete->LeftChild;
		}
		free(toDelete);
	}
}

TreeNode* ApplyNewNode(double val, int pos) { //tested
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (!newNode)
		ErrorExit(MallocError);
	newNode->val = val;
	newNode->Pos = pos;
	newNode->LeftChild = NULL;
	newNode->RightChild = NULL;
	return newNode;
}