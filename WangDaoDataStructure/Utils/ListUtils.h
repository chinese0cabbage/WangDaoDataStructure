#pragma once
//���ֲ���double�����������е�goal������λ�ã����������ڣ�����-1
int Bisearch(double arr[], int length, double goal) {
	int low = 0, high = length - 1, mid = (low + high) / 2;
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