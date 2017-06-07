/**
213[M]. House Robber II

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
**/
 
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=1) return nums.size()==1?nums[0]:0;

        return max(rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1));
    }
    int rob(vector<int>& nums, int start, int end)
    {
        int len=end-start+1;
        if(len==1) return nums[start];
        int dp[len+1];
        dp[0]=0;
        dp[1]=nums[start];
        for(int i=2;i<=len;i++)
        {
           dp[i]= max(dp[i-2]+nums[start+i-1], dp[i-1]);
        }
        return dp[len];
    }
};

