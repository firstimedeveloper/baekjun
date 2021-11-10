#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *weight, *height, *rank;
	int n;

	scanf("%d", &n);
	weight = malloc(sizeof(int) * n);
	height = malloc(sizeof(int) * n);
	rank = malloc(sizeof(int) * n);
	for (int i=0; i<n-1; i++)
	{
		rank[i] = 1;
		for (int j=i; j<n; j++)
		{
			
		}
	}
}
