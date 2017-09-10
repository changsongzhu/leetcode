/**
673[M]. Number of Longest Increasing Subsequence

Given an unsorted array of integers, find the number of longest increasing subsequence.
Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].


Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.


Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
**/


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int m=nums.size();
        vector<int> dp(m, 1);
        vector<int> cnt(m, 1);
        int len=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        cnt[i]=cnt[j];
                        dp[i]=dp[j]+1;
                    }
                    else if(dp[i]==(dp[j]+1))
                    {
                        cnt[i]+=cnt[j];
                    }
                }
            } 
            len=max(len, dp[i]);
        }
        int res=0;
        for(int i=0;i<m;i++)
        {
            if(dp[i]==len) res+=cnt[i];       
        }
        return res;
    }
};

