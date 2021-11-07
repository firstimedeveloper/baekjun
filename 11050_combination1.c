#include <stdio.h>

int factorial(int n)
{
	int ret;

	ret = 1;
	while (n > 0)
	{
		ret *= n;
		n--;
	}
	return (ret);
}

int calc(int n, int k)
{
	int ret;

	ret = factorial(n) / (factorial(k) * factorial(n-k));
	return (ret);
}

int main()
{
	int n, k;
	int total;

	scanf("%d %d", &n, &k);
	total = calc(n, k);
	printf("%d", total);
}
