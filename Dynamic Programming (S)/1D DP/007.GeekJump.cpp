#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumEnergy(vector<int> &height, int n)
  {

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
      if (i >= 2)
      {
        dp[i] = min(dp[i - 2] + abs(height[i - 2] - height[i]), dp[i]);
      }
      dp[i] = min(dp[i - 1] + abs(height[i - 1] - height[i]), dp[i]);
    }

    return dp[n - 1];
  }
};