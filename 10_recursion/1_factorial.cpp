// https://www.acmicpc.net/problem/10872

#include <iostream>

int factorial(int num) {
	if(num == 0 || num == 1) {
		return 1;
	} else {
		return factorial(num - 1) * num;
	}
}

int main() {
	int input;
	std::cin >> input;
	std::cout << factorial(input);
	
}
