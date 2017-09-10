/**
283[E]. Move Zeros
 
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
**/

//Another Solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt=0;
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                nums[index++]=nums[i];
            else
                cnt++;
        }
        for(int j=0;j<cnt;j++)
        {
            nums[nums.size()-1-j]=0;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int cur=0;
       int index=-1;
       while(cur<nums.size())
       {
           if(nums[cur]==0)
           {
               if(index==-1)
               {
                   index=cur;
                   cur++;
               }
               else
               {
                   cur++;
               }
           }
           else
           {
               if(index!=-1)
               {
                   swap(nums[cur], nums[index]);
                   index++;
                   cur++;
               }
               else
               {
                   cur++;
               }
           }
       }
    }
};
