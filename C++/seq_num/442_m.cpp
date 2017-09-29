/**
442[M]. Find all Duplication in an Array
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?
**/

//follow up Solution
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i+1&&nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1) res.push_back(nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       map<int, int> mp;
       for(int i=0;i<nums.size();i++)
       {
           mp[nums[i]]++;
       }
       vector<int> res;
       for(map<int, int>::iterator it=mp.begin();it!=mp.end();it++)
       {
           if(it->second==2) res.push_back(it->first);
       }
       return res;
        
    }
};
