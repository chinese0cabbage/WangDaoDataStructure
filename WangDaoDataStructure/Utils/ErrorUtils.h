#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

enum Errors
{
	MallocError = 1, //�����ڴ�ʧ��
	ErrorNullInput=2, //����Ϊ��
};

void ErrorExit(Errors errorTag) {
	switch (errorTag)
	{
	case MallocError:
		printf("�����ڴ�ʧ�ܣ�");
		break;
	case ErrorNullInput:
		printf("����������Ϊ��!");
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}