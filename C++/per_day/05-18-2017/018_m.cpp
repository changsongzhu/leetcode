/**
18[M]. 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note: The solution set must not contain duplicate quadruplets.
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.  
A solution set is: 
[   
[-1,  0, 0, 1],   
[-2, -1, 1, 2],   
[-2,  0, 0, 2] 
] 
**/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(res, path, nums, 0, target);
        return res;
    }
    void dfs(vector<vector<int> > &res, vector<int> &path, vector<int>&nums, int start, int target)
    {
        if(path.size()==4)
        {
            if(path[0]+path[1]+path[2]+path[3]==target)
                res.push_back(path);
            return;
        }
        
        for(int i=start;i<nums.size();i++)
        {
            if(i!=start&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(res, path, nums, i+1, target);
            path.pop_back();
        }
    }
};
