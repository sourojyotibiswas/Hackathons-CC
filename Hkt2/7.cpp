/*
An intelligence agency has received reports about some threats. The reports consist of numbers
in a mysterious method. There is a number “N” and another number “R”. Those numbers are studied
thoroughly and it is concluded that all digits of the number ‘N’ are summed up and this action
is performed ‘R’ number of times. The resultant is also a single digit that is yet to be deciphered.
The task here is to find the single-digit sum of the given number ‘N’ by repeating the action ‘R’
number of times.

If the value of ‘R’ is 0, print the output as ‘0’.

Example 1:

Input :
99 -> Value of N
3 -> Value of R

Output :
9 -> Possible ways to fill the cistern.

Explanation:
Here, the number N=99
Sum of the digits N: 9+9 = 18 Repeat step 2 ‘R’ times
i.e. 3 times (9+9)+(9+9)+(9+9) = 18+18+18 =54 Add digits of 54 as we need a single digit 5+4

Input Format
The Input format for testing the candidate has to write the code to accept 2 input(s)

First input- Accept value for N (positive integer number)
Second input: Accept value for R(Positive integer number)

Constraints

0
0<=R<=50

Output Format
The output format for testing
The output should be a positive integer number or print the message (if any)
given in the problem statement. (Check the output in Example 1)

Sample Input
99
3

Sample Output
9

Sample Input
1234
2

Sample Output
2
*/

#include <iostream>
using std::cin;
using std::cout;

int main()
{

    int n;
    int x;

    cin >> n;
    cin >> x;

    int sum = 0;

    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }

    sum = sum * x;

    int ans = 0;

    while (sum != 0)
    {
        ans += sum % 10;
        sum = sum / 10;
    }

    cout << ans;

    return 0;
}