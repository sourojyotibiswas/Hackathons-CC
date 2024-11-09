/*
Given an array containing positive and negative elements, find a subarray with alternating
positive and negative elements, and in which the subarray is as long as possible.

Input : [1, -2, 6, 4, -3, 2, -4, -3]
Output: [4, -3, 2, -4]

Note that the longest alternating subarray might not be unique.
In case the multiple alternating subarrays of maximum length exists,
the solution can return any one of them.

Input : [1, -2, 6, 2, 4, -3, 2, 4, -3]
Output: [1, -2, 6] or [4, -3, 2]

Sample Input
1, -2, 6, 4, -3, 2, -4, -3

Sample Output
4, -3, 2, -4

Sample Input
1, -2, 6, 2, 4, -3, 2, 4, -3

Sample Output
1, -2, 6

Sample Input
1, -2, 6, 2, 4, -3, 2, 4, -3

Sample Output
4, -3, 2
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> findAllLongestAlternatingSubarrays(const std::vector<int> &arr)
{
    int maxLength = 1;
    int currentLength = 1;
    std::vector<int> currentSubarray = {arr[0]};
    std::vector<std::vector<int>> result;

    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i] > 0 && arr[i - 1] < 0) || (arr[i] < 0 && arr[i - 1] > 0))
        {
            currentLength++;
            currentSubarray.push_back(arr[i]);
        }
        else
        {
            if (currentLength == maxLength)
            {
                result.push_back(currentSubarray);
            }
            else if (currentLength > maxLength)
            {
                maxLength = currentLength;
                result.clear();
                result.push_back(currentSubarray);
            }
            currentLength = 1;
            currentSubarray = {arr[i]};
        }
    }

    // Handle the last subarray
    if (currentLength == maxLength)
    {
        result.push_back(currentSubarray);
    }
    else if (currentLength > maxLength)
    {
        result.clear();
        result.push_back(currentSubarray);
    }

    return result;
}

int main()
{
    std::vector<int> arr = {1, -1, 2, 2, -1, 3, 6, -4, 2};
    std::vector<std::vector<int>> result = findAllLongestAlternatingSubarrays(arr);

    std::cout << "Longest alternating subarrays: \n";
    for (const auto &subarray : result)
    {
        for (int num : subarray)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
