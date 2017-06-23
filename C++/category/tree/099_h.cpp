/**
99[H]. Recover BST
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> res(2, NULL);
        TreeNode *prev=NULL;
        helper(root, prev, res);
        if(res[0]!=NULL&&res[1]!=NULL)
            swap(res[0]->val, res[1]->val);
    }
    void helper(TreeNode *root, TreeNode * &prev, vector<TreeNode*> &res)
    {
        if(root==NULL) return;
        helper(root->left, prev, res);
        if(prev!=NULL&&root->val<prev->val)
        {
            res[0]=res[0]==NULL?prev:res[0];
            res[1]=root;
        }
        prev=root;
        helper(root->right, prev, res);
    }
};

