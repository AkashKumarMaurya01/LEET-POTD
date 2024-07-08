#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int passThePillow(int n, int time)
    {
        int one_cycle_time = 2 * n - 2;
        int pos = time % one_cycle_time;
        return 1 + (pos >= n ? one_cycle_time - pos : pos);
    }
};
