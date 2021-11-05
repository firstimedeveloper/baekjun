#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_palindrome(char *s)
{
	size_t len = strlen(s);
	size_t i = 0;
	while (i < len / 2)
	{
		if (s[i] != s[len - i - 1])
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	char temp[6];
	while (1)
	{
		scanf("%s", temp);
		if (strcmp(temp, "0") == 0)
			break;
		if (is_palindrome(temp))
			printf("yes");
		else
			printf("no");
		printf("\n");
	}

}
