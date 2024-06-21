#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n =customers.size();
        int unsatisfied_customer = 0;
      
        for(int i=0;i<minutes;i++){//1 ,2, 3 ,4 ,5....minutes
           unsatisfied_customer+=customers[i]*grumpy[i];  
        }

        int i=0;
        int j=minutes; // minutes....n
        int max_unisatisfied=unsatisfied_customer;
        while(j<n)
        {
           
            unsatisfied_customer+=customers[j]*grumpy[j];
            unsatisfied_customer-=customers[i]*grumpy[i]; 
            // agar grumpy[i] ==0 hua to total multtiply 0 ho jayega agar nhi to customer wali value add ho jayegi 
            max_unisatisfied = max(max_unisatisfied ,unsatisfied_customer);
            i++;
            j++;

        }
          int satisfied=0;
        for(int i=0;i<n;i++)
        {
           satisfied +=customers[i]*(1-grumpy[i]);       
        }
        return (satisfied+max_unisatisfied);
    }
};

//////-----------------------------------------------------------------------------------------/
// same but in diff way 

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n =customers.size();
        int unsatisfied_customer = 0;
      
        for(int i=0;i<minutes;i++){//1 ,2, 3 ,4 ,5....minutes
           unsatisfied_customer+=customers[i]*grumpy[i];  
        }

        int i=0;
        int j=minutes; // minutes....n
        int max_unisatisfied=unsatisfied_customer;
        while(j<n)
        {
           
            unsatisfied_customer+=customers[j]*grumpy[j];
            unsatisfied_customer-=customers[i]*grumpy[i]; 
            // agar grumpy[i] ==0 hua to total multtiply 0 ho jayega agar nhi to customer wali value add ho jayegi 
            max_unisatisfied = max(max_unisatisfied ,unsatisfied_customer);
            i++;
            j++;

        }
          int satisfied=0;
        for(int i=0;i<n;i++)
        {
           satisfied +=customers[i]*(1-grumpy[i]);       
        }
        return (satisfied+max_unisatisfied);
    }
};