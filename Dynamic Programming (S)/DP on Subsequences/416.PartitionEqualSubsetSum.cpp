#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for (auto x : nums)
            sum += x;

        if (sum % 2 == 1)
            return false;

        bool dp[sum + 1][n + 1];
        // bool dp[sum + 1][2];
        memset(dp, false, sizeof(dp));

        dp[0][0] = true;

        // for (int i = 0; i < n; i++)
        // {
        //     int value = nums[i];
        //     for (int s = 0; s <= sum; s++)
        //     {
        //         if (dp[s][i])
        //             dp[s][i + 1] = true;
        //         if (dp[s][i] and s + value <= sum)
        //         {
        //             dp[s + value][i + 1] = true;
        //         }
        //     }
        // }

        // return dp[sum / 2][n];

        for (int i = 0; i < n; i++)
        {
            int value = nums[i];
            int state = i % 2;
            for (int s = 0; s <= sum; s++)
            {
                if (dp[s][state])
                {
                    if (state == 0)
                        dp[s][1] = true;
                    else
                        dp[s][0] = true;
                }
                if (dp[s][state] and s + value <= sum)
                {
                    if (state == 0)
                        dp[s + value][1] = true;
                    else
                        dp[s + value][0] = true;
                }
            }
        }

        return dp[sum / 2][0] || dp[sum / 2][1];
    }
};