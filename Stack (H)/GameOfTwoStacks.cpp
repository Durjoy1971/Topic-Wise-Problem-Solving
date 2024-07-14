#include <bits/stdc++.h>

using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b)
{
    stack<int> input;
    int cur_sum = 0;
    int item = 0;

    for (auto x : a)
    {
        if (cur_sum + x <= maxSum)
        {
            cur_sum += x;
            item++;
            input.push(x);
        }
        else
        {
            break;
        }
    }

    int ans = item;

    for (int i = 0; i < b.size();)
    {
        if (cur_sum + b[i] <= maxSum)
        {
            cur_sum += b[i];
            i++;
            item++;
        }
        else if (input.size() > 0)
        {
            while (cur_sum + b[i] > maxSum and input.size() > 0)
            {
                cur_sum -= input.top();
                input.pop();
                item--;
            }
        }
        else
            break;
        ans = max(ans, item);
    }

    return ans;
}