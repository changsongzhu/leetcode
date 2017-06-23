/**
124[M]. Binary Tree Maximum Path Sum
 Given a binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
For example:
Given the below binary tree,
         1      
  	/ \
       2   3
Return 6.

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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode *root, int &res)
    {
        if(root==NULL) return 0;
        int left=dfs(root->left, res);
        int right=dfs(root->right, res);
        int val=root->val;
        if(left>0) val+=left;
        if(right>0) val+=right;
        res=max(res, val);
        if(left<0&&right<0) return root->val;
        else return (left>right)?root->val+left:root->val+right;

    }
};

