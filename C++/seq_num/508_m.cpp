/**
508[M]. Most Frequent Subtree Sum
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.
Examples 1
Input:
  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:
  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL) return {};
        map<int, int> mp;
        vector<int> res;
        priority_queue<pair<int, int> > q;
        int sum=0;
        dfs(root, mp);
        for(auto a:mp) q.push({a.second, a.first});
        int k=q.top().first;
        while(!q.empty()&&k==q.top().first)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    int dfs(TreeNode* root, map<int, int>&mp)
    {
        if(root==NULL) return 0;
        int left=dfs(root->left, mp);
        int right=dfs(root->right, mp);
        int sum=left+right+root->val;
        mp[sum]++;
        return sum;
    }
};
