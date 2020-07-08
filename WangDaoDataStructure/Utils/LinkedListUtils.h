#pragma once
#include"TypeUtils.h"
#include<malloc.h>
#include"ErrorUtils.h"

LinkedListNode* InsertNode2Head(LinkedListNode* linkedList, double goal) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (!newNode)
		ErrorExit(MallocError);
	newNode->val = goal;
	newNode->next = linkedList;
	return newNode;
}

void InsertNode2Tail(LinkedListNode* linkedList, double goal) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
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