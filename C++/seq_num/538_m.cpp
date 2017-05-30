/**
538[M]. Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
Example:
Input: The root of a Binary Search Tree like this:
                5
              /   \
       	     2     13
 
Output: The root of a Greater Tree like this:
           18
          /   \
      	20     13
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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        int total_sum=0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *node=stk.top();stk.pop();
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
            total_sum+=node->val;
        }
        int sum=0;
        TreeNode *cur=root;
        while(cur)
        {
            stk.push(cur);
            cur=cur->left;
        }
        while(!stk.empty())
        {
            TreeNode *node=stk.top();stk.pop();
            int tmp=node->val;
            node->val=total_sum-sum;
            sum+=tmp;
            node=node->right;
            while(node)
            {
                stk.push(node);
                node=node->left;
            }
        }
        return root;

    }

};
