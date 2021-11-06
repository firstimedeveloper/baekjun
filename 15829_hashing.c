#include <stdio.h>
#include <stdlib.h>

int MOD = 1234567891;

unsigned long long  powll(int p)
{
	int ret;

	if (p == 0)
		return 1;
	ret = 1;
	for (int i=0; i<p; i++)
	{
		ret *= 31;
	}
	return ret;
}

int main()
{
	char *str;
	int len;
	unsigned long long sum;
	unsigned long long r;
	unsigned long long a;

	sum = 0;
	scanf("%d", &len);
	str = malloc(sizeof(char) * (len + 1));
	scanf("%s", str);
	int i = 0;
	r = 1;
	while (*str)
	{
		a = *str - 'a' + 1;
		sum = (sum + a * r) % MOD;
		r = (r * 31) % MOD;
		str++;
		i++;
	}
	printf("%llu\n", sum);

}
