/**
368[M]. Longest Divisible Subset
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.
Example 1:
nums: [1,2,3]
 
Result: [1,2] (of course, [1,3] will also be ok)
Example 2:
nums: [1,2,4,8]
 
Result: [1,2,4,8]
**/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums){
        int m=nums.size();
        if(m==0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(m, 1), child(m, -1);
        int mx=1, mx_idx=0;//This is for the one element array
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                 if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1)
                 {
                     dp[i]=dp[j]+1;
                     child[i]=j;
                     if(mx<dp[i])
                     {
                         mx=dp[i];
                         mx_idx=i;
                     }
                 }
            }
        }
        vector<int> res;
        for(int i=0;i<mx;i++)
        {
            res.push_back(nums[mx_idx]);
            mx_idx=child[mx_idx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==0) return res;
        vector<int> dp(nums.size(), 0), parent(nums.size(),0);
        int mx=0, mx_idx=0;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=i;j<nums.size();j++)
            {
               if(nums[j]%nums[i]==0&&dp[i]<dp[j]+1)
               {
                   dp[i]=dp[j]+1;
                   parent[i]=j;
                   if(mx<dp[i])
                   {
                       mx=dp[i];
                       mx_idx=i;
                   }
               }
            }
        }
        for(int i=0;i<mx;i++)
        {
            res.push_back(nums[mx_idx]);
            mx_idx=parent[mx_idx];
        }
        return res;
    }
};

