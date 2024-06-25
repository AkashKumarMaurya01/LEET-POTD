#include <bits/stdc++.h>
using namespace std;

// just not show errror we ad this lines
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




void solve(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;

    solve(root->right, sum);
    sum += root->val;
    root->val = sum;
    solve(root->left, sum);
}
class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};

//  approach : we have to just create a BST where we have to create a new bst where node value should be grater other
//  we know that right element is always greter than left
//  we are just traverse right most then start updating the all the node value with sum of right most