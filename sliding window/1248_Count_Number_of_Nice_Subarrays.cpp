
//https://youtu.be/JpXlsCAD1kg solution 
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();

        int prevcount = 0;
        int oddcount = 0;
        int result = 0;

        int i = 0;
        int j = 0;
        while (j < n)
        {
            if (nums[j] % 2 == 1)
            {
                oddcount++;
                prevcount = 0;
            }
            while (oddcount == k)
            {
                prevcount++;

                if (i < n && nums[i] % 2 == 1)
                {
                    oddcount--;
                }
                i++;
            }
            result += prevcount;
            j++;
        }
        return result;
    }
};





// using map 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]= 1;
        int count=0;
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            {
                count++;
            }
            if(mp.find(count-k)!=mp.end())
            {
                result+=mp[count-k];
            }
           mp[count]++;
            
        }
        return result;
    }
};