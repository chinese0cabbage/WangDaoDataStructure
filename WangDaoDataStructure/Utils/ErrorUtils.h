#pragma once
#include<stdlib.h>
#include<stdio.h>

enum Errors
{
	MallocError = 1 //�����ڴ�ʧ��
};

void ErrorExit(Errors errorTag) {
	switch (errorTag)
	{
	case MallocError:
		printf("�����ڴ�ʧ�ܣ�");
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}