#pragma once
//通过交换指针将两个数的数值交换(需要创建临时变量)
void ExchangeByPointer(double* a, double* b) {//tested
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

//通过巧妙的运算将两个数的数值交换(不需要创建临时变量)
void ExchangeByValue(double* a, double* b) {//tested
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

//通过异或运算交换两个整数的数值(不需要创建临时变量)
void ExchangeByBit(int* a, int* b) {//tested
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}