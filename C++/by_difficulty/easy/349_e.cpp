/**
349[E]. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
Each element in the result must be unique.
The result can be in any order.
**/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end());
        set<int> r;
        for(int i=0;i<nums2.size();i++)
        {
            if(s.find(nums2[i])!=s.end())r.insert(nums2[i]);
        }
        return vector<int>(r.begin(), r.end());
    }
};
