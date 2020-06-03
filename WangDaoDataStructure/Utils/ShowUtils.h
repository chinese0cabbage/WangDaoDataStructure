#pragma once
#include<stdio.h>

void ShowArray(double arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		printf("%lf\t", arr[i]);
	}
}