#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int row = triangle.size();
        int col = 0;

        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j <= col + 1; j++)
            {
                int temp_value = triangle[i][j];
                if (j <= col and j - 1 >= 0)
                {
                    triangle[i][j] = min(temp_value + triangle[i - 1][j], temp_value + triangle[i - 1][j - 1]);
                }
                else if (j <= col)
                {
                    triangle[i][j] = temp_value + triangle[i - 1][j];
                }
                else if (j - 1 >= 0)
                {
                    triangle[i][j] = temp_value + triangle[i - 1][j - 1];
                }
            }
            col++;
        }

        int ans = INT_MAX;
        for (int i = 0; i <= col; i++)
        {
            ans = min(ans, triangle[row - 1][i]);
        }

        return ans;
    }
};