/**
594[E]. Longest Harmonious Subsequence
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
**/

class Solution {
public:
    int findLHS(vector<int>& nums) {
       map<int, int> mp;
       for(auto n:nums) mp[n]++;
       int res=0;
       for(auto m:mp)
       {
           if(mp.count(m.first-1))
               res=max(res, m.second+mp[m.first-1];
           else if(mp.count(m.first+1))
               res=max(res, m.second+mp[m.first+1];
       }
       return res;
        
    }
};

