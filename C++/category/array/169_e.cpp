/**
169[E]. Majority Element
 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

**/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int maj=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != maj)
            {
                count--;
            }
            else
            {
                count++;
            }
            if(count==0)
            {
                maj=nums[i];
                count=1;
            }
        }
        return maj;
    }
};

