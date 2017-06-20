/**
300[M]. Longest increasing subsequence
 
Given an unsorted array of integers, find the length of longest increasing subsequence.
For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
**/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int n=nums.size();
        vector<int> dp(n, 0);
        int res=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i], dp[j]+1);
            res=max(res, dp[i]);
        }
        return res;
    }
};

class Solution{
public:
    int lengthOfLDS(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int n=nums.size();
        vector<int> dp(n, 0);
        int res=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
                if(nums[j]>nums[i])
                    dp[i]=max(dp[i], dp[j]+1);
            res =max(res, dp[i]);
        }
        return res;
    }
};

