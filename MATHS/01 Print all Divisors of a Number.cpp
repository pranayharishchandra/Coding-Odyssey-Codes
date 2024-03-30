#include <iostream>
#include <vector>
#include <cmath>

void printDivisors(int n) {
    std::vector<int> divisors;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }
    std::cout << "Divisors of " << n << " are: ";
    for (int divisor : divisors) {
        std::cout << divisor << " ";
    }
    std::cout << std::endl;
}

int main() {
    int number = 24;
    printDivisors(number);
    return 0;
}
