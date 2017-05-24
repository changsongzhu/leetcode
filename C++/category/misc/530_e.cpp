/**
530[E]. Minimum Absolute Difference in BST
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
Example:
Input:
 
   1
    \
     3
    /
   2
 
Output:
1
 
Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
**/

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
       int prev=-1;
       int res=INT_MAX;
       helper(root, prev, res);
       return res;
        
    }
    void helper(TreeNode *root, int &prev, int &res)
    {
        if(root==NULL) return;
        helper(root->left, prev, res);
        if(prev !=-1) res=min(res, root->val-prev);
        prev=root->val;
        helper(root->right, prev, res);
    }
};