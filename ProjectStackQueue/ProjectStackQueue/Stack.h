#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>

typedef int STDataType;

typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);
void STDestroy(ST* pst);
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);
STDataType STTop(ST* pst);
bool STEmpty(ST* pst);
int STsize(ST* pst);