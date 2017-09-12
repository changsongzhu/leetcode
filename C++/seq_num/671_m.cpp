/**
671[M]. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.
Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.


Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
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
    int findSecondMinimumValue(TreeNode* root) {
        int mn=INT_MAX;
        int mn_2=INT_MAX;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        vector<int> res;
        while(cur)
        {
            stk.push(cur);
            cur=cur->left;
        }
        while(!stk.empty())
        {
            cur=stk.top();stk.pop();
            if(cur->val<mn)
            {
                mn_2=mn;
                mn=cur->val;
                
            }
            else if(cur->val>mn&&cur->val<mn_2)
            {
                mn_2=cur->val;
            }
            cur=cur->right;
            while(cur)
            {
                stk.push(cur);
                cur=cur->left;
            }
        }
        return mn_2==INT_MAX?-1:mn_2;
        
    }
};
