#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size(), ans = 1, temp = 1;

        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else if (nums[i] == nums[i - 1] + 1)
            {
                temp++;
            }
            else
            {
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);

        return ans;
    }
};