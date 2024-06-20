#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        bool dp[sum + 1][arr.size() + 1];

        memset(dp, false, sizeof(dp));

        dp[sum][0] = true;

        for (int s = sum; s >= 0; s--)
        {
            for (int index = 0; index < arr.size(); index++)
            {
                int value = arr[index];
                if (dp[s][index])
                    dp[s][index + 1] = true;
                if (s - value >= 0 and dp[s][index])
                    dp[s - value][index + 1] = true;
            }
        }

        for (int i = 1; i <= arr.size(); i++)
        {
            if (dp[0][i])
                return true;
        }

        return false;
    }
};

int main()
{
    Solution Test;

    cout << Test.isSubsetSum({3, 34, 4, 12, 5, 2}, 30) << endl;
}