/**
501[E]. Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
  1
    \
     2
    /
   2


return [2].
Note: If a tree has more than one mode, you can return them in any order.
Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int cur  = 0;
        int max  = INT_MIN;
        int prev = 0;
        helper(root, result,prev, cur, max);
        return result;
    }
    
    
    void helper(TreeNode * root, vector<int> &result, int& prev, int& cur, int& max)
    {
        if(root == NULL) return;
        helper(root->left, result, prev, cur, max);
        if(cur != 0)
        {
            if(root->val == prev)
            {
                cur++;
                if(cur>max)
                {
                    result.clear();
                    result.push_back(root->val);
                    max = cur;
                }
                else if(cur == max)
                {
                    result.push_back(root->val);
                }
            }
            else
            {
                cur = 1;
                prev = root->val;
                if(cur == max)
                    result.push_back(root->val);
            }
        }
        else
        {
            prev = root->val;
            cur = 1;
            max = 1;
            result.push_back(root->val);
        }
        helper(root->right, result, prev, cur, max);
    }
};

