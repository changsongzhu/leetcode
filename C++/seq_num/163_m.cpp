/**
163[M][L]. Missing Ranges
Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]
**/
#include <stddef.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return {to_string(lower)+"->"+to_string(upper)};
        int start=lower;
        vector<string> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>start&&nums[i]<upper)
            {
                if(start+1==nums[i])
                {
                    res.push_back(to_string(start));
                }
                else
                {
                    res.push_back(to_string(start) +"->"+to_string(nums[i]-1));
                }
                start=nums[i]+1;
            }
            else if(nums[i]==start)
            {
               start=nums[i]+1;
            }
            else if(nums[i]==upper)
            {
               upper=upper-1;
            }
        }
        if(start==upper)
        {
            res.push_back(to_string(start));
        }
        else if(start<upper)
        {
            res.push_back(to_string(start)+"->"+to_string(upper));
        }
        return res;
   }
};

int main(void)
{
    vector<int> nums = {0, 1, 3, 50, 75, 99};
    Solution solution;
    vector<string> res=solution.findMissingRanges(nums, 0, 99);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i] << " ";
    } 
    cout<<endl;
    return 0;
}
