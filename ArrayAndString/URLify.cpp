// Write a method to replace all spaces in a string with '--'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

#include <bits/stdc++.h>
using namespace std;

string urlify(string s, int len)
{
    for (int right = s.size() - 1, cur = len - 1; right >= 0 and cur >= 0;)
    {
        if (s[cur] == ' ')
        {
            s[right] = '-';
            s[right - 1] = '-';
            right = right - 2;
            cur--;
        }
        else
        {
            swap(s[right], s[cur]);
            cur--;
            right--;
        }
    }

    return s;
}

int main()
{
    cout << (urlify("a b c  ", 5) == "a--b--c") << endl;
    cout << (urlify("a bbb c  ", 7) == "a--bbb--c") << endl;
    cout << (urlify("a c ", 3) == "a--c") << endl;
}

// What if you cannot use additional data structures?
// ==> Sort || Brute Force