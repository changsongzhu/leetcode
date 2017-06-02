/**
228[M]. Summary Ranges
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
**/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size()==0) return res;
        int left=nums[0], right=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==right+1)
            {
                right++;
            }
            else
            {
                if(left!=right)
                {
                    res.push_back(to_string(left) + "->" + to_string(right));
                }
                else
                {
                    res.push_back(to_string(left));
                }
                left=right=nums[i];
            }
        }
        if(left!=right) res.push_back(to_string(left) + "->" + to_string(right));
        else res.push_back(to_string(left));
        return res;
        
    }
};
