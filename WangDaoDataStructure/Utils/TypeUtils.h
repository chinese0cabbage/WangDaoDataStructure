#pragma once
#define MaxSize 500
typedef struct {
	double data[MaxSize];
	int length;//顺序表的当前长度
	int maxSize;//顺序表的最大长度
}SqList;

typedef struct {
	double item1;
	double item2;
}Tuple;

typedef struct {
	int Pos;
	double val;
	TreeNode* LeftChild, * RightChild;
}TreeNode;

typedef enum CommandType
{
	Cancel = 0,
	Back = 1,
	End = 2,
	Left = 3,
	Right = 4,
};

typedef struct {
	TreeNode* StackClooector[500];
}TreeNodeStack;