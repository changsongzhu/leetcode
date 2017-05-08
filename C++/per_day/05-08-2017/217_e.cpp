/**
217[E]. Contains Duplicates

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

**/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(auto n:nums)
        {
            if(mp.find(n) != mp.end()) return true;
            else mp[n]++;
        }
        return false;
    }
};

