/**
506[E]. Relative Ranks
 
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
**/
//Set Solution
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        set<pair<int, int> > s;
        int n=nums.size();
        vector<string> res(n, "");
        for(int i=0;i<nums.size();i++)
        {
            s.insert({nums[i], i});
        }
        int i=0;
        for(auto a:s)
        {
           if(i==n-1)res[a.second]="Gold Medal";
           else if(i==n-2)res[a.second]="Silver Medal";
           else if(i==n-3)res[a.second]="Bronze Medal";
           else
               res[a.second]=to_string(n-i);
           i++;
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int size=nums.size();
        vector<string> res(size,"");
        map<int ,int> mp;
        for(int i=0;i<size;i++)
            mp[nums[i]]=i;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)res[mp[nums[size-1]]]="Gold Medal";
            else if(i==1)res[mp[nums[size-2]]]="Silver Medal";
            else if(i==2)res[mp[nums[size-3]]]="Bronze Medal";
            else res[mp[nums[size-1-i]]]=to_string(i+1);
        }
        return res;
    }
};
