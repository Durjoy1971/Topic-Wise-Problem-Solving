#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int recurse(int x, int y, int row, int col, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid[x][y] == 1)
            return 0;
        if (x == row - 1 and y == col - 1)
            return 1;
        if (dp[x][y] != -1)
            return dp[x][y];

        int ans = 0;
        if (x + 1 < row and obstacleGrid[x + 1][y] == 0)
            ans += recurse(x + 1, y, row, col, dp, obstacleGrid);
        if (y + 1 < col and obstacleGrid[x][y + 1] == 0)
            ans += recurse(x, y + 1, row, col, dp, obstacleGrid);

        return dp[x][y] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 2, vector<int>(n + 2, -1));
        return recurse(0, 0, m, n, dp, obstacleGrid);
    }
};