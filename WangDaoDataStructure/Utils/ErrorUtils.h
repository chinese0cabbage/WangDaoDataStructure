#pragma once
#include<stdlib.h>
#include<stdio.h>

enum Errors
{
	MallocError = 1 //ÉêÇëÄÚ´æÊ§°Ü
};

void ErrorExit(Errors errorTag) {
	switch (errorTag)
	{
	case MallocError:
		printf("ÉêÇëÄÚ´æÊ§°Ü£¡");
		break;
	default:
		break;
	}
	exit(EXIT_FAILURE);
}