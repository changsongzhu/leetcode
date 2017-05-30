/**
96[M]. Unique BST
 
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.
   1     	3 	3      2  	1
    \   	/ 	/      / \  	\
     3 	2 	1      1   3  	2
    / 	/   	\             	\
   2 	1     	2             	3
class Solution {
public: 
    int numTrees(int n) {
        if(n<=0) return 0;
        vector<int> dp(n+1, 0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
               dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};  
 
 
98[M]. Valid Binary Search Tree
 
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
  2	
 / \
1   3
Binary tree [2,1,3], return true.
Example 2:
    1 
   / \
  2   3
Binary tree [1,2,3], return false.
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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool hepler(TreeNode *root, long long min, long long max)
    {
        if(root==NULL)return true;
        return (root->val>min&&root->val<max&&
                helper(root->left, min, root->val)&&
                helper(root->right, root->val, max));
    }
};

