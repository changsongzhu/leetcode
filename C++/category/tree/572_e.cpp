/**
572[E]. Subtree of another tree
 
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
Example 1:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
       ostringstream s1, s2;
       serialize(s, s1);
       serialize(t, s2);
       return s1.str().find(s2.str()) != string::npos; 
    }
    void serialize(TreeNode* node, ostringstream & os)
    {
        if(!node) os<<",#";
        else
        {
            os<<","<<node->val;
            serialize(node->left, os);
            serialize(node->right, os);
        }
    }
};
