/**
491[M]. Increasing Subsequence
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
**/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int> > s;
        vector<int> path;
        dfs(nums, s, path, 0);
        vector<vector<int> > res(s.begin(), s.end());
        return res;

    }
    void dfs(vector<int> &nums, set<vector<int> > &res, vector<int>&path, int start)
    {
        if(start==nums.size()&&path.size()>1) 
        {
           res.insert(path);
           return;
        }
        if(start>nums.size()) return;
        dfs(nums, res, path, start+1);
        
        for(int i=start;i<nums.size();i++)
        {
            bool push=false;
            if(path.size()==0||nums[i]>=path[path.size()-1]) 
            {
                push=true;
                path.push_back(nums[i]);
            }
            dfs(nums,res, path, i+1);
            if(push)path.pop_back();
        }
    }
};
