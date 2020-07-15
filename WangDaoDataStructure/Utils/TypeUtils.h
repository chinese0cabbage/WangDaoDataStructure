#pragma once
#define MaxSize 500

typedef struct SqList {
	double data[MaxSize];
	int length;//顺序表的当前长度
	int maxSize;//顺序表的最大长度
}SqList;

typedef struct LinkedListNode {
	double val;
	LinkedListNode* next;
}LinkedListNode;

typedef struct Tuple {
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

typedef struct TreeNodeCollector {
	TreeNode* StackCollector[MaxSize];//500个指向树节点的指针构成的数组
}TreeNodeCollector;

typedef struct TreeNodeList {
	TreeNode* node;
	TreeNodeList* next;
}TreeNodeList;