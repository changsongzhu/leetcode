/**
287[M]. Find the Duplicate Number
 
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
**/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0,slow=0;
        while(1)
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow) break;
        }
        fast=0;
        while(1)
        {
            fast=nums[fast];
            slow=nums[slow];
            if(fast==slow) break;
        }
        return slow;
    }
};
