/**
222[M]. Count Complete Tree Nodes
 
Given a complete binary tree, count the number of nodes.
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int left_depth=0;
        TreeNode *cur=root;
        while(cur)
        {
            left_depth++;
            cur=cur->left;
        }
        int right_depth=0;
        cur=root;
        while(cur)
        {
            right_depth++;
            cur=cur->right;
        }
        if(left_depth==right_depth) return pow(2, left_depth)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
        
    }
};

