#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
//typedef struct Stu
//{
//	int i;
//	char a;
//}stu, *ptr;
//
////stu相当于struct Stu, ptr相当于struct Stu*
//int main()
//{
//	stu s1 = { { 1 }, { 'a' } };
//	ptr p1 = &s1;
//	printf("%d %c", p1->i, p1->a);
//	return 0;
//}

void test1()
{
	SLNode* SList = NULL;
	SLTpushback(&SList, 1);
	SLTpushback(&SList, 2);
	SLTpushback(&SList, 3);
	SLTpushback(&SList, 4);
	SLTprint(SList);
	SLTPopBack(&SList);
	SLTprint(SList);
	SLTPopBack(&SList);
	SLTprint(SList);
	SLTPopBack(&SList);
	SLTprint(SList);
	SLTPopBack(&SList);
	SLTprint(SList);
	/*SLTPopBack(&SList);
	SLTprint(SList);*/
}

void test2()
{
	SLNode* SList = NULL;
	SLTpushFront(&SList, 1);
	SLTpushFront(&SList, 2);
	SLTpushFront(&SList, 3);
	SLTpushFront(&SList, 4);
	SLTprint(SList);
	SLTPopFront(&SList);
	SLTprint(SList);
	SLTPopFront(&SList);
	SLTprint(SList);
	SLTPopFront(&SList);
	SLTprint(SList);
	SLTPopFront(&SList);
	SLTprint(SList);
}
int main()
{
	//test1();
	//test2();
	/*int b = 2;
	int a = b;
	b = 3;
	printf("%d\n", a);*/
	int a = 3, b = 10;
	int c = abs(a - b);
	printf("%d\n", c);
	return 0;
}
