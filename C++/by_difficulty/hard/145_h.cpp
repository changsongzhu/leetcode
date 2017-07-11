/**
145[H]. Binary Tree Postorder Traversal
 
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1 	
    \
     2 	
    /	
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* head=root;
        while(!stk.empty())
        {
            TreeNode *tp=stk.top();
            if((tp->left==NULL&&tp->right==NULL)||tp->left==head||tp->right==head)
            {
               res.push_back(tp->val);
               stk.pop();
               head=tp;
            }
            else
            {
               if(tp->right)stk.push(tp->right);
               if(tp->left) stk.push(tp->left);
            }
        }
        return res;
    }
};

