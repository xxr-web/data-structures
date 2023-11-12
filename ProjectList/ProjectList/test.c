#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
void TestList1()
{
	LTNode* plist = LTIni();
	LTPushback(plist, 1);
	LTPushback(plist, 2);
	LTPushback(plist, 3);
	LTPushback(plist, 4);
	LTPushback(plist, 5);
	LTPrint(plist);
	LTPopback(plist);
	LTPopback(plist);
	LTPopback(plist);
	LTPopback(plist);
	LTPopback(plist);
	LTPrint(plist);
}

int main()
{
	TestList1();
}