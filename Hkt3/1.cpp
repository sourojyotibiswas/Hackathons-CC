/**
You have been given an array ‘a’ of ‘n’ unique non-negative integers.
Find the second largest and second smallest element from the array.
Return the two elements (second largest and second smallest) as another array of size 2.

Input Format

Sample Input 1 : 4 3 4 5 2
Sample Input 2 : 5 4 5 3 6 7

Constraints
2 ≤ 'n' ≤ 10^5 0 ≤ 'a'[i] ≤ 10^9
Time limit: 1 sec

Output Format

Sample Output 1 : 4 3
Sample Output 2 : 6 4

Sample Input
4
3 4 5 2

Sample Output
4 3

Sample Input 
5
4 5 3 6 7

Sample Output 
6 4
*/

#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

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

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void secLargeAndSecSmall(std::vector<int> &v){
    mergeSort(v, 0, v.size() - 1);
    std::cout << v[v.size() - 2] << " " << v[1];
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> v(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    secLargeAndSecSmall(v);

    return 0;
}
