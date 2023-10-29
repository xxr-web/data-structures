#define _CRT_SECURE_NO_WARNINGS
#include "SQList.h"

//void test1()
//{
//	SL s1;
//	SLini(&s1);
//	SLpushback(&s1, 1);
//	SLpushback(&s1, 2);
//	SLpushback(&s1, 3);
//	SLpushback(&s1, 4);
//	SLpushback(&s1, 5);
//	SLpushback(&s1, 6);
//	SLpushback(&s1, 7);
//	SLpushback(&s1, 8);
//	SLpushback(&s1, 9);
//	SLpushfront(&s1, 10);
//	SLpushfront(&s1, 20);
//	SLpushfront(&s1, 30);
//	//SLprinttest(&s1);
//	SLprint(&s1);
//  SLdestroy(&s1);
//}
//
//void test2()
//{
//	SL s1;
//	SLini(&s1);
//	SLpushback(&s1, 1);
//	SLpushback(&s1, 2);
//	SLpushback(&s1, 3);
//	SLpushback(&s1, 4);
//	SLpushback(&s1, 5);
//	SLpushback(&s1, 6);
//	SLpushback(&s1, 7);
//	SLpushback(&s1, 8);
//	SLpushback(&s1, 9);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	SLpopback(&s1);
//	//SLpopback(&s1);
//	SLprint(&s1);
//  SLdestroy(&s1);
//}

//void test3()
//{
//	SL s1;
//	SLini(&s1);
//	SLpushback(&s1, 1);
//	SLpushback(&s1, 2);
//	SLpushback(&s1, 3);
//	SLpushback(&s1, 4);
//	SLpushback(&s1, 5);
//	SLpushback(&s1, 6);
//	SLpushback(&s1, 7);
//	SLpushback(&s1, 8);
//	SLpushback(&s1, 9);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopfront(&s1);
//	SLpopback(&s1);
//	SLprint(&s1);
//	SLdestroy(&s1);
//}

//void test4()
//{
//	SL s1;
//	SLini(&s1);
//	SLpushback(&s1, 1);
//	SLpushback(&s1, 2);
//	SLpushback(&s1, 3);
//	SLpushback(&s1, 4);
//	SLpushback(&s1, 5);
//	SLpushback(&s1, 6);
//	SLpushback(&s1, 7);
//	SLpushback(&s1, 8);
//	SLpushback(&s1, 9);
//	SLinsert(&s1, 3, 10);
//	SLinsert(&s1, 5, 10);
//	SLinsert(&s1, 8, 10);
//	SLerase(&s1, 0);
//	SLerase(&s1, 1);
//	SLerase(&s1, 2);
//	SLprint(&s1);
//	SLdestroy(&s1);
//}

void test5()
{
	SL s1;
	SLini(&s1);
	SLpushback(&s1, 1);
	SLpushback(&s1, 2);
	SLpushback(&s1, 3);
	SLpushback(&s1, 4);
	SLpushback(&s1, 5);
	SLpushback(&s1, 6);
	SLpushback(&s1, 7);
	SLpushback(&s1, 8);
	SLpushback(&s1, 9);
	int ret = SLfind(&s1, 9);
	printf("%d\n", ret);
	ret = SLfind(&s1, 10);
	printf("%d\n", ret);
	SLdestroy(&s1);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//fflush(stdin);
	//test4();
	test5();
	return 0;
}