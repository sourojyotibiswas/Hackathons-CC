/*
Before the outbreak of corona virus to the world, a meeting happened in a room in Wuhan.
A person who attended that meeting had COVID-19 and no one in the room knew about it!
So everyone started shaking hands with everyone else in the room as a gesture of respect and
after meeting unfortunately every one got infected! Given the fact that any two persons shake
hand exactly once, Can you tell the total count of handshakes happened in that meeting?

Input Format
The first line contains the number of test cases T, T lines follow.
Each line then contains an integer N, the total number of people attended that meeting.

Constraints
1 <= T <= 1000
0 < N < 106

Output Format
Print the number of handshakes for each test-case in a new line.

Sample Input
2
1
2

Sample Output
0
1
*/

#include <bits/stdc++.h>
using namespace std;

int handshake(int n)
{
    return n * (n - 1) / 2;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int result = handshake(n);

        cout << result << "\n";
    }
    return 0;
}