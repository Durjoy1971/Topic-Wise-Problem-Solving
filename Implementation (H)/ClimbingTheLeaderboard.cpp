#include <bits/stdc++.h>
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    vector<int> filter;
    for (auto x : ranked)
    {
        if (filter.size() == 0)
            filter.push_back(x);
        else if (filter.back() != x)
            filter.push_back(x);
    }
    reverse(filter.begin(), filter.end());
    vector<int> ans;

    for (auto num : player)
    {
        ans.push_back(filter.size() + 1 - (upper_bound(filter.begin(), filter.end(), num) - filter.begin()));
    }

    return ans;
}