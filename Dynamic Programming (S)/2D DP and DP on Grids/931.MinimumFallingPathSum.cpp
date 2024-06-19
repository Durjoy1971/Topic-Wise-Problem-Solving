#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int dp[row + 50][col + 50];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                dp[i][j] = 0;
            }
        }

        for (int j = 0; j < col; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int cur = matrix[i][j] + dp[i - 1][j];

                if (j - 1 >= 0)
                {
                    cur = min(cur, matrix[i][j] + dp[i - 1][j - 1]);
                }

                if (j + 1 < col)
                {
                    cur = min(cur, matrix[i][j] + dp[i - 1][j + 1]);
                }

                dp[i][j] = cur;
            }
        }

        int ans = dp[row - 1][0];

        for (int j = 1; j < col; j++)
        {
            ans = min(ans, dp[row - 1][j]);
        }

        return ans;
    }
};