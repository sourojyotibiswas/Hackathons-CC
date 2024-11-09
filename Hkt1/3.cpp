/*
The binary number system only uses two digits, 0 and 1. Any string that represents a number
in the binary number system can be called a binary string. You are required to implement the

following function:
int OperationsBinaryString(char *str);

The function accepts a string 'str' as its argument. The string 'str' consists of binary
digits separated with an alphabet as follows:

'A' denotes AND operation 'B' denotes OR operation 'C' denotes XOR operation
You are required to calculate the result of the string 'str', scanning the string left to right,
taking one operation at a time, and return the same.

Input Format
Input:
str: 1C0C1C1A0B1

Constraints
No order of priorities of operations is required. Length of 'str' is odd If 'str' is NULL or None(in case of python), return -1

Output Format
Output:
1

Sample Input
1C0C1C1A0B1

Sample Output
1

Sample Input
0C1A1B1C1C1B0A0

Sample Output
0
*/

#include <iostream>
#include <string> // For std::string and std::getline

int OperationsBinaryString(const std::string &str)
{
    // Check if the input is empty
    if (str.empty())
    {
        return -1;
    }

    // Initialize result with the first binary digit
    int result = str[0] - '0'; // Convert character to integer ('0' -> 0, '1' -> 1)

    // Traverse the string
    for (size_t i = 1; i < str.length(); i += 2)
    {
        char op = str[i];
        int next_value = str[i + 1] - '0'; // Convert next binary digit to integer

        switch (op)
        {
        case 'A': // AND operation
            result = result & next_value;
            break;
        case 'B': // OR operation
            result = result | next_value;
            break;
        case 'C': // XOR operation
            result = result ^ next_value;
            break;
        default:
            // Invalid operation character, return -1
            return -1;
        }
    }

    return result;
}

int main()
{
    std::string input;

    // Prompt the user to enter the binary string
    std::cout << "Enter the binary string: ";
    std::getline(std::cin, input); // Read the entire line as input

    // Check and display the result
    int result = OperationsBinaryString(input);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
