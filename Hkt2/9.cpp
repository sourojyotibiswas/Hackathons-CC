/*
Given a set of activities, along with the starting and finishing time of each activity,
find the maximum number of activities performed by a single person assuming that a person
can only work on a single activity at a time.

Sample Input
(1, 4), (3, 5), (0, 6), (5, 7), (3, 8), (5, 9), (6, 10), (8, 11), (8, 12), (2, 13), (12, 14)

Sample Output
(1, 4), (5, 7), (8, 11), (12, 14)

Sample Input
(3, 7), (1, 3), (2, 9), (2, 7), (1, 2), (7, 8)

Sample Output
(1, 3), (3, 7), (7, 8)

Sample Input
(3, 7), (1, 3), (2, 9), (2, 7), (1, 2), (7, 8)

Sample Output
(1, 2), (3, 7), (7, 8)

Sample Input
(3, 7), (1, 3), (2, 9), (2, 7), (1, 2), (7, 8)

Sample Output
(1, 2), (2, 7), (7, 8)
*/

// when input activities may not be sorted.
#include <bits/stdc++.h>
using namespace std;

// A job has a start time, finish time and profit.
struct Activitiy
{
    int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
    // Sort jobs according to finish time
    sort(arr, arr + n, activityCompare);

    cout << "Following activities are selected :\n";

    // The first activity always gets selected
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish
         << ")";

    // Consider rest of the activities
    for (int j = 1; j < n; j++)
    {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (arr[j].start >= arr[i].finish)
        {
            cout << ", (" << arr[j].start << ", "
                 << arr[j].finish << ")";
            i = j;
        }
    }
}

// Driver code
int main()
{
    Activitiy arr[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printMaxActivities(arr, n);
    return 0;
}
