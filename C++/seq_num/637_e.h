/**
637[E]. Average of Levels in Binary Tree
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].


Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> nums;
        dfs(res, nums, root, 1);
        return res;      
    }
    void dfs(vector<double>&res, vector<int> &nums, TreeNode *root, int level)
    {
        if(root==NULL) return;
        if(res.size()<level)
        {
            res.push_back(root->val);
            nums.push_back(1);
        }
        else
        {
            res[level-1]=((double)res[level-1]*nums[level-1]+root->val)/(nums[level-1]+1);
            nums[level-1]++;
        }
        dfs(res, nums, root->left, level+1);
        dfs(res, nums, root->right, level+1);
        
    }
};

