/**
108[E].Convert Sorted Array to Binary Search Tree
 
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

**/

class Solution {
public:
     TreeNode* sortedArrayToBST(vector<int>& nums) {
         return helper(nums, 0, nums.size()-1);
     }
     
     TreeNode *helper(vector<int>& nums, int start, int end)
     {
         while(start>end) return NULL;
         int mid = start + (end-start)/2;
         TreeNode *left = helper(nums, start, mid-1);
         TreeNode *node = new TreeNode(nums[mid]);
         TreeNode *right = helper(nums, mid+1, end);
         node->left=left;
         node->right=right;
         return node;
     }
};


// This Solution is used to compare with 109[M]
class Solution {
public:
     TreeNode* sortedArrayToBST(vector<int>& nums) {
         int cnt=0;
         return helper(nums, 0, nums.size()-1, cnt);
     }
     
     TreeNode *helper(vector<int>& nums, int start, int end, int &cnt)
     {
         while(start>end) return NULL;
         int mid = start + (end-start)/2;
         TreeNode *left = helper(nums, start, mid-1, cnt);
         TreeNode *node = new TreeNode(nums[cnt++]);
         TreeNode *right = helper(nums, mid+1, end, cnt);
         node->left=left;
         node->right=right;
         return node;
     }
};
