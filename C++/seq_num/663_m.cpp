/**
663[M]. Equal Tree Partition
Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.
Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15


Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.


Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
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

//Refined Solution
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
    bool checkEqualTree(TreeNode* root) {
        map<int, int> m;
        int total=sum(root, m);
        if(total&1) return false;
        if(total==0) return m[total]>1;
        return m.count(total/2)!=0;
        
    }
    int sum(TreeNode *root, map<int, int> &m)
    {
        if(root==NULL) return 0;
        int left=sum(root->left, m);
        int right=sum(root->right, m);
        m[left+right+root->val]++;
        return left+right+root->val;
        
    }
};


class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL))return false;
        int sum=sumTree(root);
        if(sum&1) return false;
        return isExist(root->left, sum/2)||isExist(root->right, sum/2);
    }
    bool isExist(TreeNode *root, int sum)
    {
        if(root==NULL) return false;
        return (sumTree(root)==sum)||(isExist(root->left, sum))||(isExist(root->right, sum));
    }
    int sumTree(TreeNode *root)
    {
        if(root==NULL) return 0;
        int left=sumTree(root->left);
        int right=sumTree(root->right);
        return left+right+root->val;
    }

};

