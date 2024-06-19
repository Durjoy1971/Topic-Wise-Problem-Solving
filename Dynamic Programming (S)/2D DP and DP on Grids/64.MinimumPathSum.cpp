#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> dp(row + 3, vector<int>(col + 5, INT_MAX));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 and j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                if (i - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }

        return dp[row - 1][col - 1];
    }
};