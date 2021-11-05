#include <iostream>
#include <math.h>
#include <array>

int main()  {
    int a, b;

    std::array<int, 1000001> primes = {0, 1};
    int idx = 0;

    std::cin >> a >> b;

    for(int i=2; i<=sqrt(b); i++) {
		if (!primes[i])
        	for(int j=i*2; j <= b; j+=i) {
            	primes[j] = 1;
       	 	}
    }

    for(int i=a; i<=b; i++) {
        if(!primes[i])
            std::cout << i << "\n";
    }
}
