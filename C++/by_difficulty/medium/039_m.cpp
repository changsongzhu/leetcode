/**
39[M]. Combination Sum
 
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[  
[7],  
[2, 2, 3]
]
**/
 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            path.push_back(nums[i]);
            dfs(res, path, nums, i, target-nums[i]);
            path.pop_back();
        }
    }
};
