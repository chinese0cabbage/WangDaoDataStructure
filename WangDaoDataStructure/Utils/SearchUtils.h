#pragma once
#include<malloc.h>
#include"TypeUtils.h"

//二分查找double型有序数组中的goal的索引位置，如若不存在，返回-1
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

//查找不包含在有序数组中的元素在哪两个元素之间，返回这两个元素的下标，item2为较大的的下标,如若当前元素的值大于数组的最大值，则返回<-1,length-1>，若小于最小值，则返回<0,-1>
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