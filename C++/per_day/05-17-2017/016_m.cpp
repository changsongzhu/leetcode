/**
16[M]. 3Sum Cloest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.  	
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). 
**/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=INT_MAX;
        sort(nums.begin(), nums.end());
        for(int k=0;k<nums.size()-2;k++)
        {
            if(k!=0&&nums[k]==nums[k-1]) continue;
            int i=k+1,j=nums.size()-1;
            while(i<j)
            {
                int sums=nums[i]+nums[j]+nums[k];
                if(res==INT_MAX)
                    res=sums;
                else if(abs(sums-target)<abs(res-target))
                {
                    res=sums;
                }
                if(sums>target)--j;
                else ++i;
            }
        }
        return res;
   }
};
