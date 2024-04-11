#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int val = 1;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        { // prefix
            ans[i] = val;
            val *= nums[i];
        }
        val = 1;
        for (int i = n - 1; i >= 0; i--)
        { // suffix
            ans[i] *= val;
            val *= nums[i];
        }
        return ans;
    }
};