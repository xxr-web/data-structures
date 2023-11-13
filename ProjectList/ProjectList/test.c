#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

void test1()
{
	LT* listnode = LTIni();
	LTPushBack(listnode, 1);
	LTPushBack(listnode, 2);
	LTPushBack(listnode, 3);
	LTPushBack(listnode, 4);
	LTPushBack(listnode, 5);
	LTPrint(listnode);
	LTPopBack(listnode);
	LTPopBack(listnode);
	LTPopBack(listnode);
	LTPopBack(listnode);
	LTPopBack(listnode);
	LTPrint(listnode);
	LTPushFront(listnode, 1);
	LTPushFront(listnode, 2);
	LTPushFront(listnode, 3);
	LTPushFront(listnode, 4);
	LTPushFront(listnode, 5);
	LTPrint(listnode);
	LTPopFront(listnode);
	LTPopFront(listnode);
	LTPopFront(listnode);
	LTPopFront(listnode);
	LTPopFront(listnode);
	LTPrint(listnode);
}

void test2()
{
	LT* listnode = LTIni();
	LTPushBack(listnode, 1);
	LTPushBack(listnode, 2);
	LTPushBack(listnode, 3);
	LTPushBack(listnode, 4);
	LTPushBack(listnode, 5);
	LTPrint(listnode);
	LT* findnode = LTFind(listnode, 5);
	LTInsert(100, findnode);
	LTInsert(100, listnode);
	LTPrint(listnode);
	LTErase1(listnode);
	listnode = NULL;
	LTErase1(findnode);
	findnode = NULL;
	LTPrint(listnode);
	LTErase2(findnode);
	findnode = NULL;
	LTPrint(listnode);
}

void test3()
{
	LT* listnode = LTIni();
	LTPushBack(listnode, 1);
	LTPushBack(listnode, 2);
	LTPushBack(listnode, 3);
	LTPushBack(listnode, 4);
	LTPushBack(listnode, 5);
	//LTErase2(listnode);
	//listnode = NULL;//这样已经避免了不能传入哨兵位。
	LTPrint(listnode);
	LTDestroy(listnode);
	listnode = NULL;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}