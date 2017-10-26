/**
53[E]. Maximum Subarray
 
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

**/


//DP Solution
class Solution {
public:
    int maxSubArray(vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        int mx=dp[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=nums[i]+(dp[i-1]>0?dp[i-1]:0);
            mx=max(mx, dp[i]);
        }
        return mx;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	if(nums.size()==0) return 0;
        int res=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            res=max(res, sum);
            sum=(sum>0)?sum:0;
        }
        return res;
    }
};
