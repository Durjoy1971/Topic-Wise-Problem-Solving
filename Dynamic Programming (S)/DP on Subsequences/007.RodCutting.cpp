#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        int dp[n + 2] = {0};

        for (int i = 0; i < n; i++)
        {
            int value = price[i];
            for (int len = 1; len <= n; len++)
            {
                if (len - (i + 1) >= 0)
                {
                    dp[len] = max(dp[len], dp[len - (i + 1)] + value);
                }
            }
        }

        return dp[n];
    }
};

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solution ob;

    cout << ob.cutRod(a, n) << endl;

    return 0;
}