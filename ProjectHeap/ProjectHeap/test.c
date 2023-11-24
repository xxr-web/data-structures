#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void test1()
{
	HP heap;
	HP* h = &heap;
	HPIni(h);
	int arr[10] = { 17, 21, 25, 100, 300, 3, 10, 212, 1000, 10000 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		HPPush(h, arr[i]);
	}
	printf("%d\n", HPSize(h));
	while (!HPEmpty(h))
	{
		printf("%d ", HPTop(h));
		HPPop(h);
	}
	printf("\n");
	printf("%d\n", HPSize(h));
	HPDestroy(h);
}

int main()
{
	test1();
	return 0;
}