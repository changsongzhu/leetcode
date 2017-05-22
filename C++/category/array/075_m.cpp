/**
75[M]. Sort Colors
 
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
**/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==0) return;
        int red_index=0;
        int blue_index=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                swap(nums[red_index++], nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==0)
                swap(nums[blue_index--], nums[i]);
        }
   }
};
