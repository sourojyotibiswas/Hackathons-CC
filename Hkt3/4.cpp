/**
Find all the repeating elements present in an array.

Example 1: Input: Arr[] = [1,1,2,3,4,4,5,2] Output: 1,2,4 Explanation: 1,2 and 4 are the elements which are occurring more than once.
Example 2: Input: Arr[] = [1,1,0] Output: 1 Explanation: Only 1 is occurring more than once in the given array.

Constraints
NA

Sample Input
1 1 2 3 4 4 5 2

Sample Output 
1 2 4

Sample Input 
1 1 0

Sample Output 
1
*/

// Naive approach ; TC: O(n^2) and SC: O(d) d: number of distinct repeating elements
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

// void findRepeatingElementsNaive(const std::vector<int>& arr) {
//     std::vector<int> repeatingElements;

//     for (size_t i = 0; i < arr.size(); ++i) {
//         bool isDuplicate = false;
        
//         // Check if element is already in repeatingElements
//         for (int elem : repeatingElements) {
//             if (arr[i] == elem) {
//                 isDuplicate = true;
//                 break;
//             }
//         }
//         if (isDuplicate) continue;

//         // Compare with subsequent elements to find duplicates
//         for (size_t j = i + 1; j < arr.size(); ++j) {
//             if (arr[i] == arr[j]) {
//                 repeatingElements.push_back(arr[i]);
//                 break;
//             }
//         }
//     }

//     // Print the repeating elements
//     for (int elem : repeatingElements) {
//         std::cout << elem << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::vector<int> arr = {1, 1, 2, 3, 4, 4, 5, 2};
//     findRepeatingElementsNaive(arr);
//     return 0;
// }

// Optimized approach ; TC: O(n) and SC: O(n)

void findRepeatingElementsOptimal(const std::vector<int>& arr) {
    std::unordered_set<int> seen;
    std::unordered_set<int> repeatingElements;

    for (int num : arr) {
        // Check if the number has already been seen
        if (seen.find(num) != seen.end()) {
            repeatingElements.insert(num);
        } else {
            seen.insert(num);
        }
    }
    
    for (int elem : repeatingElements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 1, 2, 3, 4, 4, 5, 2};
    findRepeatingElementsOptimal(arr);
    return 0;
}

/**
If you use an ordered set (like std::set in C++) instead of an unordered set (std::unordered_set),
the time complexity of operations like find() and insert() changes because std::set is implemented 
as a balanced binary search tree (e.g., Red-Black Tree).
These operations will take logarithmic time rather than constant time.
 */