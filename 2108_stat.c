#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int *arr;
	int n;
	int range;
	int mode;
	double avg;
	int median;
} data;

void range(data *d)
{
	d->range = (d->arr[d->n-1] - d->arr[0]);
}

void avg(data *d)
{
	double total;

	if (d->n == 1)
	{
		d->avg = d->arr[0];
		return ;
	}
	total = 0;
	for (int i=0; i<d->n; i++)
		total += d->arr[i];
	d->avg = round(total / d->n);
}

void median(data *d)
{
	d->median = d->arr[d->n / 2];
}

int compare(const void *a, const void *b)
{
	return (*(int *)a > *(int *)b ? 1 : -1);
}

void parray(int *arr, int n)
{
	printf("array: ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void mode(data *d)
{
	int prev = d->arr[0];
	int mode = prev;
	int cur;
	int count = 1;
	int mCount = 1;

	int modes[d->n];
	modes[0] = prev;
	int idx = -1;
	
	for (int i=1; i<d->n; i++)
	{
		cur = d->arr[i];
		printf("p:%d c:%d\n",prev, cur);
		if (prev == cur)
		{
			count++;
			if (count == mCount)
				modes[++idx] = prev;
		}
		else 
		{
			if (count > mCount)
			{
				idx = 0;
				modes[idx] = prev;
				mCount = count;
			}
			if (count == mCount && count == 1)
			{
				modes[++idx] = prev;
			}
			prev = cur;
			count = 1;
		}
	}
	parray(modes, idx+1);
	if (idx > 0)
		d->mode = modes[1];
	else
		d->mode = modes[0];

}

void init(data *d)
{
	qsort(d->arr, d->n, sizeof(*(d->arr)), compare);

	avg(d);
	median(d);
	mode(d);
	range(d);
}

int main()
{
	data d;

	scanf("%d", &d.n);
	d.arr = malloc(sizeof(int) * d.n);
	for (int i=0; i<d.n; i++)
	{
		scanf("%d", &d.arr[i]);
	}
	init(&d);

	printf("result\n");
	printf("%d\n", (int)d.avg);
	printf("%d\n", d.median);
	printf("%d\n", d.mode);
	printf("%d\n", d.range);


}
