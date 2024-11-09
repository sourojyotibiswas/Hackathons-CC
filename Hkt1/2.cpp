
/*
N monkeys are invited to a party where they start dancing. They dance in a circular formation,
very similar to a Gujarati Garba or a Drum Circle. The dance requires the monkeys to constantly
change positions after every 1 second. The change of position is not random & you, in the audience,
observe a pattern. Monkeys are very disciplined & follow a specific pattern while dancing.
Consider N = 6, and an array monkey = {3,6,5,4,1,2}. This array (1-indexed) is the dancing pattern.
The value at monkeys[i], indicates the new of position of the monkey who is standing at the ith
position. Given N & the array monkeys [ ], find the time after which all monkeys are in the
initial positions for the 1st time.

Input Format
First line contains single integer t, denoting the number of test cases.
Each test case is as follows - Integer N denoting the number of monkeys.
Next line contains N integer denoting the dancing pattern array, monkeys [].

Constraints
1<=t<=10 (test cases) 1<=N<=10000 (Number of monkeys)

Output Format
t lines, Each line must contain a single integer T, where T is the minimum number of
seconds after which all the monkeys are in their initial position.

Sample Input
1
6
3 6 5 4 1 2
Sample Output
6
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the greatest common divisor
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple
int lcm(int a, int b)
{
    return abs(a * b) / gcd(a, b);
}

// Function to find all cycle lengths in the permutation
vector<int> findCycleLengths(const vector<int> &monkeys)
{
    int n = monkeys.size();
    vector<bool> visited(n, false);
    vector<int> cycleLengths;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            int length = 0;
            int x = i;
            while (!visited[x])
            {
                visited[x] = true;
                x = monkeys[x] - 1; // Move to the next position in the cycle
                ++length;
            }
            cycleLengths.push_back(length);
        }
    }

    return cycleLengths;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;

        vector<int> monkeys(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> monkeys[i];
        }

        // Find the cycle lengths
        vector<int> cycleLengths = findCycleLengths(monkeys);

        // Calculate the LCM of all cycle lengths
        int result = 1;
        for (int length : cycleLengths)
        {
            result = lcm(result, length);
        }

        // Output the result for this test case
        cout << result << endl;
    }

    return 0;
}
