#pragma once
#include"DataUtils.h"

//�����±���low��high֮���Ԫ�أ�����low��high��
void ReversedLimitOrder(double arr[], int low, int high) {//tested
	while (high > low) {
		ExchangeByPointer(&arr[high--], &arr[low++]);
	}
}