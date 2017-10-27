/**
156[M]. Binary Tree Upside Down
 
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1 

**/ 

//Refined Solution
/*
     Root         L
     /  \   -->  / \

    L    R      R   Root

**/
class Solution{
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root)
    {
        if(!root||!root->left) return root;
        TreeNode *node=upsideDownBinaryTree(root->left);
        root->left->left=root->right;
        root->left->right=root;
        root->left=root->right=NULL;
        return node;
    }

};



class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
       if(!root||!root->left) return root;
       TreeNode *cur_left=root->left;
       TreeNode *cur_right=root->right;
       TreeNode *node=upsideDownBinaryTree(root->left);
       cur_left->left=cur_right;
       cur_left->right=root;
       root->left=root->right=NULL;
       return node;
    }
};
