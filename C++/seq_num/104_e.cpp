/**
104[E]. Maximum Depth of Binary Tree
 
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode *root)
    {
        if(root == NULL) return 0;  
        return max(helper(root->left), helper(root->right)) + 1;
    }
};

