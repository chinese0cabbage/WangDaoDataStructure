#pragma once
#include"DataUtils.h"

//逆序下标在low和high之间的元素（包含low和high）
void ReversedLimitOrder(double arr[], int low, int high) {//tested
	while (high > low) {
		ExchangeByPointer(&arr[high--], &arr[low++]);
	}
}