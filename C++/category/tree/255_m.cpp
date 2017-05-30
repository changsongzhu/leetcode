/**
255[M]. Verify Preorder Sequence in Binary Search Tree
 
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.
Follow up:
Could you do it using only constant space complexity?
**/
 
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
    }
    bool dfs(vector<int> &preorder, int start, int end, int min, int max)
    {
        if(start>end) return true;
        int val=preorder[start], i=0;
        if(val>=max||val<=min) return false;
        for(int i=start;i<=end;i++)
        {
            if(preorder[i]>preorder[start]) break;
        }
        return dfs(preorder, start+1, i-1, min, val)&&dfs(preorder, i, end, val, max);
    }
};

