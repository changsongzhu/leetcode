/**
549[M]. Binary Tree Longest Consecutive Sequence II

Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
Example 1:
Input:
    	 1
   	/ \
       2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
 
Example 2:
Input:
    	 2
   	/ \
       1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 
Note: All the values of tree nodes are in the range of [-1e7, 1e7].
**/

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res=0;
        helper(root, NULL, res);
        return res;
    }
    pair<int, int> helper(TreeNode *node, TreeNode *parent, int &res)
    {
        if(root==NULL) return 0;
        int inc=0, dec=0;
        auto left=helper(node->left, node, res);
        auto right=helper(node->right,node, res);
        res = max(res, left.first+right.second+1);
        res = max(res, left.second+right.first+1);
        if(parent!=NULL&&node->val==parent->val+1)
            inc=max(left.first,right.first)+1;
        if(parent!=NULL&&node->val+1==parent->val)
            dec=max(left.second, right.second)+1;
        return {inc, dec};
    }
};

