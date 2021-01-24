// https://www.acmicpc.net/problem/2447
#include <iostream>

int fib(int n) {
	if(n == 0) return 0;
	else if(n == 1 || n == 2) return 1;
	else return fib(n-1) + fib(n-2);
}

int main() {
	int input;
	std::cin >> input;
	std::cout << fib(input);
}
