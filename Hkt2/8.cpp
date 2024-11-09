/*
Given an integer array, find the maximum product of its elements among all its subsets.

Input : [-6, 4, -5, 8, -10, 0, 8]
Output: 15360
Explanation: The subset with the maximum product of its elements is [-6, 4, 8, -10, 8]

Input : [4, -8, 0, 8]
Output: 32
Explanation: The subset with the maximum product of its elements is [4, 8]

Input : []
Output: 0

Sample Input
-6, 4, -5, 8, -10, 0, 8

Sample Output
15360

Sample Input
4, -8, 0, 8

Sample Output
32

Sample Input
[]

Sample Output
0
*/

#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
    if (n == 1)
        return a[0];

    // Find count of negative numbers, count
    // of zeros, negative number
    // with least absolute value
    // and product of non-zero numbers
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++)
    {

        // If number is 0, we don't
        // multiply it with product.
        if (a[i] == 0)
        {
            count_zero++;
            continue;
        }

        // Count negatives and keep
        // track of negative number
        // with least absolute value
        if (a[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }

        prod = prod * a[i];
    }

    // If there are all zeros
    if (count_zero == n)
        return 0;

    // If there are odd number of
    // negative numbers
    if (count_neg & 1)
    {

        // Exceptional case: There is only
        // negative and all other are zeros
        if (count_neg == 1 &&
            count_zero > 0 &&
            count_zero + count_neg == n)
            return 0;

        // Otherwise result is product of
        // all non-zeros divided by
        // negative number with
        // least absolute value
        prod = prod / max_neg;
    }

    return prod;
}

// Driver Code
int main()
{
    int a[] = {4, -8, 0, 8};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}
