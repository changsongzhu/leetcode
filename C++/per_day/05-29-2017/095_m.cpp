/**
que BST II
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
For example,
Given n = 3, your program should return all 5 unique BST's shown below.
   1     	3 	3      2  	1
    \   	/ 	/      / \  	\
     3 	2 	1      1   3  	2
    / 	/   	\             	\
   2 	1     	2             	3
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
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0) return {};
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end)
    {
        vector<TreeNode*> res;
        if(start>end)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left=helper(start, i-1);
            vector<TreeNode*> right=helper(i+1,end);
            for(int l=0;l<left.size();l++)
            {
                for(int r=0;r<right.size();r++)
                {
                    TreeNode *node=new TreeNode(i);
                    node->left=left[l];
                    node->right=right[r];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};

