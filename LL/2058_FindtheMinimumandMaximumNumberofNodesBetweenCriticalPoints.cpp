#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans={-1,-1};
        
        ListNode*prev = head;
        if(prev==NULL) return ans;
        ListNode*curr = head->next;
        if(curr==NULL) return ans;
        ListNode*forward = head->next->next;
        if(forward==NULL) return ans;
        // we are handling atleast
        int firstLM = -1;
        int lastLM = -1;
        int i = 0;
        int mini =  INT_MAX;

        while(forward!=NULL)
        {
            bool isCP = ((curr->val < prev->val && curr->val < forward->val)||(curr->val > prev->val && curr->val > forward->val))?true:false;
           
            if(isCP && firstLM ==-1)
            {
                firstLM = i;
                lastLM = i;
            }
            else if(isCP)
            {
                mini = min(mini , i - lastLM);
                lastLM = i;
                
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            forward = forward->next;
        }
        if(firstLM==lastLM)
        {
            return ans;
        }
        else
        {
            ans[0] = mini;
            ans[1] = lastLM -firstLM;
        }
            return ans;
        
    }
};