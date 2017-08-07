/**
653[E]. Path Sum IV -- Input is a BST
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True


Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
**/

Output: False
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
    bool findTarget(TreeNode* root, int k) {
        map<int, int> m;
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *cur=stk.top();stk.pop();
            if(m.count(k-cur->val)) return true;
            m[cur->val]++;
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }
        return false;
     
    }
};

