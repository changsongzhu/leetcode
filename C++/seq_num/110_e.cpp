/**

110[E]. Balanced Binary Tree
 
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int left = depth(root->left);
        int right = depth(root->right);
        
        if(abs(left-right)>1||!isBalanced(root->left) || !isBalanced(root->right)) return false;
        
        return true;
    }
    int depth(TreeNode* root)
    {
        if(root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};

