// Assumeyou have a method isSubstringwhich checks if one word is a substring of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").

#include <bits/stdc++.h>
using namespace std;

bool stringRotation(string first, string second)
{
    if (first.size() != second.size())
        return false;

    first = first + first;

    bool answer = true;

    for ()

        return answer;
}

int main()
{
    cout << stringRotation("abc", "cab") << endl;
    cout << stringRotation("rotate", "tatero") << endl;
}