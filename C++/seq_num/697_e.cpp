/**
697[E]. Degree of an array
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.


Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6


Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
**/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        map<int, vector<int> > m;
        int degree=0;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            degree=max(degree, freq[nums[i]]);
            if(m.count(nums[i])==0)m[nums[i]]={i};
            else m[nums[i]].push_back(i);
        }
        int res=nums.size();
        for(auto a:freq)
        {
            if(a.second==degree)
            {
                auto v=m[a.first];
                res=min(res, v[v.size()-1]-v[0]+1);
            }
        }
        return res;
        
    }
};

