#pragma once
#include"TypeUtils.h"
#include<malloc.h>
#include"ErrorUtils.h"

void InsertNode2Head(LinkedListNode* linkedList, double goal) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	LinkedListNode* head = linkedList;
	if (!newNode)
		ErrorExit(MallocError);
	newNode->val = goal;
	newNode->next = head;
	linkedList = newNode;
}