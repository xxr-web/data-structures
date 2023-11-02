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

int main()
{
	SLNode* SList = NULL;
	SLTpushback(&SList, 1);
	SLTpushback(&SList, 2);
	SLTpushback(&SList, 3);
	SLTpushback(&SList, 4);
	SLTprint(SList);
	return 0;
}
