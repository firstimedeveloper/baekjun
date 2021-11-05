#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numCards, max, min;
	int *cards;
	int a, b, c;

	scanf("%d %d", &numCards, &max);
	cards = malloc(sizeof(int) * numCards);
	for (int i=0; i<numCards; i++)
		scanf("%d", &cards[i]);

	min = 0;
	for (int i=0; i<numCards-2; i++)
	{
		a = cards[i];
		if (a > max)
			continue;
		for (int j=i+1; j<numCards-1; j++)
		{
			b = cards[j];
			if (a + b > max)
				continue;
			for (int k=j+1; k<numCards; k++)
			{
				c = cards[k];
				if (a + b + c > max)
					continue;
				if (a + b + c <= max && a + b + c > min)
					min = a + b + c;
			}
		}
	}

	printf("%d", min);
	free(cards);
}
