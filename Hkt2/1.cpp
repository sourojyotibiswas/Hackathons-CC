/*
Given an A.P. Series, we need to find the sum of the Series.

a = first term of A.P.
d= common Difference of A.P.
n= Number of Terms in A.P.

Examples:

Example 1: Input: n=4 a=2 d=2 Output: 20 Explanation: 2+4+6+8 = 20

Input: n=8 a=2 d=5
Output: 124
Explanation: -2 +3 + 8 + 13 + 18 + 23 + 28 + 33 = 124

Sample Input
2
2
4

Sample Output
20

Sample Input
2
3
10

Sample Output
155
*/

#include <iostream>
using std::cin;
using std::cout;

int sumOfnTerms(int a, int d, int n)
{
    int sum = (n / 2) * ((2 * a) + ((n - 1) * d));
    return sum;
}

int main()
{

    int a, n, d;

    cin >> a;
    cin >> d;
    cin >> n;

    int ans = sumOfnTerms(a, d, n);
    cout << ans;

    return 0;
}