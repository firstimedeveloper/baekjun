#include <stdio.h>

int find_gen(int n)
{
	int ret;
	ret = n;
	while (n > 0)
	{
		ret += n % 10;
		n /=10;
	}
	return ret;
}

int main()
{
	int num;
	int sol;
	int i = 1;

	scanf("%d", &num);
	while (i < num)
	{
		sol = find_gen(i);
		if (num == sol)
			break;
		i++;
	}
	if (num != sol)
		printf("0");
	else
		printf("%d", i);

}
