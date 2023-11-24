#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPIni(HP* php);

void HPDestroy(HP* php);

void Swap(HPDataType* p1, HPDataType* p2);

void HPAdjustUp(HPDataType* p, int x);

void HPPush(HP* php, HPDataType x);

void HPAdjustDown(HP* p, int parent);

void HPPop(HP* php);

bool HPEmpty(HP* php);

HPDataType HPTop(HP* php);

int HPSize(HP* php);


