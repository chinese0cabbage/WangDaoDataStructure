#pragma once
#include"DataUtils.h"

//���ֲ���double�����������е�goal������λ�ã����������ڣ�����-1
int Bisearch(double arr[], double goal, int high = 0, int low = 0) {//tested
	int mid = (low + high) / 2;
	while (high >= low)
	{
		mid = (low + high) / 2;
		if (arr[mid] < goal)
			low = mid + 1;
		else if (arr[mid] == goal)
			return mid;
		else
			high = mid - 1;
	}
	return -1;
}

//�����±���low��high֮���Ԫ�أ�����low��high��
void ReversedLimitOrder(double arr[], int low, int high) {//tested
	while (high > low) {
		ExchangeByPointer(&arr[high--], &arr[low++]);
	}
}