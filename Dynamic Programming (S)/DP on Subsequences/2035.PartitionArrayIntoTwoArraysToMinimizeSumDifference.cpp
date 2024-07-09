#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        long long int sum = 0;
        for (auto x : nums)
            sum += x;

        int mid_div = nums.size() / 2;

        vector<vector<int>> left_side(mid_div + 2), right_side(mid_div + 2);

        int left = 0;

        for (int mask = 0; mask < (1 << mid_div); mask++)
        {
            int number_of_selected = 0;
            int sum_of_left = 0, sum_of_right = 0;
            for (int cur = 0; cur < mid_div; cur++)
            {
                if (mask & (1 << cur))
                {
                    number_of_selected++;
                    sum_of_left += nums[cur];
                    sum_of_right += nums[cur + mid_div];
                }
            }
            left_side[number_of_selected].push_back(sum_of_left);
            right_side[number_of_selected].push_back(sum_of_right);
        }

        for (int i = 0; i <= mid_div; i++)
        {
            sort(right_side[i].begin(), right_side[i].end());
        }

        int ans = abs(sum - 2 * right_side[mid_div].back());

        for (int i = 1; i < mid_div; i++)
        {
            for (auto single_sum : left_side[i])
            {
                int needed = (sum - 2 * single_sum) / 2;
                int right_index = mid_div - i;
                auto iteration = lower_bound(right_side[right_index].begin(), right_side[right_index].end(), needed);
                if (iteration != right_side[right_index].end())
                {
                    ans = min(ans, (int)abs(sum - 2 * (single_sum + *iteration)));
                }
            }
        }
        return ans;
    }
};