#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        int row = points.size();
        int col = points[0].size();
        int dp[row + 2][col + 2];

        dp[0][0] = points[0][0];
        dp[0][1] = points[0][1];
        dp[0][2] = points[0][2];

        for (int i = 1; i < row; i++)
        {
            dp[i][0] = max(points[i][0] + dp[i - 1][1], points[i][0] + dp[i - 1][2]);
            dp[i][1] = max(points[i][1] + dp[i - 1][0], points[i][1] + dp[i - 1][2]);
            dp[i][2] = max(points[i][2] + dp[i - 1][1], points[i][2] + dp[i - 1][0]);
        }

        return max(dp[row - 1][0], max(dp[row - 1][1], dp[row - 1][2]));
    }
};