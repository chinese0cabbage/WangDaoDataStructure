#include"2.2SqList.h"
#include"Utils/ListUtils.h"
int main() {
	SqList* sql = InitSqList();
	for (int i = 0; i < 25; i++)
	{
		sql->data[i] = i;
	}
	sql->data[25] = 25;
	for (int i = 26; i < MaxSize; i++)
	{
		sql->data[i] = i;
	}
	sql->length = 50;
	int pos = Bisearch(sql->data, 50, 26);
	return 0;
}