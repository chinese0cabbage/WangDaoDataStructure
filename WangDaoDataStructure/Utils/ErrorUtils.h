#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

enum Errors
{
	MallocError = 1, //申请内存失败
	ErrorNullInput=2, //输入为空
};

void ErrorExit(Errors errorTag) {
	switch (errorTag)
	{
	case MallocError:
		printf("申请内存失败！");
		break;
	case ErrorNullInput:
		printf("函数的输入为空!");
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}