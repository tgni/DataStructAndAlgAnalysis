#include <stdio.h>
#include <stdlib.h>

static int NextPrime( int N )
{
	int i;

	if (++N % 2 == 0)
		++N;

	for ( ; ; N += 2 ) {
		for ( i = 3; i * i <= N; i += 2 )
			if ( N % i == 0 )
				goto ContOuter;
		return N;
ContOuter: ;
	}
}

static int CheckPrime( int N )
{
	return 0;
}

/* Print all prime less than N */
static void PrintPrime(int N)
{
	int i = 2;
	
	while (i < N) {
		printf("%u ", i);
		i = NextPrime(i);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int i, N;

	if (argc != 2) {
		printf("Usage: ./test <NUM>\n");
	}

	N = strtoul(argv[1], NULL, 0);

	PrintPrime(N);

	return 0;
}
