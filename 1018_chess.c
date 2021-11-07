#include <stdio.h>
#include <stdlib.h>

int solve(char **arr, int i, int j)
{
	int ans;
	int count, cnt2;

	ans = arr[i][j];
	count = 0;
	cnt2 = 0;
	for (int a=i; a<i+8; a++)
	{
		for (int b=j; b<j+8; b++)
		{
			if (ans != arr[a][b])
			{
				printf("%d: [%d, %d] (%d, %d)\n", count, ans, arr[a][b], a, b);
				count++;
			}
			if ((ans == 'W' ? 'B' : 'W') != arr[a][b])
				cnt2++;
			ans = (ans == 'W') ? 'B' : 'W';
		}
		ans = (ans == 'W') ? 'B' : 'W';
	}
	printf("%d\n", count);
	return (count < cnt2 ? count : cnt2);
}

int main()
{
	char **board;
	int r, c;
	int min;

	scanf("%d %d", &r, &c);
	board = malloc(sizeof(char *) * (r));
	min = r * c;
	for (int i=0; i<r; i++)
	{
		board[i] = malloc(sizeof(char) * (c + 1));
		scanf("%s", board[i]);
	}
	for (int i=0; i<r-7; i++)
	{
		for (int j=0; j<c-7; j++)
		{
			int temp = solve(board, i, j);
			if (temp < min)
				min = temp;
		}
		printf("\n");
	}


	for (int i=0; i<r; i++)
	{
		printf("%d: ", i);
		for (int j=0; j<c; j++)
		{
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
	printf("%d", min);

	for (int i=0; i<r; i++)
	{
		free(board[i]);
	}
	free(board);
	return 0;
}
