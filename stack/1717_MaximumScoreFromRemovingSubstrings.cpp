#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removed_str(string&s , string& substr , int val )
    {
        int n = s.size();
        stack<char>st;
        int result =0;

        for(char&ch:s)
        {
            if(!st.empty() && st.top()==substr[0] && ch==substr[1])
            {
               result+=val;
               st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        string str;
        while(!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin() , str.end());
        s=str;
        return result;
    }
   


    int maximumGain(string s, int x, int y) {
         
         string maxstr = (x>y)?"ab":"ba";
         string minstr = (x<y)?"ab":"ba";
        int maxi = max(x,y);
        int mini= min(x,y);
         int result =  removed_str(s , maxstr , maxi);
       
         result+=removed_str(s,minstr , mini);
        

        return result;
        
    }
};