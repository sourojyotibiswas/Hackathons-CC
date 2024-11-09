/*
Given an array of pairs, find all the symmetric pairs in the array.

Example 1: Input: (1,2),(2,1),(3,4),(4,5),(5,4)
Output: (2,1) (5,4)
Explanation: Since (1,2) and (2,1) are symmetric pairs and (4,5) and (5,4) are symmetric pairs.

Example 2: Input: (1,5),(2,3),(4,2),(5,1),(2,4)
Output: (2,4) (5,1)
Explanation: Since (1,5) and (2,4) are symmetric pairs and (5,1) and (4,2) are symmetric pairs.

Sample Input
(1,2),(2,1),(3,4),(4,5),(5,4)

Sample Output
(2,1) (5,4)

Sample Input
(1,5),(2,3),(4,2),(5,1),(2,4)

Sample Output
(2,4) (5,1)
*/

// has error for input : {1,5},{2,3},{4,2},{5,1},{2,4}

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<pair<int, int>> arr, int i, int j, int n)
{
    int mid = i + (j - i) / 2;
    if (i > j)
    {
        return -1;
    }
    if (arr[mid].second == n)
    {
        return mid;
    }
    else if (arr[mid].second > n)
    {
        return binarySearch(arr, i, mid - 1, n);
    }
    else if (arr[mid].second < n)
    {
        return binarySearch(arr, mid + 1, j, n);
    }
    return 0;
}

void sol(vector<pair<int, int>> arr)
{
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        int idx = binarySearch(arr, 0, arr.size() - 1, arr[i].first);
        if (arr[idx].first == arr[i].second && idx != -1)
        {
            cout << arr[idx].first << " " << arr[idx].second << endl;
        }
    }
}

int main()
{
    vector<pair<int, int>> vec = {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}};
    sol(vec);

    return 0;
}
