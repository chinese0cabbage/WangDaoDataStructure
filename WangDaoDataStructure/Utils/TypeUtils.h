#pragma once
#define MaxSize 500

typedef struct SqList {
	double data[MaxSize];
	int length;//˳���ĵ�ǰ����
	int maxSize;//˳������󳤶�
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
	TreeNode* StackCollector[MaxSize];//500��ָ�����ڵ��ָ�빹�ɵ�����
}TreeNodeCollector;

typedef struct TreeNodeList {
	TreeNode* node;
	TreeNodeList* next;
}TreeNodeList;