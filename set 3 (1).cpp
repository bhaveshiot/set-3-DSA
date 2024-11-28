          #include <iostream>
#include <cmath>
#include <vector>

// Function to check if a number is square-free
bool isSquareFree(int x) {
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % (i * i) == 0) {
            return false; // If divisible by a perfect square greater than 1, it's not square-free
        }
    }
    return true;
}

// Function to find and count square-free divisors of N
int countSquareFreeDivisors(int N) {
    int count = 0;
    
    // Loop through all divisors from 2 to sqrt(N)
    for (int i = 2; i <= N; ++i) {
        if (N % i == 0) {  // If i is a divisor of N
            if (isSquareFree(i)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;
    std::cin >> N;
    
    // Output the count of square-free divisors of N
    std::cout << countSquareFreeDivisors(N) << std::endl;
    
    return 0;
}
                                                                   
