/**
198[E]. House Robber
 
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
**/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> max_val(nums.size()+1, 0);
        max_val[0]=0;
        max_val[1]=nums[0];
        for(int i=2;i<nums.size()+1;i++)
        {
            max_val[i]=max(max_val[i-1], max_val[i-2]+nums[i-1]);
        }
        return max_val[nums.size()];
        
    }
};
