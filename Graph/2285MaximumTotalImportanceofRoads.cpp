#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>&roads) {

    
        vector<int>degree(n,0);
        //calculate the degree;
        for(int i =0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];

            degree[u]++;
            degree[v]++;
        }  

      sort(degree.begin() , degree.end());

      long long value =1;
      long long sum =0;
      for(auto i:degree)
      {
           sum+=(i*value);
           value++;
      }

      return sum;


    }
};

// jo node max degree h usako max value assgin kiya h 