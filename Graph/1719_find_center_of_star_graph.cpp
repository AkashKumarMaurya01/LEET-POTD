#include <bits/stdc++.h>
using namespace std;
// time O(n)   spaceO(m)
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {

        unordered_map<int, int> mp;
        int n = edges.size();
        for (auto i : edges)
        {
            mp[i[0]]++;
            mp[i[1]]++;
        }

        int val = 0;

        for (auto i : mp)
        {
            if (i.second == n)
            {
                val = i.first;
                break;
            }
        }

        return val;
    }
};
// time O(2)   spaceO(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // if x is the center of start graph it will present in all the array
        int u = edges[0][0];
        int v = edges[0][1];
        
        if(u ==edges[1][0] || u == edges[1][1] ) return u;
        return v;
    }
};
// aproach if the start element is present then it will we in all the node which means two node have definately one  common element 