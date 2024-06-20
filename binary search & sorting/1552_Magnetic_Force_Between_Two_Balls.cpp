#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Ispossibleplace(int force , vector<int>&position , int m)
    {
        int prevplace = position[0]; // place a ball at 0 index
        int countplace =1;                // count 1

        for(int i=1;i<position.size();i++)
        {
            int currpos = position[i];
            if(currpos-prevplace>=force)
            {
                countplace++;
                prevplace = currpos;
            }
            if(countplace==m)break;
        }
        return countplace==m;
    }
    int maxDistance(vector<int>& position, int m) 
    {
        int n = position.size();
        sort(begin(position) , end(position));
        int minforce =1;
        int maxforce = position[n-1] - position[0];

        int ans = 0;
        while(minforce<=maxforce)
        {
            int midforce = minforce + (maxforce-minforce)/2;
            if(Ispossibleplace(midforce , position , m))
            {
                ans = midforce;
                minforce = midforce+1;
            }
            else
            {
                maxforce = midforce-1;
            }

        }
        return ans;
    }
};