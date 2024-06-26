#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void Inorder(TreeNode*root, vector<int>&Arr)
    {
        if(root==NULL)return;
        Inorder(root->left,Arr);
        Arr.push_back(root->val);
        Inorder(root->right,Arr);
    }

    TreeNode*solve(int l , int r , vector<int>&Arr )
    {
        if(l>r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode*root = new TreeNode(Arr[mid]);
        root->left = solve(l , mid-1 ,Arr );
        root->right = solve(mid+1 , r ,Arr);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
       TreeNode* temp = root;
       vector<int>Arr;

       Inorder(temp , Arr); // save all the array into sorted form into the vector using inodere traversal 
       int l =0;
       int r =Arr.size()-1;
       return solve( 0 ,r , Arr); 
       // assign mid to be root value and l to mid -1 left subtree bcz left sub tree value will be less than mid 
       // assign mid+1 to r right subtree and right subtree value are greater than mid in the array 
 
    }
};