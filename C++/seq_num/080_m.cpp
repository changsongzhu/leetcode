/**
80[M].Remove Duplicates from Sorted Array 2
 
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
**/

//Refined Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> m;
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                nums[index++]=nums[i];
                m[nums[i]]++;
            }
            else if(m[nums[i]]<2)
            {
                nums[index++]=nums[i];
                m[nums[i]]++;
            }
        }
        return index;
        
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int prev_val=nums[0];
        int duplicated=false;
        int index=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==prev_val&&duplicated==false)
            {
                nums[index++]=nums[i];
                duplicated=true;
            }
            else if(nums[i]==prev_val&&duplicated==true)
            {
                continue;
            }
            else
            {
                prev_val=nums[i];
                nums[index++]=nums[i];
                duplicated=false;
            }
        }
        return index;
        
    }
};
