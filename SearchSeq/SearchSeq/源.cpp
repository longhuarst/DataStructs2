#include <iostream>


using namespace std;


typedef int ElemType;

typedef struct {

	ElemType *elem;

	int TableLen;

}SSTable;

int Search_Seq(SSTable ST, ElemType key)
{
	ST.elem[0] = key;

	int i;

	for (i = ST.TableLen; ST.elem[i] != key; --i);

	return i;
}


int main()
{

















	system("pause");


}


