#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	size_t lena = strlen(*(const char **)a);
	size_t lenb = strlen(*(const char **)b);
	if (lena > lenb) return 1;
	if (lena < lenb) return -1;
	return (strcmp(*(const char **)a, *(const char **)b));
}

int main()
{
	char	**words;
	int		num;
	char	temp[50];
	char	*prev;
	scanf("%d", &num);
	words = malloc(sizeof(char *) * (num));
	for (int i=0; i<num; i++)
	{
		scanf("%s", temp);
		words[i] = strdup(temp);
	}
	qsort(words, num, sizeof words[0], compare);
	for (int i=0; i<num; i++)
	{
		if (prev && strcmp(words[i], prev) == 0)
			continue;
		printf("%s\n", words[i]);
		prev = words[i];
	}
	for (int i=0; i<num; i++)
		free(words[i]);
	free(words);
	return (0);
}
