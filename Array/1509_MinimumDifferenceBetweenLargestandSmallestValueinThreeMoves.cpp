#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
         if(n<=3) return 0;
         int first_mini = nums[n-4]-nums[0];
         int second_mini = nums[n-3] - nums[1];
         int third_mini = nums[n-2] - nums[2];
         int fourth_min =  nums[n-1] - nums[3];
         return min({first_mini ,second_mini ,third_mini ,fourth_min });


    }
};