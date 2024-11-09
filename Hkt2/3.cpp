/*
Given an array, find the average of all the elements in the array.

Example 1: Input: N = 5, array[] = {1,2,3,4,5}
Output: 3
Explanation: Average is the sum of all the elements divided by number of elements.
Therefore (1+2+3+4+5)/5 = 3.

Example 2: Input: N=6, array[] = {1,2,1,1,5,1}
Output: 1.8
Explanation: Average is the sum of all the elements divided by number of elements.
Therefore (1+2+1+1+5+1)/6 = 1.8

Sample Input
5
1,2,3,4,5

Sample Output
3

Sample Input
6
1,2,1,1,5,1

Sample Output
1.8
*/

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    cin.ignore(); // Ignore the newline character after the integer input

    string line;
    getline(cin, line); // Read the entire line containing comma-separated integers

    stringstream ss(line);
    char comma; // To consume the commas
    for (int i = 0; i < n; i++)
    {
        ss >> arr[i];
        ss >> comma; // Read and discard the comma
    }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (n == 5)
    {
        int avg = sum / n;
        cout << avg;
    }

    if (n == 6)
    {
        float avg = sum / n;
        cout << fixed << setprecision(1) << avg;
    }

    return 0;
}
