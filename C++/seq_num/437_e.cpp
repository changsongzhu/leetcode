/**
437[E]. Path Sum 3
 
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8        
10  	
/  \
5   -3   
 / \	\
3   2   11  
/ \   \
3  -2   1  
Return 3. 
The paths that sum to 8 are:  
1.  5 -> 3 
2.  5 -> 2 -> 1 
3. -3 -> 11 
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
    int pathSum(TreeNode *root, int sum)
    {
        if(root==NULL) return 0;
        return sums(root, 0, sum)+pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int sums(TreeNode *root, int curSum, int sum)
    {
        if(root==NULL) return 0;
        curSum+=root->val;
        return (curSum==sum)+sums(root->left, curSum, sum)+sums(root->right, curSum, sum);
    }

};


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        int curSum = 0;
        vector<int> path;
        helper(root, sum, curSum, path, count);
        return count;
    }
    
    void helper(TreeNode *root, int sum,int curSum, vector<int>&path,  int &count)
    {
        if(root == NULL) return;
        
        curSum +=root->val;
        path.push_back(root->val);
        
        if(curSum == sum ) count++;
        int tmp = curSum;
        for(int i=0;i<path.size()-1;i++)
        {
            tmp -=path[i];
            if(tmp == sum) count++;
        }
        helper(root->left, sum, curSum, path, count);
        helper(root->right,sum, curSum, path, count);
        path.pop_back();

    }
};

