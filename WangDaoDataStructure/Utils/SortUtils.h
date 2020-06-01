#pragma once
#include"DataUtils.h"

//ͨ��ֱ�Ӳ������������������,���Ҳ����λʱ������ֲ��Ҳ��������̫���ʱ������
void InsertSort(double arr[], int length) {//tested
	for (int i = 1; i < length; i++) {
		double tmp = arr[i];
		int j = i;
		while (j > 0) {
			if (arr[--j] > tmp) {
				arr[j + 1] = arr[j];
			}
			else {
				j++;
				break;
			}
		}
		arr[j] = tmp;
	}
}

//��������֮ð������
void BubbleSort(double arr[], int length) {//tested
	for (int i = 0;i < length;i++) {
		for (int j = 0;j < length - i - 1;j++) {
			if (arr[j] > arr[j + 1])
				ExchangeByPointer(&arr[j], &arr[j + 1]);
		}
	}
}

//��������֮��������
void QuickSort(double arr[], int length, int low, int high) {
	if (high <= low)
		return;
	else if (high - low == 1) {
		if (arr[high] < arr[low])
			ExchangeByPointer(&arr[high], &arr[low]);
	}
	else {
		double sentry = arr[low];
		int hole = low, originHigh = high, originLow = low;
		while (high > low) {
			while (arr[high] > sentry)
				high--;
			arr[hole] = arr[high];
			hole = high;
			while (arr[low] < sentry)
				low++;
			arr[hole] = arr[low];
			hole = low;
		}
	}
}