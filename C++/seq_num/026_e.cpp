/**
26[E]. Remove Duplicates from the Sorted Array
 
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums 


**/
//Refined Solution
class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0||nums[i]!=nums[index]) nums[++index]=nums[i];
        }
        return index+1;
    }

};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;

        int index=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[index])
                nums[++index]=nums[i];
        }
        return index+1;
    }
};
