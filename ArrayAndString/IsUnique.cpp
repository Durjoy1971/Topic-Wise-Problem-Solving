// Implement an algorithm to determine if a string has all unique characters.

#include <bits/stdc++.h>
using namespace std;

bool isUnique(string s)
{
    map<char, bool> visited;

    for (auto x : s)
    {
        if (visited[x])
            return false;
        visited[x] = true;
    }
    return true;
}

int main()
{
    cout << isUnique("abc") << endl;
    cout << isUnique("aba") << endl;
}

// What if you cannot use additional data structures?
// ==> Sort || Brute Force