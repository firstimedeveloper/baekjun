#include <stdio.h>

int main(int argc, char **argv)
{
	double a, b;

	scanf("%lf %lf", &a, &b);
	printf("%.9lf", a / b);

	return (0);
}
