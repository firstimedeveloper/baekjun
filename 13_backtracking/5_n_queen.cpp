#include <iostream>

int valid_square(int *board, int board_size, int col, int row)
{
	int i;

	i = 1;
	while (i < col + 1)
	{
		if (board[col - i] == row)
			return 0;
		if (board[col - i] == row + i)
			return 0;
		if (board[col - i] == row - i)
			return 0;
		i++;
	}
	return 1;
}

void print_board(int *board, int board_size)
{
	for (int i=0; i<board_size; i++)
	{
		std::cout << board[i] << " ";
	}
	std::cout << "\n";
}

void recurse(int *board, int board_size, int col, int &count)
{
	if (col == board_size)
	{
		// print_board(board, board_size);
		count++;
	}
	for (int i=0; i<board_size; i++)
	{
		if (valid_square(board, board_size, col, i))
		{
			board[col] = i;
			recurse(board, board_size, col + 1, count);
		}
	}
}

int main()
{
	int *board;
	int board_size;
	int count;

	std::cin >> board_size;

	// initialize board;
	board = new int[board_size];
	for (int i=0; i<board_size; i++)
		board[i] = 0;
	count = 0;
	recurse(board, board_size, 0, count);
	std::cout << count;
}
