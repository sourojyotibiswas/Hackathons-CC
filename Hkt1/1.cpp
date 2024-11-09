/* You are given a function:

int CheckPassword(char str[], int n);

The function accepts string 'std of size int as argument Implement the function which
returns 1 if given string 'str' is a valid password else 0.

'str' is a valid password if it satisfies below conditions:
 - At least 4 characters
 - At least one numeric digit
 - At least one Capital letter
 - Must not have space or slash (/)
 - Starting character must not be a number

Input Format
Input:
aA1_67

Constraints
Input string will not be empty.
Output Format
1

Sample Input
aA1_67
Sample Output
1

Sample Input
a987 abC012
Sample Output
0
*/

#include <iostream>
#include <string>
#include <cctype>

int CheckPassword(const std::string &str)
{
    // Define a set of special characters allowed in the password
    std::string validSpecialChars = "@#$%^&*()!~`{}[]:;'\"><>?";

    // Check for at least 4 alphabetic characters
    int alphaCount = 0;
    if (str.length() < 4)
    {
        return 0;
    }

    // Starting character check
    if (std::isdigit(str[0]))
    {
        return 0;
    }

    bool hasDigit = false;
    bool hasUpper = false;

    for (char ch : str)
    {
        if (!std::isalnum(ch) && validSpecialChars.find(ch) == std::string::npos)
        {
            // If the character is not alphanumeric and not in the list of valid special characters
            return 0;
        }
        if (std::isalpha(ch))
        {
            ++alphaCount; // Count alphabetic characters
        }
        if (std::isdigit(ch))
        {
            hasDigit = true;
        }
        if (std::isupper(ch))
        {
            hasUpper = true;
        }
    }

    // Check if there are at least 4 alphabetic characters
    if (alphaCount < 4)
    {
        return 0;
    }

    // Check if both digit and uppercase letter are present
    if (hasDigit && hasUpper)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::string password;

    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    int result = CheckPassword(password);
    std::cout << result << std::endl;

    return 0;
}
