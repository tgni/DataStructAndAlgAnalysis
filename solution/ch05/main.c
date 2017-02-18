#include <stdio.h>
#include <stdlib.h>
#include "hashsep.h"

#define EMPTY	(-1)

/* Hash function for ints */
static Index Hash( ElementType Key, int TableSize)
{
	return Key % TableSize;
}


static Index LinearHash(ElementType Key, int collision, int TableSize)
{
	return (Hash(Key, TableSize) + collision) % TableSize;
}


static Index LinearInsert(ElementType Key, int A[], int TableSize)
{
	int c = 0, idx;

	idx = Hash(Key, TableSize);
	while (A[idx] != EMPTY) 
		idx = LinearHash(Key, ++c, TableSize);
	A[idx] = Key;

	return idx;
}

static Index QuadHash(ElementType Key, int collision, int TableSize)
{
	return (Hash(Key, TableSize) + collision * collision) % TableSize;
}

static Index QuadInsert(ElementType Key, int A[], int TableSize)
{
	int c = 0, idx;

	idx = Hash(Key, TableSize);
	while (A[idx] != EMPTY) 
		idx = QuadHash(Key, ++c, TableSize);
	A[idx] = Key;

	return idx;
}

static Index SecondHash(ElementType Key, int collision, int TableSize)
{
	return (Hash(Key, TableSize) + collision * (7 - (Key % 7))) % TableSize;
}

static Index SecondInsert(ElementType Key, int A[], int TableSize)
{
	int c = 0, idx;

	idx = Hash(Key, TableSize);
	while (A[idx] != EMPTY) 
		idx = QuadHash(Key, ++c, TableSize);
	A[idx] = Key;

	return idx;
}



int main(int argc, char *argv[])
{
	int i, A[7] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
	int H[10];

	for (i = 0; i < 10; ++i)
		H[i] = EMPTY;

	printf("Separate Chaining: ");
	for (i = 0; i < 7; ++i)
		printf("%u ", Hash(A[i], 10));
	printf("\n");

	printf("linear probing:");
	for (i = 0; i < 7; ++i)
		printf("%u ", LinearInsert(A[i], H, 10));
	printf("\n");

	for (i = 0; i < 10; ++i)
		H[i] = EMPTY;

	printf("quadratic probing:");
	for (i = 0; i < 7; ++i)
		printf("%u ", QuadInsert(A[i], H, 10));

	printf("\n");

	for (i = 0; i < 10; ++i)
		H[i] = EMPTY;

	printf("Second hash:");
	for (i = 0; i < 7; ++i)
		printf("%u ", SecondInsert(A[i], H, 10));

	printf("\n");

	return 0;
}
