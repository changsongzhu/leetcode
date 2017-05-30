/**
513[M]. Find Bottom Left Tree Value
Given a binary tree, find the leftmost value in the last row of the tree.
Example 1:
Input:
 
    2
   / \
  1   3
 
Output:
1
Example 2: 
Input:
 
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
 
Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        int res=0;
        int cur_level=0;
        helper(root, res, cur_level, 1);
        return res;
    }
    void helper(TreeNode *root, int &res, int &cur_level, int level)
    {
        if(root==NULL) return;
        if(level>cur_level) { res=root->val;cur_level=level;}
        helper(root->left, res, cur_level, level+1);
        helper(root->right, res, cur_level, level+1);
    }
};

