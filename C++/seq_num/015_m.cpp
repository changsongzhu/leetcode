/**
15[M]. 3Sum
 
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4], 
A solution set is:
[  
[-1, 0, 1],  
[-1, -1, 2]
]

**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(res, path, nums, 0, 0, 3);
        return res;
   }
    void dfs(vector<vector<int> > &res, vector<int>&path, vector<int> &nums, int start, int value, int count)
    {
        if(path.size()==count)
        {
            int sum=0;
            for(auto a:path) sum+=a;
            if(sum==value) res.push_back(path);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            if(i!=start&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(res, path, nums, i+1, value, count);
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return res;
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]>0) break;
            if(k!=0&&nums[k]==nums[k-1]) continue;
            int i=k+1,j=nums.size()-1;
            int target = 0-nums[k];
            while(i<j)
            {
                if(nums[i]+nums[j]==target)
                {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i<j&&nums[i]==nums[i+1]) i++;
                    while(i<j&&nums[j]==nums[j-1]) j--;
                    i++;
                    j--;
                }
                else if(nums[i]+nums[j]<target) i++;
                else j--;
            }
        }
        return res;

    }
};
