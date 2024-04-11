#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            mp[nums[i]]++;

        vector<pair<int, int>> v;
        for (auto it : mp)
            v.push_back({it.second, it.first});

        sort(v.rbegin(), v.rend());

        for (int i = 0; i < k; i++)
            ans.push_back(v[i].second);
        return ans;
    }
};