#include<bits/stdc++.h>
using namespace std;
// solution 
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int FlippedPast_i =0;
        vector<bool>isFliped(n,false); 
        int result =0;
        for(int i=0;i<n;i++)
        {
            if(i>=k && isFliped[i-k]==true)
            {
                FlippedPast_i--;
            }
            // condition when we have to fliped-> nums[i]=0 and fliped is even(fliped%2==0) or nums[i]==1 and fliped is odd 
            if(FlippedPast_i%2==nums[i]) // in this condition nums[i] is current condition is Zero and after fliped it is going to 1 after fliped if i+k > n then it can not maked to be one so we have to return -1;
            {

                FlippedPast_i++;
                isFliped[i] = true;
                if(i+k>n) return -1;
                result ++;
                  
            }
        }
        return result;
       
    }
};

// solution :2 removed isfliped vector and placed another value marker_before =9
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int FlippedPast_i =0;
        int marked_before = 9; // it can be any number as you desired but avoid 0 ,1 

        int result =0;
        for(int i=0;i<n;i++)
        {
            if(i>=k && nums[i-k]==9)
            {
                FlippedPast_i--;
            }
            // condition when we have to fliped-> nums[i]=0 and fliped is even(fliped%2==0) or nums[i]==1 and fliped is odd 
            if(FlippedPast_i%2==nums[i]) // in this condition nums[i] is current condition is Zero and after fliped it is going to 1 after fliped if i+k > n then it can not maked to be one so we have to return -1;
            {

                FlippedPast_i++;
                nums[i] = 9;
                if(i+k>n) return -1;
                result ++;
                  
            }
        }
        return result;
       
    }
};
//solution 3 
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int FlippedPast_i =0;
        deque<int>Flipque;
        int result =0;
        for(int i=0;i<n;i++)
        {
            if(i>=k)
            {
                FlippedPast_i-=Flipque.front();
                Flipque.pop_front();
            }
            // condition when we have to fliped-> nums[i]=0 and fliped is even(fliped%2==0) or nums[i]==1 and fliped is odd 
            if(FlippedPast_i%2==nums[i]) // in this condition nums[i] is current condition is Zero and after fliped it is going to 1 after fliped if i+k > n then it can not maked to be one so we have to return -1;
            {

                FlippedPast_i++;
               
                if(i+k>n) return -1;
                result ++;
                Flipque.push_back(1);//means we had fliped the at index i
                  
            }
            else
            {
                Flipque.push_back(0); // means we dont fliped  at index i 
            }
        }
        return result;
       
    }
};