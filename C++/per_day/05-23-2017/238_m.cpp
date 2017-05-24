/**
238[M]. Product of Array Except Self
 
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
**/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==0) return res;
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(i==0) left[i]=1;
            else left[i]=left[i-1]*nums[i-1];

            if(i==0) right[nums.size()-1-i]=1;
            else right[nums.size()-1-i]=right[nums.size()-i]*nums[nums.size()-i];
        }
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(left[i]*right[i]);
        }
        return res;
   }
};
