#pragma once
#include<malloc.h>
#include"TypeUtils.h"
typedef struct TreeNodeQueue {
	TreeNodeList* list;
	TreeNodeList* last;
}TreeNodeQueue;

TreeNodeQueue* InitQueue(TreeNode* node) {
	TreeNodeList* list;
	list = (TreeNodeList*)malloc(sizeof(TreeNodeList));
	list->node = node;
	list->next = NULL;
	TreeNodeQueue* queue;
	queue = (TreeNodeQueue*)malloc(sizeof(TreeNodeQueue));
	queue->list = list;
	queue->last = list;
	return queue;
}

void PushNode(TreeNodeQueue* queue, TreeNode* node) {
	TreeNodeList* list;
	list = (TreeNodeList*)malloc(sizeof(TreeNodeList));
	list->node = node;
	list->next = queue->list;
	queue->list = list;
}

TreeNode* GetNode(TreeNodeQueue* queue) {
	TreeNodeQueue* tmp = queue;
	TreeNode* returnNode;
	while (tmp->list->next->next != NULL)
		tmp->list = tmp->list->next;
	returnNode = tmp->list->next->node;
	queue->last = tmp->list;
	queue->last->next = NULL;
	return returnNode;
}