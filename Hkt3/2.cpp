/**
You are given a sorted integer array 'arr' of size 'n'.
You need to remove the duplicates from the array such that each element appears only once.
Return the length of this new array.

Note: Do not allocate extra space for another array. 
You need to do this by modifying the given input array in place with O(1) extra memory.

Constraints
1 <= 'n' <= 10^6 -10^9 <= 'arr[i]' <=10^9
Where ‘arr[i]’ is the value of elements of the array.
Time limit: 1 sec

Sample Input 
10
1 2 2 3 3 3 4 4 5 5

Sample Output 
5

Sample Input 
9
1 1 2 3 3 4 5 5 5

Sample Output 
5
 */

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& arr) {
    if (arr.empty()) return 0;
    int uniqueIndex = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[uniqueIndex]) {
            ++uniqueIndex;
            arr[uniqueIndex] = arr[i];
        }
    }
    return uniqueIndex + 1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int newLength = removeDuplicates(arr);
    std::cout << newLength << std::endl;
    return 0;
}

