/**
152[M]. Maximum Product Subarray
 
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
**/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int>dp_min(nums.size(), 0);
        vector<int>dp_max(nums.size(), 0);
        dp_min[0]=dp_max[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp_min[i]=min(nums[i]*dp_min[i-1], min(nums[i]*dp_max[i-1], nums[i]));
            dp_max[i]=max(nums[i]*dp_max[i-1], max(nums[i]*dp_min[i-1], nums[i]));
            res=max(res, dp_max[i]);
        }
        return res;
   }
};
