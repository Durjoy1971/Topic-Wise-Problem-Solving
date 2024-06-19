#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums[0];
        return max(func(nums, 0, nums.size() - 2), func(nums, 1, nums.size() - 1));
    }

    int func(vector<int> nums, int left, int right)
    {
        for (int i = left; i <= right; i++)
        {
            int tmp = nums[i];
            if (i - 3 >= left)
                tmp = max(tmp, nums[i] + nums[i - 3]);
            if (i - 2 >= left)
                tmp = max(tmp, nums[i] + nums[i - 2]);
            nums[i] = tmp;
        }
        if (right - 1 >= 0)
            return max(nums[right - 1], nums[right]);
        return nums[right];
    }
};