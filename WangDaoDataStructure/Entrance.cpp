#include"Utils/SortUtils.h"
#include"Utils/LinkedListUtils.h"

int main() {
	/*double arr[] = { 14, 21,19,17,9,10,11,7,6,5,5,3,1,2 };
	QuickSort(arr, 0, 13);
	return 0;*/
	LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	node->val = 19;
	node->next = NULL;
	InsertNode2Head(node, 1);
	return 0;
}