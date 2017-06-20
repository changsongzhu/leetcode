/**
416[M]. Partition Equal Sub Sum
 Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:
Input: [1, 5, 11, 5] 
Output: true 
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:
Input: [1, 2, 3, 5] 
Output: false 
Explanation: The array cannot be partitioned into equal sum subsets. 
**/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums=accumulate(nums.begin(), nums.end(), 0);
        if(sums&1) return false;
        int sum=sums>>1;
        bool dp[sum+1];
        fill_n(&dp[0], sum+1, false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=sum;j>=nums[i];j--)
               dp[j]=dp[j]||dp[j-nums[i]];
        }
        return dp[sum];
    }
};

