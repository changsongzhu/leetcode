/**
128[H]. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.

**/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end()) continue;
            m.erase(nums[i]);
            int prev=nums[i]-1,next=nums[i]+1;
            while(m.find(prev)!=m.end()) m.erase(prev--);
            while(m.find(next)!=m.end()) m.erase(next++);
            res=max(res, next-prev+1-2);
        }
        return res;
    }
};




class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;
        for(auto i:nums)
        {
            if(!s.count(i)) continue;
            s.erase(i);
            int prev = i-1, next = i+1;
            while(s.count(prev)) s.erase(prev--);
            while(s.count(next)) s.erase(next++);
            result = max(result, next-prev-1);
        }
        return result;
    }
};

