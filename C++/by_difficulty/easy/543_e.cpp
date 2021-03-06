/**
543[E]. Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
Example:
Given a binary tree 
         1
         / \
        2   3
       / \
      4   5    


Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
*/
 
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        helper(root, res);
        return res;   
    }
    int helper(TreeNode *root, int &res)
    {
       if(root==NULL) return 0;
       int left=helper(root->left, res);
       int right=helper(root->right, res);
       res=max(res, right+left+1);
       return max(left, right)+1;
    }
};

