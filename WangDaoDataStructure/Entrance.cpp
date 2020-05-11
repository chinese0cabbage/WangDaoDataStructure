#include"Ch2/2.2SqList.h"
int main() {
	SqList* sql = InitSqList();
	for (int i = 0; i < 25; i++)
	{
		sql->data[i] = i;
	}
	sql->data[25] = -1;
	for (int i = 26; i < MaxSize; i++)
	{
		sql->data[i] = i;
	}
	double t = PopMin(sql);
	return 0;
}