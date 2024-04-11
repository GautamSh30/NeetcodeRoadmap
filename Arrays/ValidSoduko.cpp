#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &b)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> mp;
            for (int j = 0; j < 9; j++)
            {
                if (b[i][j] != '.')
                {
                    mp[b[i][j]]++;
                }
                if (mp[b[i][j]] > 1)
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            unordered_map<char, int> mp;
            for (int j = 0; j < 9; j++)
            {
                if (b[j][i] != '.')
                {
                    mp[b[j][i]]++;
                }
                if (mp[b[j][i]] > 1)
                    return false;
            }
        }
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                unordered_map<char, int> mp;
                for (int l = i; l < i + 3; l++)
                {
                    for (int k = j; k < j + 3; k++)
                    {
                        if (b[l][k] != '.')
                        {
                            mp[b[l][k]]++;
                        }
                        if (mp[b[l][k]] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};