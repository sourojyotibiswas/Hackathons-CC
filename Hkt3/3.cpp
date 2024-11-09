/**
Given an unsorted array, find the median of the given array.
Example 1: Input: [2,4,1,3,5] Output: 3
Example 2: Input: [2,5,1,7] Output: 3.5

Constraints
NA

Sample Input
2 4 1 3 5

Sample Output 
3

Sample Input 
2 5 1 7

Sample Output 
3.5
 */

#include <algorithm>
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

double findMedian(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);
    if (n % 2 != 0) {
        return arr[n / 2];
    }
    else {
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }
}

int main()
{
    int arr[] = { 2, 5, 1, 7 };

    int n = sizeof(arr) / sizeof(arr[0]);

    double median = findMedian(arr, n);

    cout << "Median of the array is: " << median << endl;

    return 0;
}
