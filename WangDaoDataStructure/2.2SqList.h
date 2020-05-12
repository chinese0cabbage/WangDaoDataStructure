#pragma once
#include<malloc.h>
#include"Utils/DataUtils.h"
#define MaxSize 50
typedef struct {
	double data[MaxSize];
	int length;//˳���ĵ�ǰ����
	int maxSize;//˳������󳤶�
}SqList;

SqList* InitSqList() {
	SqList* head;
	head = (SqList*)malloc(sizeof(SqList));
	head->length = 50;
	head->maxSize = MaxSize;
	return head;
}

//����Ϊ2.2.3.�����ۺ�Ӧ���� P19

//Q1,ɾ��˳����е���Сֵ
double PopMin(SqList* head) {
	if (head->length == 0)
	{
		return 0;//˳���Ϊ�գ��˳�
	}
	double min = head->data[0];
	int pos = 0;
	for (int i = 1; i < head->length; i++)
	{
		if (min > head->data[i])
		{
			min = head->data[i];
			pos = i;
		}
	}
	if (pos == head->length - 1)
	{
		head->data[pos] = 0;
	}
	else
	{
		head->data[pos] = head->data[head->length - 1];
		head->data[head->length - 1] = 0;
	}
	head->length--;
	return min;
}

//Q2,����˳����е�Ԫ��
void OrderReversed(SqList* head) {
	if (head->length == 0)
		return;
	int back2mid = head->length - 1, head2mid = 0;
	while (back2mid > head2mid)
	{
		ExchangeByPointer(&head->data[head2mid], &head->data[back2mid]);
		back2mid--;head2mid++;
	}
}

//Q3,ɾ��˳���������ֵΪx��Ԫ��
