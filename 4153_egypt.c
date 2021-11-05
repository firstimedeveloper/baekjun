#include <stdio.h>

int sq(int a)
{
	return (a * a);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int is_rt(int a, int b, int c)
{
	int temp;
	if (a > c)
		swap(&a, &c);
	if (b > c)
		swap(&b, &c);

	if (c * c == b * b + a * a)
		return (1);
	return (0);
}

int main()
{
	int a, b, c;
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;
		if (is_rt(a, b, c))
			printf("right");
		else
			printf("wrong");
		printf("\n");
	}
	return (0);
}
