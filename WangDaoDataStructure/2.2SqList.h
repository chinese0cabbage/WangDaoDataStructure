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
	// head->length = 50;
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
		ExchangeByPointer(&head->data[head2mid++], &head->data[back2mid--]);
	}
}

//Q3,ɾ��˳���������ֵΪx��Ԫ��
void DeleteValueX(SqList* head, double x) {
	//���ú�Ԫ��Ǩ�Ƹ��ǵķ�ʽɾ��Ԫ��
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

//Q4,ɾ������˳����и�����s~t֮�������Ԫ�أ�����s��t
void DeleteValueBetweenST(SqList* head, double s, double t) {
	//���ö��ַ���mid����s��t֮�䣬�ٷֱ��������ö��ַ�Ѱ��s��t�����±꣬���ս�t���Ԫ��ǰ����s��λ�ôﵽɾ����Ŀ��
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