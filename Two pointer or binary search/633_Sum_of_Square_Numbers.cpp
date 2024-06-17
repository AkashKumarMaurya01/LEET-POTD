#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c == 0 || c == 1)
            return true;
        long long i = 0;
        long long j = sqrt(c);
        long long sum = 0;
        while (i <= j)
        {
            sum = i * i + j * j;
            if (sum < c)i++;
            else if (sum > c)j--;
            else return true;
        }
        return false;
    }
};