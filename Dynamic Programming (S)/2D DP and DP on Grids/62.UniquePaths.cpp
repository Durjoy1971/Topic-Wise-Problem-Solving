#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int recurse(int x, int y, int row, int col, vector<vector<int>> &dp)
    {
        if (x == row and y == col)
            return 1;
        if (dp[x][y] != -1)
            return dp[x][y];

        int ans = 0;

        if (x + 1 <= row)
            ans += recurse(x + 1, y, row, col, dp);
        if (y + 1 <= col)
            ans += recurse(x, y + 1, row, col, dp);

        return dp[x][y] = ans;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 2, vector<int>(n + 2, -1));
        return recurse(1, 1, m, n, dp);
    }
};