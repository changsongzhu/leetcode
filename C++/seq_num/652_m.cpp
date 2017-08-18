/**
652[M]. Find Duplicate Subtrees
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with same node values.
Example 1: 
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4


The following are two duplicate subtrees:
     2
     /
    4


and
   4


Therefore, you need to return above trees' root in the form of a list.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        map<string, int> m;
        helper(root, res, m);
        return res;
    }
    string helper(TreeNode *root, vector<TreeNode*> &res, map<string, int>&m)
    {
        if(root==NULL)
        {
            return "#";
        }
        string left=helper(root->left, res,  m);
        string right=helper(root->right, res,  m);
        string tmp=left+right+to_string(root->val);
        if(m.find(tmp)!=m.end()&&m[tmp]==1) 
        {
            res.push_back(root);
            m[tmp]++;
        }
        else 
        {
            m[tmp]++; 
        }
        return tmp;
    }
};

