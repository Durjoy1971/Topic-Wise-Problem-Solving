// Given two strings, write a method to decide if one is a permutation of the other.

#include <bits/stdc++.h>
using namespace std;

bool checkPermutation(string first, string second)
{
    if (first.size() != second.size())
        return false;

    map<char, int> counter;

    for (auto x : first)
    {
        counter[x]++;
    }

    for (auto x : second)
    {
        counter[x]--;
        if (counter[x] < 0)
            return false;
    }

    return true;
}

int main()
{
    cout << checkPermutation("abc", "bac") << endl;
    cout << checkPermutation("abc  ", "bac") << endl;
    cout << checkPermutation("aba", "abc") << endl;
}

// What if you cannot use additional data structures?
// ==> Sort || Brute Force