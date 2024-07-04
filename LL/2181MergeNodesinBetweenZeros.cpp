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
    ListNode* mergeNodes(ListNode* head) {
        
        int sum=0;
        ListNode*temp = NULL;
        ListNode*LL=NULL;
        while(head!=NULL)
        {
            if(head->val!=0)
            {
                sum+=head->val;
            }
            else
            {
                ListNode*curr = new ListNode(sum);
                if(LL==NULL)
                {
                    LL = curr;
                    temp =LL;
                }
                else{
                    LL->next = curr;
                    LL = curr;
                }
                sum=0;
            }
            head = head->next;
        }
        return temp->next;
    }
};

// non zero ko add karo aur naya ll bana lo 