#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void test1()
{
	SqL p;
	SqLIni(&p);
	SqLPushBack(&p, 1);
	SqLPushBack(&p, 2);
	SqLPushBack(&p, 3);
	SqLPushBack(&p, 4);
	SqLPushBack(&p, 5);
	SqLPopBack(&p);
	SqLPopBack(&p);
	SqLPopBack(&p);
	SqLPopBack(&p);
	SqLPopBack(&p);
	SqLPushFront(&p, 1);
	SqLPushFront(&p, 2);
	SqLPushFront(&p, 3);
	SqLPushFront(&p, 4);
	SqLPushFront(&p, 5);
	SqLPopFront(&p);
	SqLPopFront(&p);
	SqLPopFront(&p);
	SqLPopFront(&p);
	SqLPopFront(&p);
	SqLPrint(&p);
}

void test2()
{
	SqL p;
	SqLIni(&p);
	SqLPushBack(&p, 1);
	SqLPushBack(&p, 2);
	SqLPushBack(&p, 3);
	SqLPushBack(&p, 4);
	SqLPushBack(&p, 5);
	int ret1 = SqLFind(&p, 3);
	printf("%d\n", ret1);
	int ret2 = SqLFind(&p, 4);
	printf("%d\n", ret2);
	int ret3 = SqLFind(&p, 10);
	printf("%d\n", ret3);
	SqLDelete(&p, 2);
	SqLDelete(&p, 0);
	SqLPrint(&p);
	SqLInsert(&p, 0, 1);
	SqLInsert(&p, 2, 3);
	SqLPrint(&p);
	SqLDestroy(&p);
}
int main()
{
	//test1();
	test2();
	return 0;
}