/**
250[M]. Count Univalue Subtrees
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.
For example:
Given binary tree,
           5
          / \
         1   5
       	/ \   \
       5   5   5
 
return 4.
**/

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res=0;
        dfs(root, res);
        return res;
    }
    bool dfs(TreeNode*root, int &res)
    {
        if(root==NULL) return true;
        bool left=dfs(root->left, res);
        bool right=dfs(root->right, res);
        if(left!=true||right!=true||
           (root->left&&root->val!=root->left->val)||
           (root->right&&root->val!=root->right->val)) return false;
        res++;
        return true;
    } 
};

