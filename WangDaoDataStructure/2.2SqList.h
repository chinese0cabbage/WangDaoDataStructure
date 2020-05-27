#pragma once
#include<malloc.h>
#include<math.h>
#include"Utils/DataUtils.h"
#include "Utils/ListUtils.h"
#include"Utils/TypeUtils.h"

SqList* InitSqList() {
	SqList* head;
	head = (SqList*)malloc(sizeof(SqList));
	// head->length = 50;
	head->maxSize = MaxSize;
	return head;
}

//����Ϊ2.2.3.�����ۺ�Ӧ���� P19

//Q1,ɾ��˳����е���Сֵ,tested
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

//Q2,����˳����е�Ԫ��,tested
void OrderReversed(SqList* head) {
	ReversedLimitOrder(head->data, 0, head->length - 1);
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
void DeleteOrderedValueBetweenST(SqList* head, double s, double t) {
	if (head->length == 0 || s > t)
		return;
	//���ö��ַ���mid����s��t֮�䣬�ٷֱ��������ö��ַ�Ѱ��s��t�����±꣬���ս�t���Ԫ��ǰ����s��λ�ôﵽɾ����Ŀ��
	int low = 0, high = head->length - 1, mid = (low + high) / 2, jump = mid, sP = -1, tP = -1;
	while (mid >= 0 && mid <= head->length - 1)
	{
		if (sP == -1 && head->data[mid] <= s)
		{//��ǰֵС����С�㣬����Ǩ��,sP�ѱ���ֵ������
			if (head->data[mid] == s)
				sP = mid;
			low = mid + 1;
			jump = abs((low + high) / 2 - mid);
			mid = (low + high) / 2;
			continue;
		}
		else if (tP == -1 && head->data[mid] >= t)
		{//��ǰֵ�������㣬����Ǩ��,eP�ѱ���ֵ������
			if (head->data[mid] == t)
				tP = mid;
			high = mid - 1;
			jump = abs((low + high) / 2 - mid);
			mid = (low + high) / 2;
			continue;
		}
		else if (sP == -1)
		{//ǰ�����ж϶���������֤���Ѿ�Ǩ�Ƶ�s~t֮��
			sP = Bisearch(head->data, s, mid, mid - jump);
		}
		else if (tP == -1)
		{//ǰ�����ж϶���������֤���Ѿ�Ǩ�Ƶ�s~t֮��
			tP = Bisearch(head->data, t, mid + jump, mid);
		}
		else
			break;
		sP++;
		while (tP < head->length) {
			head->data[sP++] = head->data[tP++];
		}
		head->length -= (tP - sP - 1);
	}
}

//Q5,ɾ������˳����д�С��s~t֮���Ԫ��
void DeleteDisorderedValueBetweenST(SqList* head, double s, double t) {

}

//Q6,������˳�����ɾ��ֵ�ظ���Ԫ��
void DeleteRepeate(SqList* head) {
	int nextInsert = 1;
	double curElem = head->data[0];
	for (int i = 1; i < head->length; i++)
	{
		if (curElem == head->data[i])
			continue;
		else
		{
			head->data[nextInsert++] = head->data[i];
			curElem = head->data[i];
			head->length--;
		}
	}
}

//Q7,����˳���ϲ���һ��˳���������˳�����Ϊ��������ֵ
SqList* Combine2OrderedSqList(SqList* list1, SqList* list2) {
	SqList* head = (SqList*)malloc(sizeof(SqList));
	head->length = list1->length + list2->length;
	int i1 = 0, i2 = 0, i = 0;
	while (i1 < list1->length || i2 < list2->length)
	{
		if (i1 < list1->length && i2 < list2->length)
		{
			if (list1->data[i1] > list2->data[i2])
				head->data[i++] = list2->data[i2++];
			else
				head->data[i++] = list1->data[i1++];
		}
		else
		{
			if (i1 < list1->length)
				head->data[i++] = list1->data[i1++];
			else
				head->data[i++] = list2->data[i2++];
		}
	}
	return head;
}

//Q8,��֪����Ŀ������ʲô

//Q9,����ֵ���Ա���ΪX��Ԫ�ز������Ԫ�ػ������������������벢��ԭ���Ա�����
void SearchX(double arr[],int length, double x) {
	int pos = Bisearch(arr, x, length - 1);
	if (pos == -1)
	{
		arr[length] = x;
		for (int i = length - 1; i >= 0; i--)
		{
			if (arr[i] > x)
			{
				arr[i + 1] = arr[i];
			}
			else
			{
				arr[i + 1] = x;
				break;
			}
		}
	}
	else 
	{
		if (pos != length - 1)
			ExchangeByPointer(&arr[pos], &arr[pos + 1]);
	}
}

//Q10,��һά����ѭ������p����λ,�������Ϊ2*n/2=n,ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1),û���������ռ�,tested
void LeftMovePPosition(SqList* head, int p) {
	if (p <= 0)
		return;
	ReversedLimitOrder(head->data, 0, p - 1);//����ǰp��Ԫ��
	ReversedLimitOrder(head->data, p, head->length - 1);//�����length-p-1��Ԫ��
	ReversedLimitOrder(head->data, 0, head->length - 1);//������������
}

//Q11,Ѱ�������ȳ��������λ��
int SeachMidNum(int arr1[], int arr2[], int length) {
	int goal = length - 1, sentry1 = 0, sentry2 = 0;
	if (arr1[goal / 2] > arr2[goal / 2]) {
		sentry2 = goal / 2;
	}
	return 0;
}