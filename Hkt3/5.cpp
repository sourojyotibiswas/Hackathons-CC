/**
Given an array of N integers, the task is to replace each element of the array by its rank in the array.

Example 1: Input: 20 15 26 2 98 6 Output: 4 3 5 1 6 2 Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so…
Example 2: Input: 1 5 8 15 8 25 9 Output: 1 2 3 5 3 6 4 Explanation: When sorted,the array is 1,5,8,8,9,15,25. So the rank of 1 is 1,rank of 5 is 2,rank of 8 is 3 and so…

Constraints
NA

Sample Input 
20 15 26 2 98 6

Sample Output
4 3 5 1 6 2

Sample Input 
1 5 8 15 8 25 9

Sample Output 
1 2 3 5 3 6 4
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// TC: O(NlogN) + O(N) + O(N) = O(NlogN) and SC: O(N)+O(N) = O(N)

void replaceWithRank(std::vector<int>& arr) {
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());
    std::unordered_map<int, int> rankMap;

    int rank = 1;
    for (size_t i = 0; i < sortedArr.size(); ++i) { 
        
        if (rankMap.find(sortedArr[i]) == rankMap.end()) {
            rankMap[sortedArr[i]] = rank;
            rank++;
        }
    }

    for (size_t i = 0; i < arr.size(); ++i) { 
        arr[i] = rankMap[arr[i]];
    }

    for (size_t i = 0; i < arr.size(); ++i) { 
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {20, 15, 26, 2, 98, 6};
    replaceWithRank(arr);
    return 0;
}

/**note:
size_t is the correct type to use for indexing containers like std::vector because it is 
specifically designed to represent the size of objects in memory (i.e., the number of elements). 
It is an unsigned type and can hold large values without the risk of overflow that can occur 
when using signed types like int.
*/