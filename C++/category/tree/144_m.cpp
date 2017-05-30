/**
144[M]. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1 	
    \
     2 	
    /	
   3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> res;
        if(root)stk.push(root);
        while(!stk.empty())
        {
            TreeNode *tmp=stk.top();stk.pop();
            res.push_back(tmp->val);
            if(tmp->right) stk.push(tmp->right);
            if(tmp->left) stk.push(tmp->left);
        }
        return res;
    }
};

