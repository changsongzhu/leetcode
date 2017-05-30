/**
230[M]. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *cur=root;
        int cnt=0;
        while(root)
        {
            stk.push(root);
            root=root->left;
        }
        while(!stk.empty())
        {
            TreeNode *node=stk.top();stk.pop();
            cnt++;
            if(cnt==k) return node->val;
            if(node->right)
            {
                node=node->right;
                while(node)
                {
                    stk.push(node);
                    node=node->left;
                }
            }
        }
        return -1;
    }
};

