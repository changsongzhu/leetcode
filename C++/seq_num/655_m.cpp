/**
655[M]. Print Binary Tree
Print a binary tree in an m*n 2D string array following these rules:
The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]


Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]


Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]


Note: The height of binary tree is in the range of [1, 10].
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
class Solution {
public:
    vector<vector<string> > printTree(TreeNode *root){
        int height=depth(root);
        int width=pow(2, row)-1;
        vector<vector<string> >res(height, vector<string>(width, ""));
        helper(res, 0, 0, width, root);
        return res;
    }
    void helper(vector<vector<string>  >&res, int level, int left, int right, TreeNode *root)
    {
        if(root==NULL) return;
        int mid=left+(right-left)/2;
        res[level][mid]=root->val;
        helper(res, level+1, left, mid-1, root->left);
        helper(res, level+1, mid+1, right, root->right);
    }
    int depth(TreeNode *root)
    {
        if(root==NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int row=depth(root);
        int col=pow(2, row)-1;
        vector<vector<string> > res(row, vector<string>(col, ""));
        helper(res, 0, 0, row, root);
        return res;
    }
    void helper(vector<vector<string> > &res, int left, int level, int row, TreeNode *root)
    {
        if(root==NULL) return;
        int len=pow(2, row-level);
        res[level][left+(len-1)/2]=to_string(root->val);
        helper(res, left, level+1, row, root->left);
        helper(res, left+len/2, level+1, row,root->right);
    }
    int depth(TreeNode *root)
    {
        if(root==NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
};

