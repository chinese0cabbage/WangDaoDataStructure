#pragma once
#include<malloc.h>
#include"TypeUtils.h"

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

//���Ҳ����������������е�Ԫ����������Ԫ��֮�䣬����������Ԫ�ص��±꣬item2Ϊ�ϴ�ĵ��±�,������ǰԪ�ص�ֵ������������ֵ���򷵻�<-1,length-1>����С����Сֵ���򷵻�<0,-1>
Tuple* SearchAmongSubscript(double arr[], int length, double goal) {//tested
	int high = length - 1, low = 0, mid = (high + low) / 2;
	if (goal > arr[length - 1]) {
		low = length - 1;
		high = -1;
	}
	else if (goal < arr[0]) {
		high = 0;
		low = -1;
	}
	else {
		while (high - low > 1) {
			if (arr[mid] > goal)
				high = mid - 1;
			else
				low = mid + 1;
			mid = (high + low) / 2;
		}
	}
	Tuple* tuple = (Tuple*)malloc(sizeof(Tuple));
	tuple->item1 = low;
	tuple->item2 = high;
	return tuple;
}