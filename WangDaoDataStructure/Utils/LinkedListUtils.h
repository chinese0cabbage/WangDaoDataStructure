#pragma once
#include"TypeUtils.h"
#include<malloc.h>
#include"ErrorUtils.h"

//在单链表的标头插入新节点
LinkedListNode* InsertNode2Head(LinkedListNode* linkedList, double goal) { //tested
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (!newNode)
		ErrorExit(MallocError);
	newNode->val = goal;
	newNode->next = linkedList;
	return newNode;
}

//在链表的表尾插入新节点
void InsertNode2Tail(LinkedListNode* linkedList, double goal) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)); //tested
	LinkedListNode* head = linkedList;
	if (!newNode)
		ErrorExit(MallocError);
	if (!head) {
		return;
	}
	newNode->val = goal;
	newNode->next = NULL;
	while (head->next)
		head = head->next;
	head->next = newNode;
}