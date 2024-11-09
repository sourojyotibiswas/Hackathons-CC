/*
Given an array of integers, perform atmost K operations so that the sum of elements of final
array is minimum. An operation is defined as follows –

Consider any 1 element from the array, arr[i]. Replace arr[i] by floor(arr[i]/2).
Perform next operations on the updated array. The task is to minimize the sum after
utmost K operations.

Input Format
First line contains two integers N and K representing size of array and maximum numbers of
operations that can be performed on the array respectively.
Second line contains N space separated integers denoting the elements of the array, arr.

Constraints
1 <= N K <= 10^5.

Output Format
Print a single integer denoting the minimum sum of the final array.

Sample Input
4 3
20 7 5 4

Sample Output
17

Explanation
Operation 1 -> Select 20. Replace it by 10. New array = [10, 7, 5, 4].
Operation 2 -> Select 10. Replace it by 5. New array = [5, 7, 5, 4].
Operation 3 -> Select 7. Replace it by 3. New array = [5,3,5,4].
Sum = 17.
*/

#include <iostream>

void bubbleSortDescending(int arr[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int minimizeSum(int arr[], int N, int K)
{
    for (int i = 0; i < K; i++)
    {
        // Sort the array in descending order using bubble sort
        bubbleSortDescending(arr, N);

        // Replace the largest element with floor(largest / 2)
        arr[0] = arr[0] / 2;

        // If the largest element becomes 0, stop further operations
        if (arr[0] == 0)
        {
            break;
        }
    }

    // Calculate the final sum of the array
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int N, K;
    std::cin >> N >> K;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    int result = minimizeSum(arr, N, K);
    std::cout << result << std::endl;

    return 0;
}
