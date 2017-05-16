/**
270[E]. Closest Binary Search Tree Value
 
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
Note:
·       Given target value is a floating point.
·       You are guaranteed to have only one unique value in the BST that is closest to the target.
**/

class Solution {
public:
    int closestValue(TreeNode* root, double target) 
    {
        int res = root->val;
        while(root)
        {
            if(abs(res-target) >=(root->val-target)
               res = root->val;

            root=(target<root->val)?root->left:root->right;
        }
       return res;
    }
};

