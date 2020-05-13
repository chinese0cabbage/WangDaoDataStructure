#include"2.2SqList.h"
#include"Utils/DataUtils.h"
int main() {
	SqList* sql = InitSqList();
	for (int i = 0; i < 25; i++)
	{
		sql->data[i] = i % 5;
	}
	/*sql->data[25] = -1;
	for (int i = 26; i < MaxSize; i++)
	{
		sql->data[i] = i;
	}*/
	sql->length = 50;
	DeleteValueX(sql, 3);
	return 0;
}