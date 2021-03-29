#include <iostream>

void print(int *arr, int size)
{
	for (int i=0; i<size; i++)
	{
		std::cout << arr[i];
		if (i != size - 1)
			std::cout << " ";
	}
	
	std::cout << "\n";
}

bool is_found(int *arr, int size, int num)
{
	for (int i=0; i<size; i++)
	{
		if (num == arr[i])
			return true;
	}
	return false;
}

void recurse(int *arr, int n, int m, int cur)
{
	if (cur >= m)
		print(arr, m);
	else
	{
		for (int i=1; i<=n; i++)
		{
		//	if (is_found(arr, cur, i))
		//		continue;
			if (i == 0 || arr[cur-1] <= i)
			{
				arr[cur] = i;
				recurse(arr, n, m, cur + 1);
			}
		}
	}
}

int main()
{
	int *arr;
	int n;
	int m;
	int temp;

	std::cin >> n >> m;
	arr = new int[n];
	for (int i=0; i<n; i++)
		arr[i] = 0;
	recurse(arr, n, m, 0);
}
