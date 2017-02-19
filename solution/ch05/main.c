#include <stdio.h>
#include <stdlib.h>
#include <hashquad.h>
#include "tool.h"

int main(int argc, char *argv[])
{
	int i, A[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989, 100, 200, 300, 400};
	HashTable H;

	if (!(H = InitializeTable(NELEMS(A)))) {
		printf("Initialize hash table failed\n");
		return -1;
	}

	for (i = 0; i < NELEMS(A); ++i)
		Insert(A[i], H);

	for (i = 0; i < NELEMS(A); ++i)
		printf("Element: %d Position: %d\n", A[i], Find(A[i], H));

	return 0;
}
