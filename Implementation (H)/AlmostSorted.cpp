#include <bits/stdc++.h>

using namespace std;

void almostSorted(vector<int> arr)
{
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
        return;
    }

    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    int cnt = 0;
    int start = -1, end = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != tmp[i])
        {
            cnt++;
            if (start == -1)
                start = i;
            end = i;
        }
    }

    if (cnt <= 2)
    {
        cout << "yes" << endl;
        cout << "swap ";
        bool first = true;
        cout << start + 1 << " " << end + 1 << endl;
        return;
    }

    vector<int> ans;

    for (int i = 0; i < start; i++)
        ans.push_back(arr[i]);
    for (int i = end; i >= start; i--)
        ans.push_back(arr[i]);
    for (int i = end + 1; i < arr.size(); i++)
        ans.push_back(arr[i]);

    if (is_sorted(ans.begin(), ans.end()))
    {
        cout << "yes" << endl;
        cout << "reverse " << start + 1 << " " << end + 1 << endl;
        return;
    }

    cout << "no" << endl;
}