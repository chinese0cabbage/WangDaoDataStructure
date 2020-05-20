#pragma once
#include<malloc.h>
#include"Utils/DataUtils.h"
#define MaxSize 50
typedef struct {
	double data[MaxSize];
	int length;//顺序表的当前长度
	int maxSize;//顺序表的最大长度
}SqList;

SqList* InitSqList() {
	SqList* head;
	head = (SqList*)malloc(sizeof(SqList));
	// head->length = 50;
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
void OrderReversed(SqList* head) {
	if (head->length == 0)
		return;
	int back2mid = head->length - 1, head2mid = 0;
	while (back2mid > head2mid)
	{
		ExchangeByPointer(&head->data[head2mid++], &head->data[back2mid--]);
	}
}

//Q3,删除顺序表中所有值为x的元素
void DeleteValueX(SqList* head, double x) {
	//采用后方元素迁移覆盖的方式删除元素
	int jump = 0;
	for (int i = 0; i < head->length - jump - 1; i++)
	{
		if (head->data[i] == x) {
			if (head->data[jump + i] == x)
				jump++;
			ExchangeByPointer(&head->data[i], &head->data[jump + i]);
		}
	}
	head->length -= jump;
}

//Q4,删除有序顺序表中给定的s~t之间的所有元素，不含s和t
void DeleteValueBetweenST(SqList* head, double s, double t) {
	//先用二分法将mid跳到s和t之间，再分别向两边用二分法寻找s和t所在下标，最终将t后的元素前移至s的位置达到删除的目的
	int low = 0, high = head->length - 1, mid = (low + high) / 2, jump = mid, sP = -1, tP = -1;
	while (mid >= 0 && mid <= head->length - 1)
	{
		if (head->data[mid] <= s)
		{
			if (head->data[mid] == s)
			{
				sP = mid;
			}
			low = mid + 1;
			mid = (low + high) / 2;
			jump = mid;
			continue;
		}
		else if(head->data[mid] > t)
		{
			high = mid - 1;
			mid = (low + high) / 2;
			jump = mid;
			continue;
		}
		while (head->data[mid] != s)
		{

		}
	}
}