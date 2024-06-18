#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        vector<pair<int, int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = {difficulty[i], profit[i]};
        }
        int w = worker.size();
        int max_profit = 0;
        for (int i = 0; i < w; i++)
        {
            int profit = 0;
            for (int j = 0; j < n; j++)
            {
                if (worker[i] >= ans[j].first)
                {
                    profit = max(ans[j].second, profit);
                }
            }
            max_profit += profit;
        }
        return max_profit;
    }
};