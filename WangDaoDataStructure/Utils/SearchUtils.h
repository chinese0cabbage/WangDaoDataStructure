#pragma once
#include<malloc.h>
#include"TypeUtils.h"

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