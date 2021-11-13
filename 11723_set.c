#include <stdio.h>

void printNum(long n)
{
	for(int i=0; i<32; i++)
	{
		if (i % 5 == 0)
			printf("|");
		printf("%ld", (n >> i) & 1);
	}
	printf("\n");
}

int main()
{
	char s[10];
	int m;
	long bits;


	scanf("%d", &m);
	bits = 0;
	for (int i=0; i<m; i++)
	{
		int n;
		scanf("%s", s);
		if (!strcmp(s, "all"))
		{
			bits |= ~0L;

		}
		else if (!strcmp(s, "empty"))
			bits = 0;
		else
		{
			scanf("%d", &n);
			n -= 1;
			if (!strcmp(s, "add"))
				bits |= (1L << n);
			if (!strcmp(s, "remove"))
				bits &= ~(1L << n);
			if (!strcmp(s, "check"))
				printf("\t%ld\n", (bits >> n) & 1);
			if (!strcmp(s, "toggle"))
				bits ^= 1L << n;
		}
		printNum(bits);

	}
}
