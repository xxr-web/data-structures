#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

typedef int HDataType;

typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
}HP;

void HPIni(HP* php);
void HPDestroy(HP* php);
void Swap(HDataType* p1, HDataType* p2);
void HPAdjustUp(HDataType* a, int child);
void HPPush(HP* php, HDataType x);


