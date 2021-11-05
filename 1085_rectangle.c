#include <stdio.h>

int main()
{
	int x, y, w, h;
	int min;
	int temp;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	min = (x < w - x) ? x : w - x;
	temp = (y < h - y) ? y : h - y;
	min = (min < temp) ? min : temp;

	printf("%d", min);
	return (0);
}
