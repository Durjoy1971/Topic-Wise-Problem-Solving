// Given a string, write a function to check if it is a permutation of a palindrome.A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

#include <bits/stdc++.h>
using namespace std;

bool palindromePermutation(string s)
{
    map<char, int> counter;
    int len = 0;

    for (auto ch : s)
    {
        if (ch == ' ')
            continue;
        char X = tolower(ch);
        counter[X]++;
        len++;
    }

    if (len % 2 == 0)
    {
        for (auto x : counter)
        {
            if (x.second % 2 == 1)
                return false;
        }
    }
    else if (len % 2 != 0)
    {
        int odd_counter = 0;
        for (auto x : counter)
        {
            if (x.second % 2 == 1)
                odd_counter++;
        }
        if (odd_counter > 1)
            return false;
    }

    return true;
}

int main()
{
    cout << palindromePermutation("Tact Coa") << endl;
    cout << palindromePermutation("Tact Cde") << endl;
}