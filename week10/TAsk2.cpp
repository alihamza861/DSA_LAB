#include <iostream>
#include <string>
using namespace std;

bool ispalindrome(string s, int start, int end)
{

    if (start >= end)
        return true;


    if (s[start] != s[end])
        return false;

  
    return ispalindrome(s, start + 1, end - 1);
}

int main()
{
    string s;

    cout << "Enter a sing: ";
    cin >> s;

    if (ispalindrome(s, 0, s.length() - 1))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}