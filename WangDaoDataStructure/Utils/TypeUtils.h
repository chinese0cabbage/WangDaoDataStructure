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

typedef struct TreeNode {
	int Pos;
	double val;
	struct TreeNode* LeftChild, * RightChild;
}TreeNode;

enum CommandType
{
	Cancel = 0,
	Get = 1,
	End = 2,
	Left = 3,
	Right = 4,
};

enum Confirm
{
	No,
	Yes,
};

typedef struct TreeNodeStack {
	TreeNode* StackClooector[500];
}TreeNodeStack;