/**
94[M]. Binary Tree Inorder Traversal
 
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree [1,null,2,3],
   1 	
    \
     2 	
    /	
   3
return [1,3,2].
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* cur=root;
        while(cur)
        {
            stk.push(cur);
            cur=cur->left;
        }
        while(!stk.empty())
        {
            cur=stk.top();stk.pop();
            res.push_back(cur->val);
            cur=cur->right;
            while(cur)
            {
                stk.push(cur);
                cur=cur->left;
            }
        }
        return res;
    }
};

