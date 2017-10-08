/*
1[E]. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
Example:
Given nums = [2, 7, 11, 15], target = 9, 
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

//LC 6ms Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                return {m[target-nums[i]], i};
            }
            m[nums[i]]=i;
        }        
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
       vector<int> res(2, -1);
       for(int i=0;i<nums.size();i++){
           for(int j=0;j<nums.size();j++){
               if(nums[i]+nums[j]==target){
                   res[0]=i;
                   res[1]=j;
                   return res;
               }
           }
       }
       return res;
    }
};
