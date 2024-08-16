#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MIN 1000
#define MAX 9999

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to check if two numbers are permutations of each other
bool arePermutations(int a, int b) {
    char strA[5], strB[5];
    sprintf(strA, "%d", a);
    sprintf(strB, "%d", b);
    int count[10] = {0};
    for (int i = 0; strA[i]; i++) {
        count[strA[i] - '0']++;
    }
    for (int i = 0; strB[i]; i++) {
        count[strB[i] - '0']--;
        if (count[strB[i] - '0'] < 0) return false;
    }
    return true;
}

// Function to check for the desired arithmetic sequence
void findSequence() {
    int primes[5000];
    int primeCount = 0;

    // Generate all 4-digit primes
    for (int i = MIN; i <= MAX; i++) {
        if (isPrime(i)) {
            primes[primeCount++] = i;
        }
    }

    // Check for permutations and arithmetic sequences
    for (int i = 0; i < primeCount; i++) {
        for (int j = i + 1; j < primeCount; j++) {
            if (arePermutations(primes[i], primes[j])) {
                int d = primes[j] - primes[i];
                int thirdTerm = primes[j] + d;
                if (thirdTerm <= MAX && isPrime(thirdTerm) && arePermutations(primes[i], thirdTerm)) {
                    if (thirdTerm != primes[j] && thirdTerm != primes[i]) {
                        printf("Found sequence: %d, %d, %d\n", primes[i], primes[j], thirdTerm);
                        if (primes[i] != 1487) {
                            printf("The 12-digit number is: %lld\n", (long long)primes[i] * 10000000000LL + (long long)primes[j] * 100000000 + (long long)thirdTerm);
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    findSequence();
    return 0;
}
