/**
315[H]. Count of Smaller Numbers After Self
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
Example:
Given nums = [5, 2, 6, 1]
 
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
**/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<int> res(nums.size(), 0);
        int n=nums.size();
        int mn=INT_MAX;
        map<int, int> p;
        map<int, int> m;
        for(int i=nums.size()-1;i>=0;i--)
        {
            m[nums[i]]++;
            p[nums[i]]=i;
            if(nums[i]<=mn)
            {
                mn=nums[i];
                res[i]=0;
            }
            else
            {
                int j=nums[i]-1;
                for(;j>=mn;j--)
                {
                    if(p.count(j)) break;
                }
                res[i]=res[p[j]]+m[j];
                for(int k=p[j]-1;k>i;k--)
                {
                    if(nums[k]<nums[i]) res[i]++;
                }
            }
            
        }
        return res;
    }
};

