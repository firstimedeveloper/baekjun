#include <stdio.h>
#include <stdlib.h>

typedef struct s_Data
{
	int ok;
	int val;
	int zero;
	int one;
} Data;

Data fibonacci(Data *arr, int n)
{
    if (n == 0)
	{
        return (Data){.zero=1, .one=0};
    }
	else if (n == 1)
	{
        return (Data){.zero=0, .one=1};
    }
	else if (arr[n].ok)
	{
		return arr[n];
	}
	else {
		Data ret;
		Data temp1 = fibonacci(arr, n-1);
		Data temp2 = fibonacci(arr, n-2);
		ret.zero = temp1.zero + temp2.zero;
		ret.one = temp1.one + temp2.one;
		ret.ok = 1;
		arr[n] = ret;
		return ret;
    }
}

int main()
{
	int n;
	int temp;
	Data *arr;

	scanf("%d", &n);
	arr = malloc(sizeof(Data) * n);
	for (int i=0; i<41; i++)
		arr[i].ok = 0;
	for (int i=0; i<n; i++)
	{
		Data data;
		scanf("%d", &temp);
		data = fibonacci(arr, temp);
		printf("%d %d\n", data.zero, data.one);
	}
}
