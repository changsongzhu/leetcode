/**
228[M]. Summary Ranges
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
**/

//Start and End Solution
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return {};
        vector<string> res;
        int start=nums[0];
        int next=nums[0]+1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==next) {next++;continue;}
            else{
                (start==next-1)?res.push_back(to_string(start)): res.push_back(to_string(start)+"->"+to_string(next-1));
                start=nums[i];
                next=nums[i]+1;
            }
        }
        start==next-1?res.push_back(to_string(start)): res.push_back(to_string(start)+"->"+to_string(next-1));
        return res;
    }
};


//Refined Solution
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for(int i=0;i<nums.size();i++)
        {
            int j=i;
            while(j+1<nums.size()&&nums[j+1]==nums[j]+1)j++;
            if(j!=i)
            {
                res.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
                i=j;
            }
            else
            {
                res.push_back(to_string(nums[i]));
            }
        }
        return res;
    }
};


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
