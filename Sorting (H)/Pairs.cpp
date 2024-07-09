#include <bits/stdc++.h>
using namespace std;

int pairs(int k, vector<int> arr)
{
    int ans = 0;
    map<int, int> cnt;

    for (auto x : arr)
    {
        cnt[x]++;
    }

    for (auto x : arr)
    {
        int prev = x - k;
        ans += cnt[prev];
    }

    return ans;
}