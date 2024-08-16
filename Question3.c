/*3. A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding
the number itself.
For instance, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6; so 6 is a perfect
number.
A number n is called deficient if the sum of its proper divisors is less than n and it is called
abundant if this sum exceeds n.
For instance, 12 has divisors 1, 2, 3, 4, and 6 (excluding itself), and 1 + 2 + 3 + 4 + 6 = 16; so
12 is an abundant number.
(a) Write a C program to check a given number is a perfect number/deficient/abundant.
(b) By mathematical analysis, it can be shown that all integers greater than 28123 can be
written as the sum of two abundant numbers. However, this upper limit cannot be reduced
any further by analysis, even though it is known that the greatest number that cannot be
expressed as the sum of two abundant numbers is less than this limit. Find the sum of all
the positive integers which cannot be written as the sum of two abundant numbers.*/

#include <stdio.h>
#include <math.h>

int divisorSum(int x) {
    int sum = 0;
    for (int i = 1; i*i <= x; i++) {
        if (x % i == 0) {
            sum = sum+i;
            if(x/i != i && i != 1){
                sum = sum + x/i;
            }
        }   
    }
    return sum;
}

int main() {
    int n;
    printf("Enter the value to check :");
    scanf("%d", &n);
    int sum = divisorSum(n);
    if(sum < n){
        printf("The number is deficient");
    }
    else if(sum == n){
        printf("The number is perfect");
    }
    else{
        printf("The number is abundant");
    }

    return 0;
}



b)

#include <stdio.h>
#include <stdbool.h>

#define LIMIT 28123

// Function to calculate the sum of proper divisors of a number
int sumOfProperDivisors(int n) {
    int sum = 1; // 1 is always a proper divisor
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

// Function to determine if a number is abundant
bool isAbundant(int n) {
    return sumOfProperDivisors(n) > n;
}

int main() {
    bool isAbundantNumber[LIMIT + 1] = {false};
    bool canBeWrittenAsAbundantSum[LIMIT + 1] = {false};

    // Find all abundant numbers
    for (int i = 12; i <= LIMIT; ++i) {
        if (isAbundant(i)) {
            isAbundantNumber[i] = true;
        }
    }

    // Mark numbers that can be written as the sum of two abundant numbers
    for (int i = 12; i <= LIMIT; ++i) {
        if (isAbundantNumber[i]) {
            for (int j = i; j <= LIMIT; ++j) {
                if (isAbundantNumber[j] && i + j <= LIMIT) {
                    canBeWrittenAsAbundantSum[i + j] = true;
                }
            }
        }
    }

    // Calculate the sum of all numbers that cannot be written as the sum of two abundant numbers
    long long totalSum = 0;
    for (int i = 1; i <= LIMIT; ++i) {
        if (!canBeWrittenAsAbundantSum[i]) {
            totalSum += i;
        }
    }

    printf("The sum of all positive integers which cannot be written as the sum of two abundant numbers is: %lld\n", totalSum);

    return 0;
}

