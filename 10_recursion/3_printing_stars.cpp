#include <iostream>

char *init(int n)
{
	char *board;
	
	board = new char[n*n];
	for (int i=0; i<n*n; i++)
	{
		if (n == 3 && i == 4)
			board[i] = ' ';
		else board[i] = '*';
	}
	return board;
}

void printStars(char *arr, int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			std::cout << arr[n*i + j];
//			if (j != n - 1)
//				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	
}

void remove_middle(char *arr, int b_size, int n, int row, int col)
{
	int start;
	int end;

	start = n / 3;
	end = n - start;
	for (int i=row + start; i<row + end; i++)
	{
		for (int j=col + start; j<col + end; j++)
		{
			arr[i*b_size + j] = ' ';
		}
	}
	
}

void recurse(char *arr, int b_size, int n, int row, int col)
{
	if (n == 3)
		return ;
	int offset = n / 3;

	remove_middle(arr, b_size, n, row, col);

	for (int i=row; i<3*offset+row; i+=offset)
	{
		for (int j=col; j<3*offset+col; j+=offset)
		{
			remove_middle(arr, b_size, n/3, i, j);
			recurse(arr, b_size, n/3, i, j);
		}
	}

}

int main()
{
	char *arr;
	int input;

	std::cin >> input;
	arr = init(input);
	recurse(arr, input, input, 0, 0);
	printStars(arr, input);
}
