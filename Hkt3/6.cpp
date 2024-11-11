/**
Given an array of integers, having some duplicate elements, sort the array by frequency.

Examples:
Example 1: 
Input: N = 8, array[] = {1,2,3,2,4,3,1,2} 
Output: 2 2 2 1 1 3 3 4 
Explanation: Since 2 is present 3 times in an array , so print it 3 times ,then print ‘1’ 2 times and then ‘3’ 2 times and 4 has least frequency, it will be printed at last.

Example 2: 
Input: N = 6, array[] = {-199,6,7,-199,3,5} 
Output: -199 -199 3 5 6 7 
Explanation: Since -199 is present 2 times so it will be printed at first , then 3 , 5 ,6 ,7 are present once in array , so print them in their sorted order.

Constraints
NA

Sample Input 
1 2 3 2 4 3 1 2

Sample Output 
2 2 2 1 1 3 3 4

Sample Input 
-199 6 7 -199 3 5

Sample Output 
-199 -199 3 5 6 7
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**  
    Time complexity:O(N)+O(N log N)+O(N) = O(N log N)
    Space complexity: O(M)+O(M)+O(N)=O(N)
*/
vector<int> sortByFrequency(const vector<int>& arr) {
    unordered_map<int, int> freqMap;

    // Count the frequency of each element
    for (int num : arr) {
        freqMap[num]++;
    }

    // Move elements and their frequencies into a vector of pairs
    vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());

    // Sort by frequency in descending order, and by value in ascending order if frequencies are equal
    sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second)
            return a.second > b.second; // Sort by frequency (higher first)
        return a.first < b.first;       // Sort by value (lower first) if frequency is the same
    });

    // Prepare the result based on sorted frequencies
    vector<int> result;
    for (const auto& elem : freqVec) {
        result.insert(result.end(), elem.second, elem.first); // Append element elem.second times
    }

    return result;
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    
    vector<int> arr(N);
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> result = sortByFrequency(arr);

    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
