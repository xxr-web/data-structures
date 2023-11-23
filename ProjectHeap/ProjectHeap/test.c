#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void test1()
{
	HDataType arr[10] = { 2, 1, 10, 5, 3, 7, 6, 4, 9, 8 };
	HP H;
	HPIni(&H);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		HPPush(&H, arr[i]);
	}
}

int main()
{
	test1();
}