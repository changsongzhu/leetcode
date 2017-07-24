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
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j!=i+1&&nums[j]==nums[j-1]) continue;
                int left=j+1, right=nums.size()-1;
                while(left<right)
                {
                   if(nums[left]+nums[right]+nums[i]+nums[j]==target)
                   {
                       res.push_back({nums[i], nums[j], nums[left], nums[right]});
                       while((left+1)<right&&nums[left]==nums[left+1]) left++;
                       while(left<(right-1)&&nums[right]==nums[right-1]) right--;
                       left++;right--;
                   }
                   else if(nums[left]+nums[right]+nums[i]+nums[j]<target)
                       left++;
                   else right--;
                }
            }
        }
        return res;
    }
};


//DFS Solution: TLE. 
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


/**
Extended Question

How about k-Sum

**/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int k, int target) {
        vector<vector<int> > res;
        if(nums.size()<k) return res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(res, path, nums, 0, k, target);
        return res;
    }
    void helper(vector<vector<int> > &res, vector<int> &path, vector<int> &nums, int start, int k, int target)
    {
        if(path.size()==k&&target==0)
        {
            res.push_back(path);
            return;
        }
        if(path.size()==k) return;
        for(int i=start;i<nums.size();i++)
        {
            if(i!=start&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(res, path, nums, i+1, k, target-nums[i]);
            path.pop_back();
        }
    }
};
