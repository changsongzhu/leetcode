/**
260[M]. Single Number 3
 
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

**/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       map<int, int> mp;
       vector<int> res;
       for(auto a:nums)
       {
          if(mp.find(a)!=mp.end()) mp.erase(a);
          else mp[a]++;
       }
       for(auto a:mp) res.push_back(a.first);
       return res;
    }
};

