#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
void test1()
{
	ST s;
	STIni(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);
	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}
	printf("\n");
}

int main()
{
	test1();
	return 0;
}

