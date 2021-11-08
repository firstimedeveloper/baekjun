#include <stdio.h>

int _gcd(int a, int b)
{
	if (b == 0)
		return a;
	return _gcd(b, a % b);
}

int main()
{
	int a, b;
	int gcd, lcm;

	scanf("%d %d", &a, &b);
	gcd = _gcd(a, b);
	printf("%d\n", gcd);
	printf("%d", a * b / gcd);
}
