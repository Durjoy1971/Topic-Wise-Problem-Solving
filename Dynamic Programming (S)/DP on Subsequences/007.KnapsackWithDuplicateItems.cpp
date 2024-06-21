#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[W + 1] = {0};

        for (int i = 0; i < N; i++)
        {
            int value = val[i];
            for (int weight = 0; weight <= W; weight++)
            {
                if (weight - wt[i] >= 0)
                {
                    dp[weight] = max(dp[weight - wt[i]] + value, dp[weight]);
                }
            }
        }

        return dp[W];
    }
};

int main()
{
    int N, W;
    cin >> N >> W;
    int val[N], wt[N];
    for (int i = 0; i < N; i++)
        cin >> val[i];
    for (int i = 0; i < N; i++)
        cin >> wt[i];

    Solution ob;
    cout << ob.knapSack(N, W, val, wt) << endl;
}