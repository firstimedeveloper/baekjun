#include <iostream>

int main()
{
	int *cards;
	int numOfCards;
	int max;
	int ret;
	int temp;

	std::cin >> numOfCards >> max;

	cards = new int[numOfCards];
	for (int i=0; i<numOfCards; i++)
	{
		std::cin >> cards[i];
	}

	ret = 0;
	for (int i=0; i<numOfCards-2; i++)
	{
		for (int j=i+1; j<numOfCards-1; j++)
		{
			for (int k=j+1; k<numOfCards; k++)
			{
				temp = cards[i] + cards[j] + cards[k];
				if (temp > ret && temp <= max)
					ret = temp;
				if (ret == max)
				{
					std::cout << ret;
					return 0;
				}

			}
		}
	}
	std::cout << ret;
	return 0;
}
