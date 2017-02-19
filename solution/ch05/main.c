#include <stdio.h>
#include <stdlib.h>
#include <hashquad.h>

int main(int argc, char *argv[])
{
	int i, A[7] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
	HashTable H;

	if (!(H = InitializeTable(7))) {
		printf("Initialize hash table failed\n");
		return -1;
	}

	for (i = 0; i < 7; ++i)


	return 0;
}
