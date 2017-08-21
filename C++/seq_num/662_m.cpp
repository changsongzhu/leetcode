/**
662[M].Maximum Width of Binary Tree
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).


Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).


Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).


Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).




Note: Answer will in the range of 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        vector<vector<int> > path;
        dfs(root, path, 0, 0);
        int res=INT_MIN;
        for(int i=0;i<path.size();i++)
        {
            res=max(res, path[i][path[i].size()-1]-path[i][0]+1);
        }
        return res==INT_MIN?0:res;
    }
    void dfs(TreeNode* root, vector<vector<int> >&path, int index, int level)
    {
        if(root==NULL) return;
        if(path.size()<=level)
        {
            path.push_back({index});
        }
        else
        {
            path[level].push_back(index);
        }
        dfs(root->left, path, index*2+0, level+1);
        dfs(root->right, path, index*2+1, level+1);
    }
};

