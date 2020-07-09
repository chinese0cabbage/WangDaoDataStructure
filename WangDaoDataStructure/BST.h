#pragma once
#include"Utils/TypeUtils.h"
#include"Utils/ErrorUtils.h"

TreeNode* ApplyNewNode(double val, int pos);
void DeleteChildNodeWith2ChildByMove(TreeNode* parent, double goal);
void FreeEqualChild(TreeNode* parent, double goal);
void DeleteChildNodeWith2ChildByReplace(TreeNode* parent, double goal);
void InsertNode2BST(TreeNode* tree, double goal) { //tested
	if (!tree)
		ErrorExit(ErrorNullInput); //根节点为空，直接返回

	//初始化节点信息
	TreeNode* head = tree, * newNode;
	newNode = ApplyNewNode(goal, 0);

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

TreeNode* SearchBSTNode(TreeNode* tree, double goal) { //tested
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

//删除当前节点中与值相等的孩子节点
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

//被删除节点的左右孩子节点都会发生迁移，一个接到双亲节点上，一个持续下落到最大或最小的节点下接上
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

//被删除节点的左右孩子均保持不动，寻找左子树的最大节点(或右子树的最小节点)代替被删除节点，如果被移动的节点还有子树，则用子树的根节点放到被移动节点位置
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