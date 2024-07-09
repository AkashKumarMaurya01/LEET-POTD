
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int sum=customers[0][0]+customers[0][1];
        double diff = sum - customers[0][0];
        for(int i=1;i<n;i++)
        {
            sum+= customers[i][1];
            sum = max(sum ,(customers[i][0]+customers[i][1]));
            diff+=(sum - customers[i][0]);
        }
        return double(double(diff)/double(n));
    }
};

