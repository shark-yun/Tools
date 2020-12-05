
#include <iostream>
#include <string>
#include <cassert>
#include<cctype>

using namespace std;

bool isAPalindrome(string str, unsigned int low, unsigned int high)
{
    //base condition if string reaches at middle
    if (low == high)
        return true;

    //checking for punctuation or space for right half and ignore it
    if (ispunct(str[low]) || isspace(str[low]))
        return isAPalindrome(str, low + 1, high);

    //checking for punctuation or space for left half and ignore it
    if (ispunct(str[high]) || isspace(str[high]))
        return isAPalindrome(str, low, high - 1);

    //checking character by first converting it to upper case and then compare
    if ((toupper(str[low]) != toupper(str[high])))
        return false;

    //if there are more than two chars, check if middle substring is also palindrome pr not
    if (low < (high + 1))
        return isAPalindrome(str, low + 1, high - 1);

    return true;
};

int main()
{
    string str;
    string terminate = "quit";
    unsigned int low, high;
   

    while (1)
    {
        cout << "Enter a string to start and 'quit' to leave: ";
        std::getline(std::cin, str);
        if (str.compare(terminate) == 0)
            break;

        low = 0;
        high = str.length() - 1;
        if (isAPalindrome(str, low, high))
            cout << str << " is a palindrome." << endl;
        else
            cout << str << " is not a palindrome." << endl;
    }
    return 0;
}

