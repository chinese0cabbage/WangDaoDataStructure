#pragma once
//ͨ������ָ�뽫����������ֵ����(��Ҫ������ʱ����)
void ExchangeByPointer(double* a, double* b) {
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

//ͨ����������㽫����������ֵ����(����Ҫ������ʱ����)
void ExchangeByValue(double* a, double* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

//ͨ��������㽻��������������ֵ(����Ҫ������ʱ����)
void ExchangeByBit(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}