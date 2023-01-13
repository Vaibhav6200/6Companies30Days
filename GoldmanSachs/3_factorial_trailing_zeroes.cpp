#include<bits/stdc++.h>
using namespace std;


// Function to find the number of trailing zeros in the factorial of a given number n
int trailingZeroes(int n) {
    // Initialize a variable to store the number of trailing zeros
    int num_zeros = 0;

    // Iterate over the multiples of 5 from 5 to n
    for (int i = 5; i <= n; i += 5) {
        // Initialize a variable to store the current multiple of 5
        int num = i;

        // Divide num by 5 and add the quotient to num_zeros until num is no longer divisible by 5
        while (num % 5 == 0) {
            num /= 5;
            num_zeros++;
        }
    }

    // Return the number of trailing zeros
    return num_zeros;
}


int main()
{

    return 0;
}