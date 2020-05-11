#pragma once
#include<malloc.h>
#define MaxSize 50
typedef struct {
	double data[MaxSize];
	int length;//顺序表的当前长度
	int maxSize;//顺序表的最大长度
}SqList;

SqList* InitSqList() {
	SqList* head;
	head = (SqList*)malloc(sizeof(SqList));
	head->length = 50;
	head->maxSize = MaxSize;
	return head;
}

//以下为2.2.3.二的综合应用题 P19

//Q1,删除顺序表中的最小值
double PopMin(SqList* head) {
	if (head->length == 0)
	{
		return 0;//顺序表为空，退出
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

//Q2,逆置顺序表中的元素