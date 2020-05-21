#pragma once
//二分查找double型有序数组中的goal的索引位置，如若不存在，返回-1
int Bisearch(double arr[], double goal, int high = 0, int low = 0) {
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