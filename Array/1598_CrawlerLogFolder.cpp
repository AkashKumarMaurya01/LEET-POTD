#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        int n = logs.size();
        for(int i=0;i<n;i++)
        {
            if(logs[i]=="./") continue;
            if(logs[i]=="../")
            {
                count--;
                if(count<=0)count=0;
            }
            else if(logs[i]!="../")
            {
                count++;
            }
        }
        if(count<0) return 0;
        return count;
        
    }
};


// simple and easy : ../ tobackward else forward count++