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

//以下为2.2.3.二的综合应用题 P19

//Q1,删除顺序表中的最小值,tested
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

//Q2,逆置顺序表中的元素,tested
void OrderReversed(SqList* head) {
	ReversedLimitOrder(head->data, 0, head->length - 1);
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
void DeleteOrderedValueBetweenST(SqList* head, double s, double t) {
	if (head->length == 0 || s > t)
		return;
	//先用二分法将mid跳到s和t之间，再分别向两边用二分法寻找s和t所在下标，最终将t后的元素前移至s的位置达到删除的目的
	int low = 0, high = head->length - 1, mid = (low + high) / 2, jump = mid, sP = -1, tP = -1;
	while (mid >= 0 && mid <= head->length - 1)
	{
		if (sP == -1 && head->data[mid] <= s)
		{//当前值小于最小点，向上迁移,sP已被赋值则跳过
			if (head->data[mid] == s)
				sP = mid;
			low = mid + 1;
			jump = abs((low + high) / 2 - mid);
			mid = (low + high) / 2;
			continue;
		}
		else if (tP == -1 && head->data[mid] >= t)
		{//当前值大于最大点，向下迁移,eP已被赋值则跳过
			if (head->data[mid] == t)
				tP = mid;
			high = mid - 1;
			jump = abs((low + high) / 2 - mid);
			mid = (low + high) / 2;
			continue;
		}
		else if (sP == -1)
		{//前两个判断都已跳过，证明已经迁移到s~t之间
			sP = Bisearch(head->data, s, mid, mid - jump);
		}
		else if (tP == -1)
		{//前两个判断都已跳过，证明已经迁移到s~t之间
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

//Q5,删除无序顺序表中大小在s~t之间的元素
void DeleteDisorderedValueBetweenST(SqList* head, double s, double t) {

}

//Q6,从有序顺序表中删除值重复的元素
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

//Q7,两个顺序表合并成一个顺序表，并将该顺序表作为函数返回值
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

//Q8,不知道题目在描述什么

//Q9,查找值线性表中为X的元素并与其后元素互换，如果不存在则插入并是原线性表有序
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

//Q10,将一维数组循环左移p个单位,计算次数为2*n/2=n,时间复杂度为O(n),空间复杂度为O(1),没有申请额外空间,tested
void LeftMovePPosition(SqList* head, int p) {
	if (p <= 0)
		return;
	ReversedLimitOrder(head->data, 0, p - 1);//逆序前p个元素
	ReversedLimitOrder(head->data, p, head->length - 1);//逆序后length-p-1个元素
	ReversedLimitOrder(head->data, 0, head->length - 1);//逆序整个数组
}

//Q11,寻找两个等长数组的中位数
int SeachMidNum(int arr1[], int arr2[], int length) {
	int goal = length - 1, sentry1 = 0, sentry2 = 0;
	if (arr1[goal / 2] > arr2[goal / 2]) {
		sentry2 = goal / 2;
	}
	return 0;
}