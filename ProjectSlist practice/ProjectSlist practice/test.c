#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void test1()
{
	SL P;
	SL* p1 = &P;
	SL** phead = &p1;
	SLIni(phead);
	SLPushBack(phead, 1);
	SLPushBack(phead, 2);
	SLPushBack(phead, 3);
	SLPushBack(phead, 4);
	SLPushBack(phead, 5);
	SLPrint(p1);
	SLPopBack(phead);
	SLPopBack(phead);
	SLPopBack(phead);
	SLPopBack(phead);
	SLPopBack(phead);
	SLPrint(p1);
}

void test2()
{
	SL P;
	SL* p1 = &P;
	SL** phead = &p1;
	SLIni(phead);
	SLPushFront(phead, 1);
	SLPushFront(phead, 2);
	SLPushFront(phead, 3);
	SLPushFront(phead, 4);
	SLPushFront(phead, 5);
	SLPrint(p1);
	SLPopFront(phead);
	SLPopFront(phead);
	SLPopFront(phead);
	SLPopFront(phead);
	SLPopFront(phead);
	SLPrint(p1);
}

void test3()
{
	SL P;
	SL* p1 = &P;
	SL** phead = &p1;
	SLIni(phead);
	SLPushBack(phead, 1);
	SLPushBack(phead, 2);
	SLPushBack(phead, 3);
	SLPushBack(phead, 4);
	SLPushBack(phead, 5);
	SL* ret = SLFind(p1, 3);
	SL* ret1 = SLFind(p1, 1);
	printf("%d\n", ret->val);
	//SLErase(phead, ret);
	SLErase(phead, ret1);
	SLInsert(phead, 100, ret);
	SLPrint(p1);
}

int main()
{
	//test1();
	//test2();
	test3();
}