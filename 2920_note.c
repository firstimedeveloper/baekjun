#include <stdio.h>

int main()
{
	int prev;
	int dir; //0 asc, 1 desc, 2 mix
	int a;
	
	scanf("%d", &a);
	if (a == 1)
		dir = 0;
	else if (a == 8)
		dir = 1;
	else
	{
		printf("mixed");
		return (0);
	}

	for (int i=0; i<7; i++)
	{
		prev = a;
		scanf("%d", &a);
		if (!dir && a >= prev)
			continue;
		if (dir && a <= prev)
			continue;
		dir = 2;
		break;
	}

	switch (dir)
	{
		case 0:
			printf("ascending");
			break;
		case 1:
			printf("descending");
			break;
		case 2:
			printf("mixed");
			break;
	}
	return (0);
}
