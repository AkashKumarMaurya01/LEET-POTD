#include<bits/stdc++.h>
using namespace std;
// Recursive solution
class Solution {
public:
    int solve(int n , int k )
    {
        if(n==1) return 0;

        int winnerindex = (solve(n-1 , k)+k)%n;
        return winnerindex;

    }
    int findTheWinner(int n, int k) {

        int winner  =  solve(n ,k);
        return winner+1;

        
    }
};
//using queue data structure
class Solution {
public:
    int findTheWinner(int n, int k) {

    queue<int>que;

    for(int i=1;i<=n;i++)
    {
        que.push(i);
    }

    while(que.size()!=1)
    {
        for(int i=1;i<=k-1;i++)
        {
            que.push(que.front());
            que.pop();
        }
        que.pop();
    }
    return que.front();
    }
};

// using array 
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
           arr.push_back(i+1);
        }
       int i=0;
       while(arr.size()!=1)
       {
          int index =(i+k-1)%arr.size();
          arr.erase(arr.begin()+index);
          i = index ; 
       }

       return arr[0];

    }
};