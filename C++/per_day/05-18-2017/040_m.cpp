/**
40[M]. Combination Sum II
 
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[  
[1, 7],  
[1, 2, 5],  
[2, 6],  
[1, 1, 6]
]
**/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(res, path, candidates, 0, target);
        return res;

    }
    void dfs(vector<vector<int> > &res, vector<int> &path, vector<int>&nums, int start, int target)
    {
        if(target==0)
        {
           res.push_back(path);
           return;
        }
        if(target<0) return;
        for(int i=start;i<nums.size();i++)
        {
            if(i!=start&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(res, path, nums, i+1, target-nums[i]);
            path.pop_back();
        }
    }
};
