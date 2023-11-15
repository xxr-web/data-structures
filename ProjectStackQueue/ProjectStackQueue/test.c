#define _CRT_SECURE_NO_WARNINGS
//#include "Stack.h"
#include "Queue.h"
//void test1()
//{
//	ST s;
//	STIni(&s);
//	STPush(&s, 1);
//	STPush(&s, 2);
//	STPush(&s, 3);
//	STPush(&s, 4);
//	STPush(&s, 5);
//	while (!STEmpty(&s))
//	{
//		printf("%d ", STTop(&s));
//		STPop(&s);
//	}
//	printf("\n");
//}

void test2()
{
	q p;
	QIni(&p);
	QPush(&p, 1);
	QPush(&p, 2);
	QPush(&p, 3);
	QPush(&p, 4);
	QPush(&p, 5);
	while (!QEmpty(&p))
	{
		printf("%d ", QFront(&p));
		QPop(&p);
	}
	printf("\n");
	QDestroy(&p);
}

int main()
{
	//test1();
	test2();
	return 0;
}

