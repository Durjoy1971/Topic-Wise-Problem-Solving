#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row, col;
    vector<vector<vector<int>>> dp;
    int cherryPickup(vector<vector<int>> &grid)
    {
        row = grid.size();
        col = grid[0].size();
        dp = vector<vector<vector<int>>>(row + 1, vector<vector<int>>(col + 1, vector<int>(col + 1, -1)));

        return recurse(grid, 0, 0, col - 1);
    }

    bool check(int indx)
    {
        return (0 <= indx and indx < col);
    }

    int recurse(vector<vector<int>> &grid, int cur_row, int ra, int rb)
    {
        if (cur_row >= row)
            return 0;

        if (dp[cur_row][ra][rb] != -1)
            return dp[cur_row][ra][rb];

        int result = grid[cur_row][ra] + grid[cur_row][rb];
        int mx = 0;

        for (int i = ra - 1; i <= ra + 1; i++)
        {
            for (int j = rb - 1; j <= rb + 1; j++)
            {
                if (i < j and check(i) and check(j))
                {
                    mx = max(mx, recurse(grid, cur_row + 1, i, j));
                }
            }
        }
        result += mx;

        return dp[cur_row][ra][rb] = result;
    }
};