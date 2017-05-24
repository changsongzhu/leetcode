/**
229[M]. Majority Number II
 
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
**/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int a=0, b=0;
        int ca=0,cb=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a) ca++;
            else if(nums[i]==b) cb++;
            else if(ca==0) {a=nums[i];ca++;}
            else if(cb==0) {b=nums[i];cb++;}
            else {ca--;cb--;}
        }
        ca=cb=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a) ca++;
            else if(nums[i]==b) cb++;
        }
        if(ca>nums.size()/3) res.push_back(a);
        if(cb>nums.size()/3) res.push_back(b);
        return res;
   }
};
